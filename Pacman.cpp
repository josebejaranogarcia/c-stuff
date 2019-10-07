#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <texto.h>




void pinta();

int mapa [25] [53] = {

1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,0,0,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,1,
1,1,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,0,0,0,1,
1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,
1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,2,0,1,1,1,1,2,0,1,1,1,1,0,0,1,1,1,1,2,0,1,1,1,1,0,0,1,
1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,
1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,
1,1,0,0,1,1,1,1,0,0,1,1,1,1,2,0,1,1,1,1,2,0,1,1,1,1,2,0,1,1,1,1,2,0,1,1,1,1,0,0,1,1,1,1,2,0,1,1,1,1,2,0,1,
1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,
1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,
1,1,0,0,1,1,1,1,0,0,1,1,1,1,2,0,1,1,1,1,2,0,1,1,1,1,2,0,1,1,1,1,2,0,1,1,1,1,0,0,1,1,1,1,2,0,1,1,1,1,2,0,1,
1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,
1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,
1,1,0,0,1,1,1,1,0,0,1,1,1,1,2,0,1,1,1,1,2,0,1,1,1,1,2,0,1,1,1,1,2,0,1,1,1,1,0,0,1,1,1,1,2,0,1,1,1,1,2,0,1,
1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,
1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
};


int bon=0;
main()

{
   int gdriver = DETECT, gmode, errorcode;
   int x, y, cursor,x1=9,y1=5,x2=21,y2=7,x3=39,y3=25;
   int i,w=1,xr=4,yr=8,a=0;
   initgraph(&gdriver, &gmode, "\\tc\\bgi");

   errorcode = graphresult();
   if (errorcode != grOk)
   {
      gprintf("Graphics error:        ", grapherrormsg(errorcode));
      gprintf("Press any key to halt:");
      getch();
      exit(1);
   }


pinta();
     x=5;
     y=3;

	setfillstyle(1,15);
	sector(x*11,y*15,20,320,5,5);

      do {

      gprintfxy (10,25,"bon %d",bon);

      if (bon == 40) {
	 gprintfxy(300,250,"Has ganado");
	 sound(100);
	 delay(500);
	 nosound();
	 getch();
	 exit(1);
	 }

      setcolor (0);
      setfillstyle(1,0);
      fillellipse(x1*11,y1*15,xr,yr);
      y1++;

	   if (y1> 20) y1=5;
	      delay (5);
	      setcolor (12);
	      setfillstyle(1,12);
	      fillellipse(x1*11,y1*15,xr,yr);
	      delay(5);

		  if (y1==200){
		     setcolor (0);
		     setfillstyle(1,0);
		     fillellipse(x1*11,y1*15,xr,yr);
		     y1=70;
		     setcolor (0);
		     setfillstyle(1,0);
		     fillellipse(x1*11,y1*15,xr,yr);
		     y1++;
		     delay (5);
		     setcolor (12);
		     setfillstyle(1,12);
		     fillellipse(x1*11,y1*15,xr,yr);
		     }


   setcolor (0);
   setfillstyle(1,0);
   fillellipse(x2*11,y2*15,xr,yr);
   y2++;

       if (y2> 20) y2=5;
	  delay (15);
	  setcolor (2);
	  setfillstyle(1,2);
	  fillellipse(x2*11,y2*15,xr,yr);
	  delay(15);

	      if (y2==200){
		 setcolor (0);
		 setfillstyle(1,0);
		 fillellipse(x2*11,y2*15,xr,yr);
		 y2=70;
		 setcolor (0);
		 setfillstyle(1,0);
		 fillellipse(x2*11,y2*15,xr,yr);
		 y2++;
		 delay (15);
		 setcolor (2);
		 setfillstyle(1,2);
		 fillellipse(x2*11,y2*15,xr,yr);
		 }


   setcolor (0);
   setfillstyle(1,0);
   fillellipse(x3*11,y3*15,xr,yr);
   y3++;

       if (y3> 20) y3=5;
	  delay (15);
	  setcolor (9);
	  setfillstyle(1,9);
	  fillellipse(x3*11,y3*15,xr,yr);
	  delay(15);

	      if (y3==200){
		 setcolor (0);
		 setfillstyle(1,0);
		 fillellipse(x3*11,y3*15,xr,yr);
		 y3=70;
		 setcolor (0);
		 setfillstyle(1,0);
		 fillellipse(x3*11,y3*15,xr,yr);
		 y3++;
		 delay (15);
		 setcolor (9);
		 setfillstyle(1,9);
		 fillellipse(x3*11,y3*15,xr,yr);
		 }

   if (x1==x && y1==y || x2==x && y2 ==y || x3==x && y3==y){
   gprintfxy(216,390,"Perdiste Loser");
   getch();
   exit(1);
   }


	  if (kbhit()){
	  cursor = getch();
	  switch (cursor)
	     {

	      case 0x4b:          //izquierda
	      setcolor (0);
	      setfillstyle (1,0);
	      sector (x*11,y*15,0,360,5,5);

	      if (mapa [y] [x-1] == 0 || mapa [y] [x-1] == 2)
		 {
		 x--;

		 if (mapa [y] [x-1] == 2)
		    {
		    bon++;
		    mapa [y] [x-1] = 0;
		    }
		 }

	     setfillstyle (1,14);
	     sector (x*11,y*15,20,325,5,5);
	     delay (10);
	     sector (x*11,y*15,10,340,5,5);
	     delay (10);
	     sector (x*11,y*15,0,360,5,5);

	     break;

	     case 0x4d:        //derecha
	      setcolor (0);
	      setfillstyle (1,0);
	      sector (x*11,y*15,0,360,5,5);

	      if (mapa [y] [x+1] == 0 || mapa [y] [x+1] == 2)
		 {
		 x++;

		 if (mapa [y] [x+1] == 2)
		    {
		     bon++;
		     mapa [y] [x+1] = 0;
		    }
		 }

	     setfillstyle (1,14);
	     sector (x*11,y*15,20,325,5,5);
	     delay (10);
	     sector (x*11,y*15,10,340,5,5);
	     delay (10);
	     sector (x*11,y*15,0,360,5,5);
	     break;

		case 0x48:        //arriba
	      setcolor (0);
	      setfillstyle (1,0);
	      sector (x*11,y*15,0,360,5,5);

	      if (mapa [y-1] [x] == 0 || mapa [y-1] [x] == 2)
		 {
		 y--;

		   if (mapa [y-1] [x] == 2)
		      {
		      bon++;
		      mapa [y-1] [x] = 0;
		      }
		 }

	     setfillstyle (1,14);
	     sector (x*11,y*15,20,325,5,5);
	     delay (10);
	     sector (x*11,y*15,10,340,5,5);
	     delay (10);
	     sector (x*11,y*15,0,360,5,5);

	     break;

		case 0x50:        //abajo
	      setcolor (0);
	      setfillstyle (1,0);
	      sector (x*11,y*15,0,360,5,5);

	      if (mapa [y+1] [x] == 0 || mapa [y+1] [x] == 2)
		 {
		 y++;

		    if (mapa [y+1] [x] == 2)
		       {
		       bon++;
		       mapa [y+1] [x] = 0;
		       }
	      }

	     setfillstyle (1,14);
	     sector (x*11,y*15,20,325,5,5);
	     delay (10);
	     sector (x*11,y*15,10,340,5,5);
	     delay (10);
	     sector (x*11,y*15,0,360,5,5);
	     break;
	     }

	     }

	 } while(cursor!=27);
	   cleardevice();
	   setcolor(14);
	   gprintfxy(246,196,"Perdiste Loser");
	   getch();
	   exit(1);

	 getch();
	 closegraph();


return 0;
}


void pinta()
{
  /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int x, y, cursor;

   initgraph(&gdriver, &gmode, "");

   errorcode = graphresult();
   if (errorcode != grOk)
   {
      gprintf("Graphics error:           ", grapherrormsg(errorcode));
      gprintf("Press any key to halt:");
      getch();
      exit(1);
   }

for (y=1;y<25;y++)
 for (x=1;x<53;x++)
    if (mapa [y] [x] == 1)
       {
	setcolor (1);
//	 gprintfxy (x*11,y*15,"²");
       circle(x*11,y*15,5);
       }
    else
       if (mapa [y] [x] == 2)
       {
	setcolor (2); gprintfxy (x*11,y*15,"*");
       }

}
