#define _CRT_SECURE_NO_WARNINGS
#include "terminal.h"
#include "card.h"

 ST_terminalData_t termData;


EN_terminalError_t getTransactionDate(ST_terminalData_t *ptrtermData) {
  uint8_t dummy[11] ={0};
  strcpy(ptrtermData->transactionDate ,dummy);

  int temparr[11] = {0};
  temparr[0] = sysDay();
  temparr[1] = sysMonth();
  temparr[2] = sysYear();

  char buffer[11];
  for (int i = 0; i < 3; ++i) {
    if (temparr[i] < 10) {
      strcat(ptrtermData->transactionDate, "0");
      strcat(ptrtermData->transactionDate, _itoa(temparr[i], buffer, 10));
    } else
      strcat(ptrtermData->transactionDate, _itoa(temparr[i], buffer, 10));

    if (i == 2)
      continue;
    strcat(ptrtermData->transactionDate, "/");
  }

  printf(" Transaction date is : \n %s \n", ptrtermData->transactionDate);
  return Ok;
}

EN_terminalError_t isCardExpired(ST_cardData_t *ptrcardData,
                                 ST_terminalData_t *ptrtermData) {
  static char tempexp[100];
  static char temptrans[100];
  strcpy(tempexp, ptrcardData->CardExpiryDate);
  strcpy(temptrans, ptrtermData->transactionDate);

  if (atoi(temptrans + 8) > atoi(tempexp + 3)) { // comp year
    printf(" EXPIRED_CARD\n");
    return EXPIRED_CARD;
  } else {
    if (atoi(temptrans + 8) < atoi(tempexp + 3)) { // comp year
      printf(" Ok, Card expiry Date  is Valid \n");
      return Ok;
    } else {
      if (atoi(temptrans + 3) > atoi(tempexp)) { // comp month
        printf(" EXPIRED_CARD\n");
        return EXPIRED_CARD;
      } else {
        printf(" Ok, Card expiry Date  is Valid\n");
        return Ok;
      }
    }
  }
}

EN_terminalError_t setMaxAmount(ST_terminalData_t *ptrtermData) {

  ptrtermData->maxTransAmount = (float)10000.00;

  if (ptrtermData->maxTransAmount <= (float)0) // almost useless
    return INVALID_MAX_AMOUNT;
  else {
    printf(" max tarnsaction amount is set to 10000.00$\n");
    return Ok;
  }
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t *ptrtermData) {

  float dummy = (float)0;
  ptrtermData->transAmount=dummy;

  printf("please enter the transaction amount : \n==> ");
  scanf("%f", &(ptrtermData->transAmount));

  if (ptrtermData->transAmount <= (float)0) {
    printf(" INVALID_AMOUNT\n");
    return INVALID_AMOUNT;
  } else {
    return Ok;
  }
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *ptrtermData) {
  if (ptrtermData->transAmount > ptrtermData->maxTransAmount) {
    printf(" EXCEED MAX AMOUNT\n");
    return EXCEED_MAX_AMOUNT;
  } else {
    printf(" %0.2f is valid amount \n", ptrtermData->transAmount);
    return Ok;
  }
}

// additional funcitons that I need
int sysYear(void) {
  time_t t;
  time(&t);

  char year[5];
  for (int i = 0; i < 4; ++i)
    year[i] = ctime(&t)[i + 20];

  year[4] = '\0';
  int ytoint = atoi(year);

  return ytoint;
}

int sysMonth(void) {
  time_t t;
  time(&t);

  char month[4];
  for (int i = 0; i < 3; ++i)
    month[i] = ctime(&t)[i + 4];

  month[3] = '\0';
  int mtoint = 0;

  if (!strcmp(month, "Jan")) {
    mtoint = 1;
  } else if (!strcmp(month, "Feb")) {
    mtoint = 2;
  } else if (!strcmp(month, "Mar")) {
    mtoint = 3;
  } else if (!strcmp(month, "Apr")) {
    mtoint = 4;
  } else if (!strcmp(month, "May")) {
    mtoint = 5;

  } else if (!strcmp(month, "Jun")) {
    mtoint = 6;

  } else if (!strcmp(month, "Jul")) {
    mtoint = 7;

  } else if (!strcmp(month, "Aug")) {
    mtoint = 8;

  } else if (!strcmp(month, "Sep")) {
    mtoint = 9;

  } else if (!strcmp(month, "Oct")) {
    mtoint = 10;

  } else if (!strcmp(month, "Nov")) {
    mtoint = 11;

  } else if (!strcmp(month, "Dec")) {
    mtoint = 12;
  } else
    mtoint = 0;

  return mtoint;
}

int sysDay(void) {
  time_t t;
  time(&t);

  char day[3];
  for (int i = 0; i < 2; ++i)
    day[i] = ctime(&t)[i + 8];

  day[2] = '\0';
  int dtoint = atoi(day);

  return dtoint;
}