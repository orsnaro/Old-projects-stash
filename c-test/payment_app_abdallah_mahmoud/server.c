#define _CRT_SECURE_NO_WARNINGS
#include "server.h"
#include "card.h"
#include "terminal.h"

ST_accountsDB_t accountRefrence[255] = {
    {162000.0F, RUNNING, "5170770054625604"},
    {127000.0F, BLOCKED, "5170770054628566"},
    {191000.0F, RUNNING, "5170770054628061"},
    {1210000.0F, BLOCKED, "5170770054625323"},
    {1490000.0F, RUNNING, "5170770054625745"},
    {1780000.0F, RUNNING, "5170770054621355"},
    {163000.0F, BLOCKED, "5170770054623138"},
    {9000.0F, RUNNING, "5170770054626560"},
    {9000.0F, BLOCKED, "5170770054627436"},
    {1220000.0F, RUNNING, "5170770054625638"},
    {150000.0F, BLOCKED, "5170770054620720"},
    {1790000.0F, RUNNING, "5170770054625778"}};

ST_transaction_t transData[255] = {{0}};

ST_cardData_t *ptrtest = &cardData;
ST_terminalData_t *ptrtest2 = &termData;

int Z = -1;
int transcntr = 0;
int mx_trans = 255;

EN_transStat_t recieveTransactionData(ST_transaction_t *ptrtransData) {

  int handler_save = saveTransaction(ptrtransData);

  if (handler_save != 0) {
    puts("INTERNAL_SERVER_ERROR\n"); // either trans limit reached OR cant save
                                     // func failed;
    return INTERNAL_SERVER_ERROR;
  } else {

    if ((ptrtransData + transcntr)->transState != 0) {
      int overallHandler = (ptrtransData + transcntr)->transState;
      printf("DECLINED, code : %d \n", overallHandler);
      return (overallHandler);
    } else {
      printf("APPROVED\n");
      // getTransaction((ptrtransData + transcntr)->transactionSequenceNumber,
      //                (&transData)[0]);
      int tempstate = (ptrtransData + transcntr)->transState;
      float temp_amount = (ptrtransData + transcntr)->terminalData.transAmount;

      if (Z != -1 && (tempstate == 0)) {
        (accountRefrence + Z)->balance -= temp_amount;
        printf(
            "new balance for (%s) is : %0.2f \n\n \n ***********************\n",
            (accountRefrence + Z)->primaryAccountNumber,
            (accountRefrence + Z)->balance);
				printf(" prev. transaction seq.number: %d \n", (ptrtransData+transcntr)->transactionSequenceNumber);
      } 

      int overallHandler = (ptrtransData + transcntr)->transState;
      return (overallHandler);
    }

    ++transcntr;
  }
}

EN_serverError_t isValidAccount(ST_cardData_t *ptrcardHolderData) {
  Z = -1;
  uint8_t pan[20];
  strcpy(pan, ptrcardHolderData->CardPAN);
  for (int i = 0; i < mx_trans; i++) {
    if (!strcmp(pan, accountRefrence[i].primaryAccountNumber)) {
      Z = i;
      break;
    }
  }

  if (Z == -1) {
    printf("ACCOUNT_NOT_FOUND\n");
    return ACCOUNT_NOT_FOUND;
  } else {
    printf("SERVER_OK : valid account\n");
    return SERVER_OK;
  }
}

EN_serverError_t isBlockedAccount(ST_accountsDB_t *ptraccountRefrence) {
  if ((ptraccountRefrence + Z)->state != 0) {
    printf("BLOCKED_ACCOUNT\n");
    return BLOCKED_ACCOUNT;
  } else {
    printf("SERVER_OK : Running account\n");
    return SERVER_OK;
  }
}

EN_serverError_t isAmountAvailable(ST_terminalData_t *ptrterminalData) {
  float accbalance = accountRefrence[Z].balance;
  float reqamount = (ptrterminalData + transcntr)->transAmount;
  if (accbalance < reqamount) {
    printf("LOW_BALANCE\n");
    return LOW_BALANCE;
  } else {
    printf("SERVER_OK : amount valid\n");
    return SERVER_OK;
  }
}

EN_serverError_t saveTransaction(ST_transaction_t *ptrtransData) {

  if (transcntr == mx_trans) {
    puts("INTERNAL_SERVER_ERROR\n"); // either trans limit reached OR cant save
                                     // func failed;
    return SAVING_FAILED;
  }

  transData[transcntr].cardHolderData = cardData;
  transData[transcntr].terminalData = termData;

  int handler_isvalidacc =
      isValidAccount(&(transData[transcntr].cardHolderData));
  int handler_isblokdacc = isBlockedAccount((&accountRefrence)[0]);
  int handler_isamountav =
      isAmountAvailable(&(transData[transcntr].terminalData));

  if (handler_isvalidacc != 0)
    transData[transcntr].transState = DECLINED_STOLEN_CARD;
  else if (handler_isblokdacc != 0)
    transData[transcntr].transState = FRAUD_CARD;
  else if (handler_isamountav != 0)
    transData[transcntr].transState = DECLINED_INSUFFECIENT_FUND;
  else
    transData[transcntr].transState = APPROVED;

  if (transcntr + 1 == mx_trans)
    puts("WARNING! you can't make more transactions after this \n "
         "i.e.(max transaction limit reached)\n");

  //   (ptrtransData + transcntr)->transactionSequenceNumber = transcntr + 1;
  transData[transcntr].transactionSequenceNumber = transcntr + 1;
  puts("transaction saved\n");
  return SERVER_OK;
}

// will use this function to update balance for now.
// then add option in app.c either to view transaction or do new one.
EN_serverError_t getTransaction(uint32_t transactionSequenceNumber,
                                ST_transaction_t *ptrtransData) {
	int target=-1;
	for ( int i =0 ; i < mx_trans ; ++i){
		int tempseqnum=(ptrtransData+i)->transactionSequenceNumber;
		if( tempseqnum == transactionSequenceNumber){
			target = i;
			break;
		}
	}			
	
		printf("you requested transaction with seq.number: :\n %d \n",target+1);
  if ( target != -1 ) {
		printf(" Holder name : %s\n", (ptrtransData+target)->cardHolderData.CardHolderName);
		printf(" PAN num : %s \n", (ptrtransData+target)->cardHolderData.CardPAN);
		printf(" Card expiry date : %s\n", (ptrtransData+target)->cardHolderData.CardExpiryDate);
		printf(" Card transaction date : %s\n", (ptrtransData+target)->terminalData.transactionDate);
		printf(" Card transaction amount : %0.2f \n", (ptrtransData+target)->terminalData.transAmount);
		printf(" Card Max amount : %0.2f\n", (ptrtransData+target)->terminalData.maxTransAmount);
		printf("trans state code:%d \n hint(0 = APPROVED transaction)\n\n***********************\n", (ptrtransData+target)->transState);
		
    return SERVER_OK;
  } else{
		printf("TRANSACTION_NOT_FOUND\n");
    return TRANSACTION_NOT_FOUND;
	}
}
