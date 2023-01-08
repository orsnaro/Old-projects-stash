#ifndef CARD_H
#define CARD_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


typedef struct ST_cardData_t {
  uint8_t CardHolderName[25];
  uint8_t CardExpiryDate[6];
  uint8_t CardPAN[20];
} ST_cardData_t;


typedef enum EN_Card_Error_t {
  OK,
  Wrong_Name,
  Wrong_Exp_Date,
  Wrong_PAN
} EN_Card_Error_t;

EN_Card_Error_t getCardHolderName(ST_cardData_t *ptrcardData);
EN_Card_Error_t getCardExpiryDate(ST_cardData_t *ptrcardData);
EN_Card_Error_t getCardPAN(ST_cardData_t *ptrcardData);

#endif