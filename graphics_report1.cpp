
// Report #1 done by omar rashad mahmoud salem no.138 section 6
// 1st year electrical engineering 20/21

#include <graphics.h> //we can include them in one header.
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <direct.h>



int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   float midx, midy,x;
   int radius = 300;


   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, (char*)"");


   /* draw the circle */
   for(midx=0;midx<=640;midx++)
{ //  setcolor(radius/5);

   midy=(480.0/640.0)*midx;
   setcolor(10);
   line(midx-30,midy,midx+30,midy);
   line(midx,midy-30,midx,midy+30);
   circle(midx, midy, 30);
   delay(30);
   setcolor(0);
   line(midx-30,midy,midx+30,midy);
   line(midx,midy-30,midx,midy+30);
   circle(midx, midy, 30);
   }

   /* clean up */
   getch();
   closegraph();
   return 0;
}
