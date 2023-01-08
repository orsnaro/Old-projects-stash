#define _CRT_SECURE_NO_WARNINGS
#include "app.h"
#include "card.h"
#include "server.h"
#include "terminal.h"

int main() {

  short int closeapp = -1;
  while (closeapp != 2) {
    printf("Do you want to make  transaction or view old transaction?"
           "\n 0)make new trans. \n 1)view old trans. \n 2)exit \n==>");
    scanf("%hd", &closeapp);
	 if(closeapp == 0)
    	appStart();
	 else if(closeapp == 1){
		uint32_t dummy_transnum;
		printf("please enter transaction seq.num: \n==> ");
		scanf("%d", &dummy_transnum);
		getTransaction(dummy_transnum,(&transData)[0]);

	 }

  }

  return 0;
}

void appStart(void) {

  /*CARD*/
  if (getCardHolderName(&cardData) != 0)
    return;
  if (getCardExpiryDate(&cardData) != 0)
    return;
  if (getCardPAN(&cardData) != 0)
    return;

  /*TERMINAL*/
  getTransactionDate(&termData);
  if (isCardExpired(&cardData, &termData) != 0)
    return;
  // if(isValidCardPAN(&cardData) != 0)
  //   exit(EXIT_FAILURE);

  if (setMaxAmount(&termData) != 0)
    return;
  if (getTransactionAmount(&termData) != 0)
    return;
  if (isBelowMaxAmount(&termData) != 0)
    return;

  /*SERVER*/
  int recieve_err_holder = recieveTransactionData((&transData)[0]);
  if (recieve_err_holder != 0) {
    if (recieve_err_holder == INTERNAL_SERVER_ERROR) {
      puts("CRITICAL ERROR all data/transaction changes will be reversed\n");
      puts("(PLEASE PRESS ANY KEY...)\n");
      getch();
      exit(EXIT_FAILURE);
    }
  }

  return;
}