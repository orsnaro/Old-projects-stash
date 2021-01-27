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

  int row_num,colm_num,chk_row,chk_colm;

//starting with array 'A' making sure it filled and correctly.
do
{
        fflush(stdout);
        sleep(1);
        printf("PLEASE! choose Array 'A' Rank (maximum 4x4)==>\n\n");

        printf(" \a 'A' rows=  ");
        chk_row =scanf("%d", &row_num);


       printf("  'A' columns=  ");
       chk_colm =scanf("%d", &colm_num);
        //restrictions for user input in following line
        if( chk_row!=1||chk_colm!=1||row_num>4 || row_num<0|| colm_num>4 || colm_num<0)
{
        printf("\n \a Failure!!---->  Your Array Rank is not accepted !!.");

        printf("\n \n -----PLEASE!----- re-input your values ==>\n\n");
}

        // we can add sleep() here ! if we want but \a is good!.
       //restrictions for user input in following line
}while(  chk_row!=1||chk_colm!=1|| row_num>4 || row_num<0||  colm_num>4 || colm_num<0);

x= row_num, y= colm_num;

printf("\n\n\a\t\tSuccess!!---> Array 'A' set to rank = %ix%i ---> (A[%i][%i]). \n\n"
      ,row_num,colm_num,row_num,colm_num);

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

      // Array 'B' making sure it filled and correctly.
     // i stoped here !!
printf("\t\t\a***** REMEMBER!! arrays  must be in same Rank (Rows*columns) to"
       " do Add/subtract them*****\n\n ");
       sleep(1);
{
        fflush(stdout);
        sleep(1);
        printf("PLEASE! choose Array 'B' Rank (maximum 4x4)==>\n\n");

        printf(" \a 'B' rows=  ");
        chk_row =scanf("%d", &row_num);


       printf("  'B' columns=  ");
       chk_colm =scanf("%d", &colm_num);
        //restrictions for user input in following line
        if( chk_row!=1||chk_colm!=1||row_num>4 || row_num<0|| colm_num>4 || colm_num<0)
{
        printf("\n \a Failure!!---->  Your Array Rank is not accepted !!.");

        printf("\n \n -----PLEASE!----- re-input your values ==>\n\n");
}

        // we can add sleep() here ! if we want but \a is good!.
       //restrictions for user input in following line
}while(  chk_row!=1||chk_colm!=1|| row_num>4 || row_num<0||  colm_num>4 || colm_num<0);

x= row_num, y= colm_num;

printf("\n\n\a\t\tSuccess!!---> Array 'B' set to rank = %ix%i ---> (B[%i][%i]). \n\n"
,row_num,colm_num,row_num,colm_num);

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

 //next line will check if array 'A' and array 'B' are in same rank before addtion then we write addtion code

// i stoped here !!

return 0;}
