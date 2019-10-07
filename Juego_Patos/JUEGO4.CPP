#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <stdlib.h>
#include <string.h>

//Funciones del raton

void ratonlimver(int x, int y)
{
  union REGS inregs, outregs;
  inregs.x.ax = 8;
  inregs.x.cx = x;
  inregs.x.dx = y;
  int86(0x33, &inregs, &outregs);
}

void ratonlimhor (int x, int y)
{
  union REGS inregs, outregs;
  inregs.x.ax = 7;
  inregs.x.cx = x;
  inregs.x.dx = y;
  int86 (0x33, &inregs, &outregs);
}

int iniciaraton() //comprueba si esta instalado
{
  union REGS inregs, outregs;
  inregs.x.ax=0;
  int86 (0x33, &inregs, &outregs);
  return (outregs.x.ax);
}

void mueveraton (int x, int y)   //coloca el raton donde le indiquemos
{
  union REGS inregs, outregs;
  inregs.x.ax = 4;
  inregs.x.cx = x;
  inregs.x.dx = y;
  int86 (0x33, &inregs, &outregs);
}

void siraton()  //muestra el puntero del raton
{
  union REGS inregs, outregs;
  inregs.x.ax = 1;
  int86 (0x33, &inregs, &outregs);
}

void noraton()   //oculta el puntero del raton
{
  union REGS inregs, outregs;
  inregs.x.ax = 2;
  int86 (0x33, &inregs, &outregs);
}

void ratonpos(int *x, int *y)  //devuelve la posicion del puntero
{
  union REGS inregs, outregs;
  inregs.x.ax = 3;
  int86 (0x33, &inregs, &outregs);
  *x = outregs.x.cx;
  *y = outregs.x.dx;
}

int botonsoltado (int numboton)
{
  union REGS inregs, outregs;
  int veces;
  inregs.x.ax = 6;
  inregs.x.bx = numboton;
  int86 (0x33, &inregs, &outregs);
  veces = outregs.x.bx;
  if (veces>0)
	  return (1);
  else
	  return (0);
}


/* numboton  -->  0 Bot¢n Izdo, 1 Bot¢n Dcho  */
int botonpulsado(int numboton)
{
  union REGS inregs, outregs;
  int veces;
  inregs.x.ax=5;
  inregs.x.bx=numboton;
  int86 (0x33, &inregs, &outregs);
  veces = outregs.x.bx;
  if (veces>0)
	 return (1);
  else
	 return (0);
}
//--------------------------------
//Estructura que escribe y lee los records

struct record
{
   char nombre [50];
   int capturas;
};

//Clases de mira y animal

class mira
{
  protected:
	 int x,y;
	 int color;
	 int fondo;
	 int radio;
  public:
	 void mover (int incx, int incy);
	 void dibujar (void);
	 void borrar (void);
	 mira (int x0, int y0,int fondo0, int color0, int radio0);
	 //~mira(void);

};
void mira::mover(int incx, int incy)
{
	borrar();
	x=incx; //igulamos coordenadas al las devueltas por la funcion del raton
	y=incy;
	dibujar();
}

void mira::borrar(void)
{
	setcolor(fondo);
	circle(x,y,radio);
	line(x-14,y,x+14,y);
	line(x,y-14,x,y+14);
}

void mira::dibujar(void)
{
   setcolor(color);
   circle(x,y,radio);
   line(x-14,y,x+14,y);
   line(x,y-14,x,y+14);
}

mira::mira(int x0=300,int y0=200, int fondo0=0, int color0=15, int radio0=10)
{
	x=x0;
	y=y0;
	fondo=fondo0;
	color=color0;
	radio=radio0;
}
/*mira::~mira(void)
{
   cleardevice();
} */

//---------------------------------------

class animal
{
   protected:

	 int x,y,w,z;
	 int fondo;
	 int tamano;
	 int direc,ver, elige;
	 char *fila; //lee de fichero dependoendo del tama§o
	 FILE *fd;
   public:

	void mover(int incx, int incy, int direc0);
	void abrir (void);
	void borrar (void);
	void dibujar (void);
	friend int choque (int elige, animal *a);
	friend int disparo (int x, int y, animal *a);
	animal (int x0, int y0, int direccion0, int tamano0, int fondo0, int elige0);
	~animal(void);
};

void animal::mover(int incx, int incy, int direc0)
{

	direc=direc0;  //obtenemos direccion
	borrar(); //borramos pato inicial
	x=x+incx; //incrementamos segun valores recibidos
	y=y+incy;
	abrir();
	dibujar();
}

void animal::borrar(void)
{
	setcolor(fondo);   //visualiza un bar del color del fondo en las coordenadas del pato
	setfillstyle(SOLID_FILL,fondo);
	bar(x,y,x+tamano,y+tamano);
}

void animal::abrir(void)
{
   if (elige==0) //pato
   {
      if (direc!=4)
      {
	 if (ver== 0)
	 {
	    fd=fopen("c:\\patos\\1I.jav","rb");
	    if (fd==NULL)
	    {
	       fd=fopen("c:\\patos\\1I.jav","rb");
		  if (fd==NULL)
		  {
			outtextxy (200,200,"Pegue la carpeta ``patosÔÔ en el disco ``CÔÔ");
			getch();
		  }
	    }
	    fflush (fd);
	    ver=1;
	 }
	 else
	 {
	    fd=fopen("c:\\patos\\3I.jav","rb");
	    ver=0;
	 }
      }
      else
      {
	 if (ver ==0)
	 {
	    fd=fopen("c:\\patos\\0m.jav","rb");
	    ver=1;
	 }
	 else if (ver ==1)
	 {
	    fd=fopen("c:\\patos\\3i.jav","rb");
	    ver=2;
	 }
	 else if (ver ==2)
	 {
	    fd=fopen("c:\\patos\\3i.jav","rb");
	    ver=1;
	 }
      }
   }
   else if (elige==1)  //oca
   {
      if (direc!=4)
      {
	 if (ver ==0)
	 {
	    fd=fopen("c:\\patos\\o1i.jav","rb");
	    ver=1;
	 }
	 else
	 {
	    fd=fopen("c:\\patos\\o2i.jav","rb");
	    ver=0;
	 }
      }
      else
      {
	 if (ver ==0)
	 {
	    fd=fopen("c:\\patos\\o0m.jav","rb");
	    ver=1;
	 }
	 else if (ver==1)
	 {
	    fd=fopen("c:\\patos\\o2i.jav","rb");
	    ver=2;
	 }
	 else
	 {
	    fd=fopen("c:\\patos\\o2i.jav","rb");
	    ver=1;
	 }
      }
   }
}

void animal::dibujar(void)
{

   fseek(fd,0,SEEK_SET);
   if ((direc==0)||(direc==1)||((direc==4)&&(ver==0))) //ver normal
   {
      fseek(fd,0,SEEK_SET);
      for(w=0;w<tamano;w++)
      {
	  flushall();
	  fread(fila,tamano,1,fd);
	  flushall();
	  for(z=0;z<60;z++)
	  {
		 putpixel((x+z),(y+w),fila[z]);
	  }
      }
      if (direc==4)
	 delay (500);
   }
   else if ((direc==2)||(direc==3))  //ver mirando a derecha
   {
      fseek(fd,0,SEEK_SET);
      for(w=0;w<tamano;w++)
      {
	  fread(fila,tamano,1,fd);
	  for(z=0;z<tamano;z++)
	  {
		 putpixel((x+(60-z)),(y+w),fila[z]);
	  }
      }
   }
   else if ((direc==4)&&(ver==1))  //ver mirando a derecha y abajo
   {
      fseek(fd,0,SEEK_SET);
      for(w=0;w<tamano;w++)
      {
	  fread(fila,tamano,1,fd);
	  for(z=0;z<tamano;z++)
	  {
		 putpixel((x+(60-z)),(y+(60-w)),fila[z]);
	  }
      }
   }
   else if ((direc==4)&&(ver==2))  //ver mirando a izquierda y abajo
   {
      fseek(fd,0,SEEK_SET);
      for(w=0;w<tamano;w++)
      {
	  fread(fila,tamano,1,fd);
	  for(z=0;z<tamano;z++)
	  {
		 putpixel((x+(z)),(y+(60-w)),fila[z]);
	  }
      }
   }
   fclose (fd);
}

animal::animal(int x0, int y0, int direccion0, int tamano0, int fondo0,  int elige0)
{
	x=x0;
	y=y0;
	elige=elige0;
	fondo=fondo0;
	direc=direccion0;
	tamano=tamano0;
	ver=0;
	fila=(char*)malloc(tamano);
}

animal::~animal(void)
{
   free (fila);
   fclose (fd);
   fcloseall ();
   flushall();
}

//---------------------------------------

//Funciones

char menu (void);
void reglas (void);
void presentacion (void);
void records (void);
int juego (void);
void copia_record (int puntos);
void fondo (void);
int inicializa ();
FILE * pato (int direccion, int *ver);
FILE * oca (int direccion, int *ver);
void incremento (int *incx, int *incy, int direccion);
int choque (int elige, animal *a);
int disparo (int x, int y, animal *a);
int cartuchos (int *cartucho);

//---------------------------------
void main (void)
{
   char salir;
   int puntos;
   do
   {
      salir=menu();
      fcloseall();
      flushall();
      switch (salir)
      {
	 case '1':
	    puntos=juego();
	    copia_record(puntos);
	    break;
	 case '2':
	    reglas();
	    break;
	 case '3':
	    presentacion();
	    break;
	 case '4':
	    records();
	    break;
      }
   }while (salir != 27);
}

// Funciones del main

char menu (void)
{
    int controlador=VGA, modo=VGAHI, i, j;
    char tecla;
    FILE *cz;
    char * fila;

    initgraph(&controlador,&modo,"c:\\bc\\bgi");
    setbkcolor(11);
    cleardevice();
    setcolor(LIGHTGREEN); //valle
    setfillstyle(SOLID_FILL,LIGHTGREEN);
    bar(0,410,640,480);
    fondo();
    fila=(char *)malloc(180);
    cz=fopen("c:\\patos\\menu.jav","rb");
    for (i=0;i<150;i++)
    {
	  fread(fila,180,1,cz);
	  for (j=0;j<180;j++)
	  {
	  putpixel((j+400),(i+290),fila[j]);
	  }
	  fflush(cz);
    }
    free (fila);
    //setcolor (BROWN);
    //settextstyle(1,HORIZ_DIR,6);
    //outtextxy (175,3,"DUCK'S HUNTER");
    //settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
    setcolor (BLUE);
    outtextxy (275,13,"DUCK'S HUNTER");
    outtextxy (100,75,"<MENU>");
    outtextxy (50,100,"1) Jugar");
    outtextxy (50,120,"2) Reglamento");
    outtextxy (50,140,"3) Presentaci¢n");
    outtextxy (50,160,"4) Records");
    outtextxy (50,180,"ESC) Salir");
    outtextxy (50,220,"ELIGE UNA OPCION");
    tecla=getch();
    closegraph();
    flushall();
    fclose (cz);
    fcloseall();
    return (tecla);
}
void reglas (void)
{
    int controlador=VGA, modo=VGAHI, i, j;
    initgraph(&controlador,&modo,"c:\\bc\\bgi");
    setbkcolor(11);
    cleardevice();
    setcolor(LIGHTGREEN); //valle
    setfillstyle(SOLID_FILL,LIGHTGREEN);
    bar(0,410,640,480);
    fondo();
    //setcolor (BROWN);
    //settextstyle(1,HORIZ_DIR,6);
    //outtextxy (175,3,"DUCK'S HUNTER");
    //settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
    setcolor (BLUE);
    outtextxy (275,13,"DUCK'S HUNTER");
    outtextxy (50,80,"El juego consiste en matar a los patos que van apareciendo.");
    outtextxy (50,110,"Para mover el punto de mira utilizaremos el rat¢n.");
    outtextxy (50,140,"Para dispara hacemos click con el boton izquierdo del rat¢n.");
    outtextxy (50,170,"Tenemos dos tiros seguidos de cada vez. Si los gastamos debemos");
    outtextxy (50,185,"esperar a que la escopeta se cargue.");
    outtextxy (50,240,"Intenta matar el mayor n£mero de aves posible.");
    outtextxy (50,280,"El juego finaliza cuando 4 de las aves se nos escapen sin matarlas.");
    outtextxy (280,350, "BUENA SUERTE");
    getch();
    closegraph();
    flushall();
    fcloseall();
}
void presentacion (void)
{
    int controlador=VGA, modo=VGAHI, i, j;
    FILE *cz;
    char * fila;

    initgraph(&controlador,&modo,"c:\\bc\\bgi");
    setbkcolor(11);
    cleardevice();
    setcolor(LIGHTGREEN); //valle
    setfillstyle(SOLID_FILL,LIGHTGREEN);
    bar(0,410,640,480);
    fondo();
    fila=(char *)malloc(180);
    cz=fopen("c:\\patos\\menu.jav","rb");
    for (i=0;i<150;i++)
    {
	  fread(fila,180,1,cz);
	  for (j=0;j<180;j++)
	  {
	  putpixel((j+100),(i+290),fila[j]);
	  }
	  fflush(cz);
    }
    free (fila);
    fcloseall();
    flushall();
   sound (880); delay (100); nosound();
   sound (1174.64); delay (100); nosound();
   sound (880); delay (100); nosound();
   sound (1174.64); delay (100); nosound();
   sound (880); delay (800); nosound();
   sound (698.45); delay (400); nosound();
   sound (783.99); delay (400); nosound();
   sound (587.32); delay (800); nosound();
   delay (400);
   setcolor (BROWN);
   outtextxy (275,13,"DUCK'S HUNTER");
   sound (880); delay (100); nosound();
   sound (1174.64); delay (100); nosound();
   sound (880); delay (100); nosound();
   sound (1174.64); delay (100); nosound();
   sound (880); delay (800); nosound();
   sound (698.45); delay (400); nosound();
   sound (659.25); delay (200); nosound();
   sound (587.32); delay (200); nosound();
   sound (523.25); delay (800); nosound();
   delay (400);
   setcolor (BLUE);
   outtextxy (50,80,"Juego realizado por:");
   sound (880); delay (100); nosound();
   sound (1174.64); delay (100); nosound();
   sound (880); delay (100); nosound();
   sound (1174.64); delay (100); nosound();
   sound (880); delay (800); nosound();
   sound (698.45); delay (400); nosound();
   sound (783.99); delay (200); nosound();
   sound (698.45); delay (200); nosound();
   sound (659.25); delay (800); nosound();
   delay (400);
   setcolor (RED);
   outtextxy (150,120,"FRANCISCO JAVIER ALONSO");
   sound (880); delay (100); nosound();
   sound (1174.64); delay (100); nosound();
   sound (880); delay (100); nosound();
   sound (1174.64); delay (100); nosound();
   sound (880); delay (800); nosound();
   sound (698.45); delay (400); nosound();
   sound (783.99); delay (400); nosound();
   sound (1046.50); delay (1000); nosound();
   delay (800);
   closegraph();
}


void records (void)
{
   FILE *fd;
   int i;
   struct record lee [5];
   fd=fopen("record.jav","rb");
   clrscr();
   if (fd == NULL)
      printf ("\n\n\n\t\tNing£n record disponible");
   else
   {
       fseek(fd,0,SEEK_SET);
       fread(lee,52,5,fd);
       printf ("\n\n\t\t\tRECORDS");
       printf ("\n\n\n\t   nombre                                            capturas");
       for (i=0;i<5;i++)
       {
	  printf ("\n\n\t%d) %-50s %d.",i+1,lee[i].nombre,lee[i].capturas);
       }
   }
   fclose (fd);
   printf ("\n\n\n(pulsa una tecla para salir)");
   free (lee);
   fcloseall ();
   flushall();
   getch();
}


//Funciones del juego

int juego (void)
{
   int controlador=VGA, modo=VGAHI;
   char tecla;
   char muerto [15];
   char escape [15];
   class mira *m;
   class animal *p;
   int x,y,salida,direccion,inicio=0,tamano,elige,*incx,*incy; //eliege=selecciona animal
   int *espera, contador=0, muertos=0, escapes=0, *cartucho, gurada;

   initgraph(&controlador,&modo,"c:\\bc\\bgi");
   setbkcolor(11);
   cleardevice();

   iniciaraton(); //comprueba si esta instalado
   noraton(); //oculta el puntero del raton
   ratonlimhor(10,630); //limite horizontal
   ratonlimver(10,390); //limite vertical
   mueveraton(320,200);  //posicion de inicio

   delay (100);
   setcolor (RED);
   outtextxy (250,220,"COMIENZA LA PARTIDA");
   delay (500);
   sound (880); delay (100); nosound();
   sound (1174.64); delay (100); nosound();
   sound (880); delay (100); nosound();
   sound (1174.64); delay (100); nosound();
   sound (880); delay (800); nosound();
   sound (698.45); delay (400); nosound();
   sound (783.99); delay (400); nosound();
   sound (587.32); delay (800); nosound();
   delay (1500);
   setcolor (11);
   outtextxy (235,220,"€€€€€€€€€€€€€€€€€€€€€€€");
   flushall();

   m= new mira(300,200,11,1,6); //creamos clase mira
   m->dibujar();
   fondo();
   setcolor(LIGHTGREEN); //valle
   setfillstyle(SOLID_FILL,LIGHTGREEN);
   bar(0,410,640,480);
   do
   {
      do
      {
	 if (inicio==0) //inicializa la posicion y direccion inicial del pato
	 {
		 setcolor(LIGHTGREEN); //valle
		 setfillstyle(SOLID_FILL,LIGHTGREEN);
		 bar(0,410,640,480);
		 *cartucho=3;
		 *cartucho=cartuchos(cartucho);
		 x=inicializa ();
		 direccion=random(4);//obtiene direccion
		 elige=random(2); //selecciona animal
	 }
	 switch (elige)
	 {
		case 0:  //pato;
		     tamano=60;
		     gurada=*cartucho;
		     *espera=100;
		     contador++;
		     if (inicio==0)    //crea objeto
		     {
			p= new animal(x,340,direccion,tamano,11,elige);
			inicio=1;
		     }
		     incremento(incx,incy,direccion); //calcula incrementos dependiendo de direccion
		     p->mover(*incx,*incy,direccion); //movemos pato
		     direccion=choque(elige,p);
		     *cartucho=gurada;
		     break;
		case 1:  //oca;
		     tamano=60;
		     gurada=*cartucho;
		     *espera=100;
		     if (inicio==0)    //crea objeto
		     {
			p= new animal(x,340,direccion,tamano,11,elige);
			inicio=1;
		     }
		     incremento(incx,incy,direccion); //calcula incrementos dependiendo de direccion
		     p->mover(*incx,*incy,direccion); //movemos pato
		     direccion=choque(0,p);
		     *cartucho=gurada;
		     break;
	 }
	 if (direccion==-2)
	 {
	    escapes++;//contador de escapados
	    direccion=-1;
	 }
	 fondo(); //visualiza el fondo

	 if (*cartucho> -1) //controla si no hay cartuchos (MIRA QUIETA)
	 {
	    ratonpos(&x,&y);//devuelve posicion del puntero
	    m->mover(x,y); //movemos la mira con los valores devueltos
	    if ((botonpulsado(0))&&(direccion!=4)) //indica la pulsacion del boton del raton y que el pato ya no este muerto
	    {
	       sound (1000); delay (50); nosound();
	       sound (980); delay (50); nosound();
	       sound (960); delay (50); nosound();
	       sound (940); delay (50); nosound();
	       sound (920); delay (50); nosound();
	       sound (900); delay (50); nosound();
               nosound();
	       *cartucho=cartuchos(cartucho);
	       direccion=disparo(x, y, p);
	       if (direccion==4)
	       {
		  muertos++;//contador de matados;
	       }
	    }
	 }
	 else
	 {
	    m->mover(320,385); //coloca mira en carga
	    mueveraton(320,385); //coloca raton en carga
	 }
	 if (*cartucho < -1)
	 {
	    *cartucho=*cartucho+1;
	    outtextxy(290,450,"CARGANDO");
	    if (*cartucho %3 ==0)
	       sound (880); delay (50); nosound();
	 }
	 else if (*cartucho==-1) //cuando no hay cartuchos
	 {
	    *cartucho=3;
	    setcolor(LIGHTGREEN);
	    outtextxy(290,450,"€€€€€€€€€€");
	    setcolor(BLUE);
	    *cartucho=cartuchos(cartucho);
	 }
	 if (direccion==-1)   //comprueba si el pato se escapa
	 {
	    delete p;
	    inicio=0;
	 }
	 m->dibujar(); //dibujamos la mira para que no quede tapada por el pato
	 delay(*espera);
	 if (kbhit()) //controla la salida del programa
	 {
	    tecla=getch();
	    if (!tecla)
	       tecla=getch();
	    if (tecla==27)
	       inicio=-5;
	 }
	 sprintf(muerto,"Capturas: %d",muertos);
	 sprintf(escape,"Escapadas: %d",escapes);
	 setcolor(LIGHTGREEN);
	 outtextxy(10,450,"€€€€€€€€€€€€€");
	 setcolor(BLUE);
	 outtextxy(10,450,muerto);
	 outtextxy(540,450,escape);

      }while((escapes<4)&&(inicio!=-5));
      cleardevice();
      if (tecla!=27)
      {
	 setcolor (BLUE);
	 outtextxy(280,240,"GAME OVER");
	 sound (880); delay (400); nosound();
	 sound (831.5); delay (400); nosound();
	 sound (783.99); delay (400); nosound();
	 sound (734); delay (1000); nosound();
	 nosound();
	 }
      else
      {
	 setcolor (BLUE);
	 outtextxy(220,240,"®Desea continuar? (s/n)");
	 tecla=getch();
	 if ((tecla=='s')||(tecla=='S'))
	 {
	    inicio=0;
	    setcolor(11);
	    outtextxy(220,240,"€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€");
	 }
      }
   }while((tecla!='n')&&(tecla!='N')&&(escapes<4));
   m->~mira();
   p->~animal();
   ratonlimhor(0,639); //limite horizontal
   ratonlimver(0,480); //limite vertical
   closegraph();
   flushall();
   fcloseall();
   free (muerto);
   free (escape);
   delete p;
   delete m;
   return (muertos);
}


int inicializa ()
{
   int salida, x;
   salida=random(5);//posicion
   switch (salida)//dependiendo del random sale de una x diferente
   {
	   case 0:
	  x=100;
	  break;
	   case 1:
	  x=210;
	  break;
       case 2:
	  x=320;
	  break;
       case 3:
	  x=430;
	  break;
       case 4:
	  x=540;
	  break;
   }
   return (x);
}

//-----------------------------------

void incremento (int *incx, int *incy,int direccion)
{
   switch (direccion) //indica el incremento dependiendo de la direccio
   {
       case 0:
	    *incx=(-25);
	    *incy=-8;
	    break;
       case 1:
	    *incx=(-29);
	    *incy=-8;
	    break;
       case 2:
	    *incx=29;
	    *incy=-8;
	    break;
       case 3:
	    *incx=25;
	    *incy=-8;
	    break;
       case 4:
	    *incx=0;
	    *incy=+15; //despues de ser abatido el pato cae
	    break;
   }
}

//-----------------------------------

int choque (int elige, animal *a)
{
   switch (elige)
   {
      case 0:
	     if ((a->x>550)||(a->x<10)) //controla choques laterales
	     {
		if (a->direc==0)
		{
			a->direc=3;
		}
		else if (a->direc==1)
		{
			a->direc=2;
		}
		else if (a->direc==2)
		{
			a->direc=1;
		}
		else if (a->direc==3)
		{
			a->direc=0;
		}
	     }
      }
      if (a->y < -60)
      {
	      a->borrar();
	      a->direc=-2;
      }
      if (a->y > 345)
	  {
	      a->borrar();
	      a->direc=-1;
      }
      return (a->direc);
}

//------------------------------------

int disparo (int x, int y, animal *a)
{
   if ((x > a->x) && (y > a->y) &&(x < a->x+(a->tamano)) && (y < a->y+(a->tamano)))
      return (4);
   return (a->direc);
}

//-------------------------------------

int cartuchos (int *cartucho)
{
   if (*cartucho==3)
   {
      setcolor(LIGHTRED);
      setfillstyle(SOLID_FILL,LIGHTRED);
      bar(300,450,305,458);
      setcolor(YELLOW);
      setfillstyle(SOLID_FILL,YELLOW);
      bar(300,458,305,462);
      setcolor(LIGHTRED);
      setfillstyle(SOLID_FILL,LIGHTRED);
      bar(314,450,319,458);
      setcolor(YELLOW);
      setfillstyle(SOLID_FILL,YELLOW);
      bar(314,458,319,462);
      *cartucho=*cartucho-1;
   }
   else if (*cartucho==2)
   {
      setcolor(LIGHTRED);
      setfillstyle(SOLID_FILL,LIGHTRED);
      bar(300,450,305,458);
      setcolor(YELLOW);
      setfillstyle(SOLID_FILL,YELLOW);
      bar(300,458,305,462);
      setcolor(LIGHTGREEN);
      setfillstyle(SOLID_FILL,LIGHTGREEN);
      bar(314,450,319,462);
      *cartucho=*cartucho-1;
   }
   else if (*cartucho==1)
   {
      setcolor(LIGHTGREEN);
      setfillstyle(SOLID_FILL,LIGHTGREEN);
      bar(300,450,305,462);
      setcolor(LIGHTGREEN);
      setfillstyle(SOLID_FILL,LIGHTGREEN);
      bar(314,450,319,462);
      *cartucho=-20;
   }
   return (*cartucho);
}

//--------------------------------------

void fondo (void)
{
   int i, j;
   setcolor(LIGHTGREEN);
   for(i=1;i<640;i++) //cesped
   {
	  if (i%11==0)
		 line(i,408,i,440);
	  else if(i%7==0)
		 line(i,406,i,440);
	  else if(i%5==0)
		 line(i,404,i,440);
	  else if(i%3==0)
		 line(i,402,i,440);
	  else if(i%2==0)
		 line(i,403,i,440);
	  else
		 line(i,401,i,440);
   }
}

//FUNCION QUE GUARDA LOS RECORDS

void copia_record (int puntos)
{
    FILE *fd;
    int i,contador;
    char *nombre= "vac°o";
    struct record lee [5];
    //struct record aux;
    fd=fopen("record.jav","r+b");
    clrscr();
    if (fd!=NULL)
    {
	  fread(lee,52,5,fd);
	  if (lee[4].capturas<puntos)
	  {
		for (i=4;i>-1;i--)
		{
		   if (lee[i-1].capturas<puntos)
		   {
			 strcpy (lee[i].nombre,lee[i-1].nombre);
			 lee[i].capturas=lee[i-1].capturas;
		   }
		   else
		   {
			 printf ("\n\n\n\t\tHAS OBTENIDO UNA PUNTUACI¢N ALTA");
			 printf ("\n\n\nIntroduce tu nombre: ");
			 fflush (stdin);
			 gets (lee[i].nombre);
			 fflush (stdin);
			 lee[i].capturas=puntos;
			 puntos=-10;//para que no entre mas
			 fseek(fd,0,SEEK_SET);
			 fwrite(lee,52,5,fd);
			 fflush (fd);
			 fclose (fd);
			 records();
			 fcloseall();
			 flushall();
			 i=-4; //para que no entre m†s
		   }
		}
	  }
    }
    else
    {
	  fclose(fd);
	  fd=fopen("record.jav","wb");
	  printf ("\n\n\n\t\tHAS OBTENIDO UNA PUNTUACI¢N ALTA");
	  printf ("\n\n\nIntroduce tu nombre: ");
	  fflush (stdin);
	  gets (lee[0].nombre);
	  fflush (stdin);
	  lee[0].capturas=puntos;
	  for (i=1;i<5;i++)
	  {
	  strcpy (lee[i].nombre,nombre);
		lee[i].capturas=0;
	  }
	  fwrite (lee,52,5,fd);
       fflush (fd);
       fclose (fd);
       flushall();
       fcloseall ();
       records();
    }
    free (nombre);
    flushall();
    fcloseall ();
}