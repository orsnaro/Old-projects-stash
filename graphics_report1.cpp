
// Report #1 done by omar rashad mahmoud salem no.138 section 6
// 1st year electrical engineering 20/21
#include <math.h>
#include "includes.h"
#define PI 3.14159265


int main(void)
{
int i , gdriver= DETECT , gmode , errorcode;
static float x, theta , m ;
m = tan(theta) ;
float y= ( m*80)+85 ;
initgraph(&gdriver, &gmode, (char*)"");


setbkcolor(11); //sky!!
cleardevice();

for (theta=0; theta==180; theta+=60)
{
  setcolor(YELLOW);//sunrays
  line(480,y,580,y);
}


setcolor(WHITE); //sun it self
setlinestyle(0,1,3);
circle(530,85,40);
setcolor(YELLOW);
fillellipse(530,85,38.5,38.5);

//i will fininsh the task then make it alive (sun and car and windmills will move!)








  getch();
  closegraph();
   return 0;
}
