
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>

#include <direct.h>

int main()
{
  int gd= DETECT , gm , errorcode;
  initgraph(&gd, &gm, (char*) " " );
  getch();
  closegraph();


  return 0;
}
