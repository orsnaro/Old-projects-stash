//this header belongs to ors simple calc :)
#include "includes.h"
int x,y;
float mat_add( float A[x][y], float B[x][y],float C[x][y]);




float matrix_operations(float A[x][y], float B[x][y],float C[x][y])
{
    char  main_mnu_slct ;
    float average_value ;
    static float Z[4][4],W[4][4],K[4][4];

    //MAIN menu
        printf("\n \n ---------------------------------------------------------------------\n");
        printf("\n \n //\n ---------------->\t WELCOME! THIS is MATRIX SECTION \t<--------------. \n \t\t //Please Select your option: \v\v \n");
        printf("\n \n //\n press \"a\" if you want to Add . \n");
        printf("press \"b\" if you want to Subtract . \n");
        printf("press \"c\" if you want to Multiply . \n");
        printf("press \"d\" if you want to find the average value of an Array  . \n");
        printf("press \"e\" if you want to sort your Matrix\n\n");
        printf("press \"f\" to INCLUDE last result in a new operation\n\n");
        printf("PLEASE! choose  ==> ");
        scanf("%c",&main_mnu_slct);



switch(main_mnu_slct)
{
        case'a':
{
  static float Z[4][4],W[4][4],K[4][4];
  mat_add( Z , W, K) ;
}
break;

        case'b':
{

}
break;

       case'c':
{

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
return(0);}

}






                 // --------------------functions body--------------------


// 1) MATRICES Addtion**************************************************************
float mat_add( float A[4][4], float B[4][4], float C[4][4])
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

//show user's Matrix 'A' final value.
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

return 0;}
