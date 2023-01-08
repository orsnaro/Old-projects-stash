// #include <bits/stdc++.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>


typedef enum EN_accountState_t { RUNNING, BLOCKED } EN_accountState_t;

typedef struct ST_accountsDB_t {
  float balance;
  EN_accountState_t state;
  uint8_t primaryAccountNumber[20];
} ST_accountsDB_t;

ST_accountsDB_t accountRefrence[255] = {{{0}}};


int main() {

  int x = sizeof(accountRefrence); // total size TOTAL

  printf("%d\n", x);
   
  getch();
  return 0;
}
