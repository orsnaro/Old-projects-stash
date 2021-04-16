
// Report #1 done by omar rashad mahmoud salem no.138 section 6
// 1st year electrical engineering 20/21

#include "includes.h"
#define PI 3.14159265


int main(void)
{
int gdriver= DETECT , gmode , errorcode;
static float x,y, theta , m ;
m= tan (theta) ;
y= (tan_ray*(x-490))+85;
initgraph(&gdriver, &gmode, (char*)"");

setbkcolor(11); //sky!!
cleardevice();

for (i=0;  i<6; i++)
{
  theta=theta+(60*(PI/180))
  setcolor(YELLOW);//sunrays
  line(490,570,y,y);
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
