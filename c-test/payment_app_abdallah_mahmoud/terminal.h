#ifndef TERMINAL_H
#define TERMINAL_H
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
 #include "card.h"

typedef struct ST_terminalData_t {
  float transAmount;
  float maxTransAmount;
  uint8_t transactionDate[11];
} ST_terminalData_t;

typedef enum EN_terminalError_t {
  Ok,
  WRONG_DATE,
  EXPIRED_CARD,
  INVALID_CARD,
  INVALID_AMOUNT,
  EXCEED_MAX_AMOUNT,
  INVALID_MAX_AMOUNT
} EN_terminalError_t;

EN_terminalError_t getTransactionDate(ST_terminalData_t *ptrtermData);
EN_terminalError_t isCardExpired(ST_cardData_t *ptrcardData,
                                 ST_terminalData_t *ptrtermData);
EN_terminalError_t isValidCardPAN(ST_cardData_t *ptrcardData);
EN_terminalError_t setMaxAmount(ST_terminalData_t *ptrtermData);
EN_terminalError_t getTransactionAmount(ST_terminalData_t *ptrtermData);
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *ptrtermData);

// additional fucntions that I need
int sysYear(void);
int sysMonth(void);
int sysDay(void);

#endif