//this header belongs to ors simple calc :)
#include "includes.h"

static int A_row_num,A_colm_num,B_row_num,B_colm_num;
int x=4;
int y=4;

void mat_add( float A[x][y], float B[x][y],float C[x][y]);
void mat_sub( float A[x][y], float B[x][y],float C[x][y]);
void mat_multiply( float A[x][y], float B[x][y],float C[x][y]);
void mat_avg( float A[x][y], float B[x][y], float C[x][y]);
void mat_sort( float A[x][y] );
float matrix_operations(float A[x][y], float B[x][y],float C[x][y])
{
    static char  mat_mnu_slct ;
    static float average_value ;
    float Z[x][y],W[x][y],K[x][y];
    static char func_return,ch;

    Selection:
    //MAIN menu
    fflush(stdout);
        printf("\n \n ---------------------------------------------------------------------\n");
        printf("\n \n //\n ---------------->\t WELCOME! THIS is MATRIX SECTION \t<--------------. \n \t\t //Please Select your option:  \n");
        printf("\n \n //\n press \"a\" if you want to Add Matrices . \n");
        printf("press \"b\" if you want to Subtract Matrices . \n");
        printf("press \"c\" if you want to Multiply Matrices . \n");
        printf("press \"d\" if you want to find the average value of an Array  . \n");
        printf("press \"e\" if you want to sort your Matrix\n\n");
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
  mat_avg(Z, W, K);
}
break;

        case'e':
{
  mat_sort(Z);
}
break;



        default:
{
  puts("\a #OPS!---------------------> something went wrong  !!"
        "please re-select! <------------------------------");
  goto Selection ;
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




















// 4) MATRICES Average Value**************************************************************
void mat_avg( float A[x][y], float B[x][y], float C[x][y])
{
int i,j;
x=4,y=4;
float mat_avg_value=0;
int A_row_num,A_colm_num,A_chk_row,A_chk_colm;

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
printf("\n\n\a\t\t SUCCESS!!---> (Matrix 'A') average value = %.2f\n\n\n",mat_avg_value);

/* --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
}




























// 4) MATRICES SORT**************************************************************
void mat_sort( float A[x][y])
{
  int i,j;
  x=4,y=4;
  int A_row_num,A_colm_num,A_chk_row,A_chk_colm;
  int k,l;
 char sort_meth,c;
 static float temp,smallv,bigv;  // temp is the "tool" to switch array elements places.

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
  printf("\t\tPLEASE! fill Matrix 'A' to sort it --((input  values \"*ROW by ROW*\"))-- \n\n");
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

  sort_method:

        printf("\t\t =====================> Choose Sort method (*character!!*) <=====================:\n");// using   sorting algoritihm
        printf("\t\t 'a' Ascending order?\n");
        printf("\t\t 'd' Descending order?\n");
        printf("PLEASE! choose  ==> ");
        c=getchar();
        sort_meth= c;

        switch(sort_meth)
{
          case'a':
  {
            for(i=0;i<x;i++)
            {
              for(j=0;j<y;j++)
             {
              smallv = A[i][j];

                 for(k=i;k<x;k++)
              {
                     for(l=j+1;l<y;l++)
               {
                    bigv=A[k][l];
                    printf("f");
                    if(bigv<=smallv)
                {
                    temp=smallv;
                    smallv=bigv;
                    bigv=temp;
                    k=i,l=j+1;
                }
               }
              }
             }
            }

  }
            /*check if two elements are equal does it work?*/
          break;

          case'd':
          {

          }
          break;

          default:
          {
            printf("\a -----------------OPS!! something went wrong. PLEASE! reselect sort method------------------");
            goto sort_method ;
          }
}




        //show user's Matrix 'A' final sorted value.
  printf("\t\t------------------------------------OUTPUT------------------------------------ \n");
  printf("\n (SORTED Arrray 'A')=\n" );
  for(i=0;i<x;i++)
  {
  for(j=0;j<y;j++)
  printf("%-.2f\t",A[i][j] );
  printf("\n");
  }














//******************************MAT SORT A


  /* ---------------------------------------------------------------------------------EOF-----------------------------------------------------------------------------------------------*/
}
