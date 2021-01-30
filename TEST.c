#include <stdio.h>
#include <math.h>
#include <string.h>
//we can add "windows.h" header if we want to use Sleep(ms) 'captial S'.
 int x=4,y=4 ; //global
 float mat_add( float A[x][y], float B[x][y],float C[x][y]);

 int main()
 {
   static float Z[4][4],W[4][4],K[4][4];

  mat_add( Z , W, K) ;

  return 0;}

  float mat_add( float A[4][4], float B[4][4], float C[4][4])
{
int i,j;
x=4,y=4;

  int A_row_num,A_colm_num,A_chk_row,A_chk_colm;
  int B_row_num,B_colm_num,B_chk_row,B_chk_colm;

do //this do is to make sure that array 'A' and 'B' can be added\subtractdd.
{
//starting with array 'A' SECTION:  making sure it filled and correctly.
do
{
        fflush(stdout);
        sleep(1);
        printf("PLEASE! choose Array 'A' Rank (maximum 4x4)==>\n\n");

        printf(" \a 'A' rows=  ");
        A_chk_row =scanf("%d", &A_row_num);


       printf("  'A' columns=  ");
       A_chk_colm =scanf("%d", &A_colm_num);
        //restrictions for user input in following line
        if( A_chk_row!=1||A_chk_colm!=1||A_row_num>4 || A_row_num<0|| A_colm_num>4 || A_colm_num<0)
{
        printf("\n \a Failure!!---->  Your Array Rank is not accepted !!.");

        printf("\n \n -----PLEASE!----- re-input your values ==>\n\n");
}

        // we can add sleep() here ! if we want but \a is good!.
       //restrictions for user input in following line
}while(  A_chk_row!=1||A_chk_colm!=1|| A_row_num>4 || A_row_num<0||  A_colm_num>4 || A_colm_num<0);

x= A_row_num, y= A_colm_num;

printf("\n\n\a\t\tSuccess!!---> Array 'A' set to rank = %ix%i ---> (A[%i][%i]). \n\n"
      ,A_row_num,A_colm_num,A_row_num,A_colm_num);

sleep(0.5);
printf("\t\tPLEASE! fill Array 'A' --(input  values \"row by row\")-- \n\n");
sleep(0.5);
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

        //show user's Array 'A' final value.
printf("\t\t------------------------------------OUTPUT------------------------------------ \n");
printf("\n (Arrray 'A')=\n" );
for(i=0;i<x;i++)
{
  for(j=0;j<y;j++)
  printf("%-.2f\t",A[i][j] );
  printf("\n");
}
printf("\t\t------------------------------------------------------------------------------ \n");

      // Array 'B' SECTION: making sure it filled and correctly.
     // i stoped here !!
printf("\t\t\a***** REMEMBER!! arrays  must have same Rows & columns to"
       "  Add/subtract them *****\n\n ");
       sleep(1);
do
{
        fflush(stdout);
        sleep(1);
        printf("PLEASE! choose Array 'B' Rank (maximum 4x4)==>\n\n");

        printf(" \a 'B' rows=  ");
        B_chk_row =scanf("%d", &B_row_num);


       printf("  'B' columns=  ");
       A_chk_colm =scanf("%d", &B_colm_num);
        //restrictions for user input in following line
        if( B_chk_row!=1||B_chk_colm!=1||B_row_num>4 || B_row_num<0|| B_colm_num>4 || B_colm_num<0)
{
        printf("\n \a Failure!!---->  Your Array Rank is not accepted !!.");

        printf("\n \n -----PLEASE!----- re-input your values ==>\n\n");
}

        // we can add sleep() here ! if we want but \a is good!.
       //restrictions for user input in following line
}while(  B_chk_row!=1||B_chk_colm!=1|| B_row_num>4 || B_row_num<0||  B_colm_num>4 || B_colm_num<0);

x= B_row_num, y= B_colm_num;

printf("\n\n\a\t\tSuccess!!---> Array 'B' set to rank = %ix%i ---> (B[%i][%i]). \n\n"
,B_row_num,B_colm_num,B_row_num,B_colm_num);

sleep(0.5);
printf("\t\tPLEASE! fill Array 'B' --(input  values \"row by row\")-- \n\n");
sleep(0.5);
 printf("\t\t----------------------------------START INPUT--------------------"
 "----------- \n");

for(i=0;i<x;i++)// 'i' is row counter and 'j' is coloumns counter.
{
  for(j=0;j<y;j++)
{
  printf("\n---> B[%d][%d]=",i,j)  ;
  scanf("%f", &B[i][j]);
  /*we  can add restriction input line here then if not true goto() previous step
  (not really needed) */
}

}

//show user's Array 'A' final value.
printf("\t\t------------------------------------OUTPUT------------------------------------ \n");
printf("\n (Arrray 'B')=\n" );
for(i=0;i<x;i++)
{
  for(j=0;j<y;j++)
  printf("%-.2f\t",B[i][j] );
  printf("\n");
}

  if( A_row_num!= B_row_num || A_colm_num!=B_colm_num)
  printf("\t\tOOPS !!!! ***** your arrays 'A & B' does not have same coloumns & rows number \n"
        "\t\t\t\t*****please RETRY!! **** \n ");

}while(A_row_num!=B_row_num || A_colm_num!=B_colm_num); //this do-while loop is to make sure that array 'A' and 'B' can be added\subtractdd.

printf("\t\t------------------------------------------------------------------------------ \n");
printf("\n\n\a\t\tSuccess!!---> A+B=C\n\n (Array 'C')=\n";

C=A+B;
for(i=0;i<x;i++)
{
  for(j=0;j<y;j++)
  printf("%-.2f\t",C[i][j] );
  printf("\n");
}



// i stoped here !!

return 0;}
