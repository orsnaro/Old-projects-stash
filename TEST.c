//this header belongs to ors simple calc :)
#include "includes.h"

int x=4;
int y=4;
void mat_avg( float A[x][y], float B[x][y], float C[x][y]);

int main()
{
float Z [x][y], W[x][y], K[x][y];
 mat_avg(Z, W, K);


return 0;
}























void mat_avg( float A[x][y], float B[x][y], float C[x][y])
{
int i,j;
x=4,y=4;
float mat_avg_value=0;
int A_row_num,A_colm_num,A_chk_row,A_chk_colm;
int B_row_num,B_colm_num,B_chk_row,B_chk_colm;

//starting with array 'A' SECTION:  making sure it filled and correctly.
do
{
      fflush(stdout);
      Sleep(500);
      printf("PLEASE! choose Matrix 'A' Rank (maximum 4x4)==>\n\n");

      printf(" \a 'A' rows=  ");
      A_chk_row =scanf("%d", &A_row_num);


     printf("  'A' columns=  ");
     A_chk_colm =scanf("%d", &A_colm_num);
      //restrictions for user input in following line
      if( A_chk_row!=1||A_chk_colm!=1||A_row_num>4 || A_row_num<0|| A_colm_num>4 || A_colm_num<0)
{
      printf("\n \a Failure!!---->  Your Matrix Rank is not accepted !!.");

      printf("\n \n -----PLEASE!----- re-input your values ==>\n\n");
}

      // we can add Sleep() here ! if we want but \a is good!.
     //restrictions for user input in following line
}while(  A_chk_row!=1||A_chk_colm!=1|| A_row_num>4 || A_row_num<0||  A_colm_num>4 || A_colm_num<0);

x= A_row_num, y= A_colm_num;

printf("\n\n\a\t\tSuccess!!---> Matrix 'A' set to rank = %ix%i ---> (A[%i][%i]). \n\n"
    ,A_row_num,A_colm_num,A_row_num,A_colm_num);

Sleep(500);
printf("\t\tPLEASE! fill Matrix 'A' to find it's average value --((input  values \"*ROW by ROW*\"))-- \n\n");
Sleep(500);
printf("\t\t----------------------------------START INPUT--------------------"
      "----------- \n");

for(i=0;i<x;i++)// 'i' is row counter and 'j' is coloumns counter.
{
for(j=0;j<y;j++)
{
printf("\n---> A[%d][%d]=",i,j)  ;
scanf("%f", &A[i][j]);
/*we  can add restriction input line here then if not true goto() previous step
(not really needed) */
}
}

      //show user's Matrix 'A' final value.
printf("\t\t------------------------------------OUTPUT------------------------------------ \n");
printf("\n (Arrray 'A')=\n" );
for(i=0;i<x;i++)
{
for(j=0;j<y;j++)
printf("%-.2f\t",A[i][j] );
printf("\n");
}
printf("------------------------------------------------------------------------------ \n");

for(i=0;i<x;i++)
{
for(j=0;j<y;j++)
mat_avg_value += A[i][j];
}
mat_avg_value/= x*y;
printf("\n\n\a\t\t SUCCESS!!---> (Matrix 'A') average value = %.2f\n",mat_avg_value);







/* --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
}




//stoped here ! 6-2-2021
