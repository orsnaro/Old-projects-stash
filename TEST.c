//this header belongs to ors simple calc :)
#include "includes.h"

int x=4;
int y=4;
int mat_sort( float A[x][y]);
int i,j;
int main()
{

float Z[x][y];
mat_sort(Z);
return 0;
}

int mat_sort( float A[x][y])
{
  int i,j;
  x=4,y=4;
  int n=-1;
 static int A_row_num,A_colm_num,A_chk_row,A_chk_colm;
 static int k,l;
 char sort_meth,c;
 static float temp,temp_2;  // temp is the "tool" to switch array elements places.

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
          case'a': // can't make an inner\nested  functions  in C with out gnu. SO will write whole "array sort code" inside the switch func. Then maybe later we will define it independently in Main_Calc.c.
  {
            for(i=0;i<x;++i)
            {

              for(j=0;j<y;++j)

             {
                 n=-1;
                 for(k=i;k<x;++k)
              {
                     for(l=j;l<y;++l) // was initialized l=j most of the time. i need to make initialized ==> (k>i?l=0:l=j)
               {// just dont **** duplicate values !!!! *** #$!$!!$!^%$&!!.

printf("_____________________this will be Deleted after DEBUG!!______________________\n",i,j,k,l);
                 for(int i_3=0;i_3<x;i_3++)
                 {
                 for(int j_3=0;j_3<y;j_3++)
                 printf("%-.2f\t",A[i_3][j_3] );
                 printf("\n");
                 }
                 printf("_____________________i=%d j=%d k=%d l=%d ______________________\n",i,j,k,l);

                    if(i==k && j==l)
                    continue;

                    if(A[k][l]<A[i][j])
                {
                    temp=A[i][j];
                    A[i][j]=A[k][l];
                    A[k][l]=temp;

                }

                while(A[i][j]==A[k][l] && i!=k && j!=l ) //now re-arrange equal elements
                {
                  printf("Duplicated values counter= %d\n",n+1);
                  n+=1;
                  if((l+n)>=y)
                  {
                  k+=1;
                  l=0;
                  }
                  else
                  l+=n;

                  while(A[i][j]==A[k][l] && i!=k && j!=l )
                  {
                  temp_2=A[k][l];
                  for(int i_2=k; i_2>i && i_2>=0; i_2--)
                  {
                  for(int j_2=l; (j_2>j || (j_2<=j && i_2>i)) && j_2>=0; j_2--)
                  {
                    A[i_2][j_2]=A[i_2][j_2-1];
                  }

                  }
                  if((j+1)>=y)
                    A[i+1][0]=temp_2;
                  else if ((j+1)<y)
                    A[i][j+1]=temp_2;
                    k=i;
                    l=j;

                  }
                 }
               }
              }
             }
            }


  }

          break;

          case'd':
  {
    for(i=x;i>=1;i--)
    {
      for(j=y;j>=1;j--)
     {
         for(k=i;k>=1;--k)
      {
             for(l=j;l>=1;--l) // I don't "yet" know how *NOT TO* compare the element with it self in 2D+ arrays (btw not a big deal keep it simple omar).
       {

            if(A[k][l]<A[i][j])
        {
            temp=A[i][j];
            A[i][j]=A[k][l];
            A[k][l]=temp;

        }


        }

       }
      }
     }



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
  printf("\n (SORTED matrix 'A')=\n" );
  for(i=0;i<x;i++)
  {
  for(j=0;j<y;j++)
  printf("%-.2f\t",A[i][j] );
  printf("\n");
  }


  /* ---------------------------------------------------------------------------------EOF-----------------------------------------------------------------------------------------------*/
return 0 ;}

//stoped here ! 10-2-2021
// sortiing equal values not working + sort menu bug.
//  i think we can fix sorting equal values if we learned how not to compare same alement in 2D+ arrays
