#ifndef SERVER_H
#define SERVER_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include "terminal.h"
typedef enum EN_transState_t {
  APPROVED,
  DECLINED_INSUFFECIENT_FUND,
  DECLINED_STOLEN_CARD,
  FRAUD_CARD,
  INTERNAL_SERVER_ERROR
} EN_transStat_t;

typedef enum EN_serverError_t {
  SERVER_OK,
  SAVING_FAILED,
  TRANSACTION_NOT_FOUND,
  ACCOUNT_NOT_FOUND,
  LOW_BALANCE,
  BLOCKED_ACCOUNT
} EN_serverError_t;

typedef enum EN_accountState_t { RUNNING, BLOCKED } EN_accountState_t;

typedef struct ST_transaction_t {
  ST_cardData_t cardHolderData;
  ST_terminalData_t terminalData;
  EN_transStat_t transState;
  uint32_t transactionSequenceNumber;
} ST_transaction_t;

typedef struct ST_accountsDB_t {
  float balance;
  EN_accountState_t state;
  uint8_t primaryAccountNumber[20];
} ST_accountsDB_t;


extern ST_cardData_t cardData;
extern ST_terminalData_t termData;


// ST_accountsDB_t *ptrrefrence[255] = accountRefrence;
// ST_transaction_t *ptrDATATRANS [255]= transData;

EN_transStat_t recieveTransactionData(ST_transaction_t *ptrtransData);
EN_serverError_t isValidAccount(ST_cardData_t *ptrcardHolderData);
EN_serverError_t isBlockedAccount(ST_accountsDB_t *ptraccountRefrence);
EN_serverError_t isAmountAvailable(ST_terminalData_t *ptrterminalData);
EN_serverError_t saveTransaction(ST_transaction_t *ptrtransData);
EN_serverError_t getTransaction(uint32_t transactionSequenceNumber,
                                ST_transaction_t *ptrtransData);
#endif 