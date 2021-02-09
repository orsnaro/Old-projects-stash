//this header belongs to ors simple calc :)
#include "includes.h"

int x=4;
int y=4;
void mat_sort( float A[x][y]);
int i,j;
int main()
{

float Z[x][y];
mat_sort(Z);
return 0;
}

void mat_sort( float A[x][y])
{
  int i,j;
  x=4,y=4;
  int A_row_num,A_colm_num,A_chk_row,A_chk_colm;
  int k,l;
 char sort_meth,c;
 static float temp;  // temp is the "tool" to switch array elements places.

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
                 for(k=i;k<x;k++)
              {
                     for(l=j;l<y;l++) // I don't "yet" know how not to compare the element with it self in 2D+ arrays (btw not a big deal keep it simple omar).
               {
                    printf("%d",k);
                    if(A[k][l]<A[i][j])
                {
                    temp=A[i][j];
                    A[i][j]=A[k][l];
                    A[k][l]=temp;
                    k=i;
                    l=j+1;
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


  /* ---------------------------------------------------------------------------------EOF-----------------------------------------------------------------------------------------------*/
}

//stoped here ! 9-2-2021
// need to fix sorting equal elements + descinding sorting + sort menu bug.
