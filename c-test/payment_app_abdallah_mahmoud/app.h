#ifndef APP_H
#define APP_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "server.h"

extern ST_cardData_t cardData;
extern ST_terminalData_t termData;
extern ST_transaction_t transData[255];

extern ST_accountsDB_t accountRefrence[255];
void appStart(void);



#endif