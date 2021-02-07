//this header belongs to ors simple calc :)
#include "includes.h"

static int A_row_num,A_colm_num,B_row_num,B_colm_num;
 int x,y;

void mat_add( float A[x][y], float B[x][y],float C[x][y]);
void mat_sub( float A[x][y], float B[x][y],float C[x][y]);
void mat_multiply( float A[x][y], float B[x][y],float C[x][y]);

x=4;
y=4;
float matrix_operations(float A[x][y], float B[x][y],float C[x][y])
{
    static char  mat_mnu_slct ;
    static float average_value ;
    float Z[x][y],W[x][y],K[x][y];
    static char func_return,ch;
    //MAIN menu
    fflush(stdout);
        printf("\n \n ---------------------------------------------------------------------\n");
        printf("\n \n //\n ---------------->\t WELCOME! THIS is MATRIX SECTION \t<--------------. \n \t\t //Please Select your option: \v\v \n");
        printf("\n \n //\n press \"a\" if you want to Add Matrices . \n");
        printf("press \"b\" if you want to Subtract Matrices . \n");
        printf("press \"c\" if you want to Multiply Matrices . \n");
        printf("press \"d\" if you want to find the average value of an Array  . \n");
        printf("press \"e\" if you want to sort your Matrix\n\n");
        printf("press \"f\" to INCLUDE last result in a new operation\n\n");
        printf("PLEASE! choose  ==> \n ");
        ch= getchar();
        mat_mnu_slct=ch;




switch(mat_mnu_slct)
{
        case'a':
{

  mat_add( Z , W, K) ;
}
break;

        case'b':
{

  mat_sub( Z , W, K) ;
}
break;

       case'c':
{

  mat_multiply( Z , W, K) ;

}
break;

        case'd':
{

}
break;

        case'e':
{

}
break;

        case'f':
{

}
break;

        default: ;
{

}
}


}














                 // --------------------functions body--------------------





// 1) MATRICES Addtion**************************************************************

void mat_add( float A[x][y], float B[x][y], float C[x][y])
{
int i,j;
x=4,y=4;

int A_row_num,A_colm_num,A_chk_row,A_chk_colm;
int B_row_num,B_colm_num,B_chk_row,B_chk_colm;

do //this do is to make sure that Matrix 'A' and 'B' can be added\subtractdd.
{
//starting with array 'A' SECTION:  making sure it filled and correctly.
do
{
      fflush(stdout);
      Sleep(1000);
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
printf("\t\tPLEASE! fill Matrix 'A' --(input  values \"row by row\")-- \n\n");
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


/* --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


    // Matrix 'B' SECTION: making sure it filled and correctly.


printf("\t\t\a***** REMEMBER!! Matrices  must have same Rows & columns to"
     "  Add/subtract them *****\n\n ");
     Sleep(1000);
do
{
      fflush(stdout);
      Sleep(1000);
      printf("PLEASE! choose Matrix 'B' Rank (maximum 4x4)==>\n\n");

      printf(" \a 'B' rows=  ");
      B_chk_row =scanf("%d", &B_row_num);


     printf("  'B' columns=  ");
     B_chk_colm =scanf("%d", &B_colm_num);
      //restrictions for user input in following line
      if( B_chk_row!=1||B_chk_colm!=1||B_row_num>4 || B_row_num<0|| B_colm_num>4 || B_colm_num<0)
{
      printf("\n \a Failure!!---->  Your Matrix Rank is not accepted !!.");

      printf("\n \n -----PLEASE!----- re-input your values ==>\n\n");
}

      // we can add Sleep() here ! if we want but \a is good!.
     //restrictions for user input in following line
}while(  B_chk_row!=1||B_chk_colm!=1|| B_row_num>4 || B_row_num<0||  B_colm_num>4 || B_colm_num<0);

x= B_row_num, y= B_colm_num;

printf("\n\n\a\t\tSuccess!!---> Matrix 'B' set to rank = %ix%i ---> (B[%i][%i]). \n\n"
,B_row_num,B_colm_num,B_row_num,B_colm_num);

Sleep(500);
printf("\t\tPLEASE! fill Matrix 'B' --(input  values \"row by row\")-- \n\n");
Sleep(500);
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

//show user's Matrix 'B' final value.
printf("\t\t------------------------------------OUTPUT------------------------------------ \n");
printf("\n (Arrray 'B')=\n" );
for(i=0;i<x;i++)
{
for(j=0;j<y;j++)
printf("%-.2f\t",B[i][j] );
printf("\n");
}

if( A_row_num!= B_row_num || A_colm_num!=B_colm_num)
      printf("\t\tOOPS !!!! ***** your Matrices 'A & B' does not have same coloumns & rows number \n\n"
             "\t\t\t\t\t\t\t*****please RETRY!! **** \n\n ");
      printf("------------------------------------------------------------------------------ \n");

}while(A_row_num!=B_row_num || A_colm_num!=B_colm_num); //this do-while loop is to make sure that array 'A' and 'B' can be added\subtractdd.






/* --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


    // Matrix 'C' (result) SECTION:



printf("------------------------------------------------------------------------------ \n");

for(i=0;i<x;i++)
{
for(j=0;j<y;j++)
C[i][j]=A[i][j]+B[i][j];
}

printf("\n\n\a\t\tSuccess!!---> A+B=C\n\n (Matrix 'C')=\n");

for(i=0;i<x;i++)
{
for(j=0;j<y;j++)
printf("%-.2f\t",C[i][j] );
printf("\n");
}

}





















// 2) MATRICES Subtraction**************************************************************

void mat_sub( float A[x][y], float B[x][y], float C[x][y])
{
int i,j;
x=4,y=4;

int A_row_num,A_colm_num,A_chk_row,A_chk_colm;
int B_row_num,B_colm_num,B_chk_row,B_chk_colm;

do //this do is to make sure that Matrix 'A' and 'B' can be added\subtractdd.
{
//starting with array 'A' SECTION:  making sure it filled and correctly.
do
{
      fflush(stdout);
      Sleep(1000);
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
printf("\t\tPLEASE! fill Matrix 'A' --(input  values \"row by row\")-- \n\n");
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


/* --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


    // Matrix 'B' SECTION: making sure it filled and correctly.


printf("\t\t\a***** REMEMBER!! Matrices  must have same Rows & columns to"
     "  Add/subtract them *****\n\n ");
     Sleep(1000);
do
{
      fflush(stdout);
      Sleep(1000);
      printf("PLEASE! choose Matrix 'B' Rank (maximum 4x4)==>\n\n");

      printf(" \a 'B' rows=  ");
      B_chk_row =scanf("%d", &B_row_num);


     printf("  'B' columns=  ");
     B_chk_colm =scanf("%d", &B_colm_num);
      //restrictions for user input in following line
      if( B_chk_row!=1||B_chk_colm!=1||B_row_num>4 || B_row_num<0|| B_colm_num>4 || B_colm_num<0)
{
      printf("\n \a Failure!!---->  Your Matrix Rank is not accepted !!.");

      printf("\n \n -----PLEASE!----- re-input your values ==>\n\n");
}

      // we can add Sleep() here ! if we want but \a is good!.
     //restrictions for user input in following line
}while(  B_chk_row!=1||B_chk_colm!=1|| B_row_num>4 || B_row_num<0||  B_colm_num>4 || B_colm_num<0);

x= B_row_num, y= B_colm_num;

printf("\n\n\a\t\tSuccess!!---> Matrix 'B' set to rank = %ix%i ---> (B[%i][%i]). \n\n"
,B_row_num,B_colm_num,B_row_num,B_colm_num);

Sleep(500);
printf("\t\tPLEASE! fill Matrix 'B' --(input  values \"row by row\")-- \n\n");
Sleep(500);
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

//show user's Matrix 'B' final value.
printf("\t\t------------------------------------OUTPUT------------------------------------ \n");
printf("\n (Arrray 'B')=\n" );
for(i=0;i<x;i++)
{
for(j=0;j<y;j++)
printf("%-.2f\t",B[i][j] );
printf("\n");
}

if( A_row_num!= B_row_num || A_colm_num!=B_colm_num)
      printf("\t\tOOPS !!!! ***** your Matrices 'A & B' does not have same coloumns & rows number \n\n"
             "\t\t\t\t\t\t\t*****please RETRY!! **** \n\n ");
      printf("------------------------------------------------------------------------------ \n");

}while(A_row_num!=B_row_num || A_colm_num!=B_colm_num); //this do-while loop is to make sure that array 'A' and 'B' can be added\subtractdd.




/* --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


    // Matrix 'C' (result) SECTION:.

printf("------------------------------------------------------------------------------ \n");

for(i=0;i<x;i++)
{
for(j=0;j<y;j++)
C[i][j]=A[i][j]-B[i][j];
}

printf("\n\n\a\t\tSuccess!!---> A-B=C\n\n (Matrix 'C')=\n");

for(i=0;i<x;i++)
{
for(j=0;j<y;j++)
printf("%-.2f\t",C[i][j] );
printf("\n");
}

}



















// 3) MATRICES Multiplication**************************************************************


void mat_multiply( float A[x][y], float B[x][y], float C[A_row_num][B_colm_num])
{

 static int A_chk_row,A_chk_colm,B_chk_row,B_chk_colm;
 int i,j,k,l;
 x=4,y=4;

 do //this do is to make sure that Matrix 'A' and 'B' can be Multiplied.
 {

 //starting with array 'A' SECTION:  making sure it filled and correctly.
 do
 {
       fflush(stdout);
       Sleep(1000);
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
 printf("\t\tPLEASE! fill Matrix 'A' --(input  values \"row by row\")-- \n\n");
 Sleep(500);
 printf("\t\t----------------------------------START INPUT--------------------"
       "----------- \n");

 for(i=0;i<x;i++)// 'i' is row counter and 'j' is coloumns counter.
 {
 for(j=0;j<y;j++)
 {
 printf("\n---> A[%d][%d]=",i,j)  ;
 scanf("%f", &A[i][j]);
 /*we  can add restriction input line here then if not true goto() any previous step
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


 /* --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


     // Matrix 'B' SECTION: making sure it filled and correctly.


 printf("\t\a***** REMEMBER!! no. of 'A' COLOUMNS must be equal to no. of 'B' ROWS to "
      "  Mulyiply Successfully *****\n\n ");
      Sleep(1000);
 do
 {
       fflush(stdout);
       Sleep(1000);
       printf("PLEASE! choose Matrix 'B' Rank (maximum 4x4)==>\n\n");

       printf(" \a 'B' rows=  ");
       B_chk_row =scanf("%d", &B_row_num);


      printf("  'B' columns=  ");
      B_chk_colm =scanf("%d", &B_colm_num);
       //restrictions for user input in following line
       if( B_chk_row!=1||B_chk_colm!=1||B_row_num>4 || B_row_num<0|| B_colm_num>4 || B_colm_num<0)
 {
       printf("\n \a Failure!!---->  Your Matrix Rank is not accepted !!.");

       printf("\n \n -----PLEASE!----- re-input your values ==>\n\n");
 }

       // we can add Sleep() here ! if we want but \a is good!.
      //restrictions for user input in following line
 }while(  B_chk_row!=1||B_chk_colm!=1|| B_row_num>4 || B_row_num<0||  B_colm_num>4 || B_colm_num<0);

 x= B_row_num, y= B_colm_num;

 printf("\n\n\a\t\tSuccess!!---> Matrix 'B' set to rank = %ix%i ---> (B[%i][%i]). \n\n"
 ,B_row_num,B_colm_num,B_row_num,B_colm_num);

 Sleep(500);
 printf("\t\tPLEASE! fill Matrix 'B' --(input  values \"row by row\")-- \n\n");
 Sleep(500);
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

 //show user's Matrix 'B' final value.
 printf("\t\t------------------------------------OUTPUT------------------------------------ \n");
 printf("\n (Arrray 'B')=\n" );
 for(i=0;i<x;i++)
 {
 for(j=0;j<y;j++)
 printf("%-.2f\t",B[i][j] );
 printf("\n");
 }

 if( A_colm_num!=B_row_num)
       printf("\t\tOOPS !!!! ***** your Matrices 'A & B' can't be Multiplied ! \n\n"
              "\t\t\t\t\t\t\t***** please RETRY!! **** \n\n ");
       printf("------------------------------------------------------------------------------ \n");

 }while( A_colm_num!=B_row_num); //this do-while loop is to make sure that array 'A' and 'B' can be Multiplied.




 /* --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
     // Matrix 'C' (result array) SECTION:

 printf("------------------------------------------------------------------------------ \n");
 printf("\n\n\a\t\t Matrix 'C'  rank set to = %ix%i  \n\n  \n", A_row_num,B_colm_num);
 //here we will input column by column  (NOT as USUALL => row by row).
//breaking each element in array 'C'  into 4 parts maximum.

for(j=0,l=0; j<B_colm_num || l<B_colm_num; j++,l++) //move between array 'C' columns by 'j'.
{
 k=0;
 for(i=0,k=0; i<A_row_num || k<A_row_num; i++,k++)  //move between array 'C' rows by 'i'.
 {
  C[i][j]= (A[k][0]) * (B[0][l]); // 1st part of array 'C' elements.
  if (A_row_num!=1)
  {
    C[i][j]+= (A[k][1]) * (B[1][l]); // 2nd part of array 'C' elements.
  }
  else if (A_row_num!=2)
  {
    C[i][j]+= (A[k][2]) * (B[2][l]); // 3rd part of array 'C' elements.
  }
  else if (A_row_num!=3)
  {
    C[i][j]+= (A[k][3]) * (B[3][l]); // 4th part of array 'C' elements.
  }


 }
}



 printf("\n\n\a\t\t ============> ( SUCCESS^_^!! ---> A*B=C ) <===========\n\n (Matrix 'C')=\n"); //show user's Final Multiplication result.

for(i=0;i<A_row_num;i++)
{
for(j=0;j<B_colm_num;j++)
 printf("%-.2f\t",C[i][j] );
 printf("\n");
}

printf("\n");
}

//stoped here ! 6-2-2021
//try to fix the return or pass arrays to main function + try whole matrix operations in test.c
