#define _CRT_SECURE_NO_WARNINGS
#include "card.h"

 ST_cardData_t cardData;


// get card holder name
EN_Card_Error_t getCardHolderName(ST_cardData_t *ptrcardData) {
  printf("please enter your name: \nplease no spaces use *_* \n==> ");
  
//   fflush(stdin);
  uint8_t dummy[25] ={0};
  strcpy(ptrcardData->CardHolderName ,dummy);

  scanf( "%24s" ,&(ptrcardData->CardHolderName));

  int length = strlen(ptrcardData->CardHolderName);
  if (length > 20 && length < 24) {
    printf(" OK\n");
    return OK;
  } else {
    printf(" Wrong_Name\n");
    return Wrong_Name;
  }
}
// get card Expiry date
EN_Card_Error_t getCardExpiryDate(ST_cardData_t *ptrcardData) {
  uint8_t dummy[6] ={0};
  strcpy(ptrcardData->CardExpiryDate ,dummy);
  
  printf("please enter card expiry date MM YY : \n==> ");

  char M[5];
  scanf("%4s", &M);

  if (M[0] == '0' || M[0] == '1') {
    if ((M[0] == '1' && (M[1] >= '0' && M[1] <= '2')) ||
        (M[0] == '0' && (M[1] >= '1' && M[1] <= '9'))) {
      strcat(ptrcardData->CardExpiryDate, M);
      strcat(ptrcardData->CardExpiryDate, "/");

    } else {
      printf(" Wrong_Exp_Date\n");
      return Wrong_Exp_Date;
    }
  } else {
    printf(" Wrong_Exp_Date\n");
    return Wrong_Exp_Date;
  }

  char Y[5];
  scanf("%4s", &Y);

  int inty = atoi(Y);
  if (inty >= 22 && inty <= 30) {
    strcat(ptrcardData->CardExpiryDate, Y);
    printf(" OK\n");
    return OK;
  } else {
    printf(" Wrong_Exp_Date\n");
    return Wrong_Exp_Date;
  }
}

// get card PAN
EN_Card_Error_t getCardPAN(ST_cardData_t *ptrcardData) {
  printf("please enter Card PAN : \n==> ");
  scanf("%19s", &(ptrcardData->CardPAN));
  // strcat(ptrcardData->CardPAN,'\0');

  int panlength = strlen(ptrcardData->CardPAN);
  if (panlength >= 16 && panlength <= 19) {
    printf(" OK\n");
    return OK;
  } else {
    printf(" Wrong_PAN\n");
    return Wrong_PAN;
  }
}