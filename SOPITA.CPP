#include <conio.h>
#include <stdio.h>
#include <string.h>

#define N 5

struct tipo
{
  char marca[11];
  int fila;
  int columna;
  int sentido;
  int acierto;
};

void dibuja(struct tipo tabla[], int k, int fallos);

void main()
{
 char sopa[10][20]={"a e f g i m o r s v",
		    "t m p t p f p k a t",
		    "m a v g r r e v o r",
		    "a j c h a s l e n z",
		    "d k i s u b t q u j",
		    "q w l b g t k n h v",
		    "u f s e a t j n n t",
		    "l l r m j w o o i p",
		    "i z n h m r t e h h",
		    "p i r a r r e f q o"};
  int i,j,k,fallos=0,acierto=0,intentos=3,pasoaqui;
  char palabra[11];
  //j=columna,i=fila//
  struct tipo tabla[N]={"opel",3,42,2,0,
			"ferrari",12,44,4,0,
			"rover",5,48,4,0,
			"seat",9,34,3,0,
			"jaguar",10,38,1,0};
  clrscr();
  for(i=0;i<10;i++)
  {
    for(j=0;j<19;j++)
    {
      textcolor(YELLOW);
      gotoxy(j+30,i+3);
      cprintf("%c",sopa[i][j]);
    }
  }

  while(fallos!=3 && acierto!=5)
  {
    textcolor(WHITE);
    gotoxy(2,15);
    cprintf("INTRODUZCA UNA PALABRA: ");
    textcolor(WHITE);
    scanf("%s",palabra);
    fflush(stdin);
    pasoaqui=0;
    for(k=0;k<N;k++)
    {
      if(strcmp(palabra,tabla[k].marca)==0)
      {
	if(tabla[k].acierto==1)
	{
	  textcolor(GREEN);
	  cprintf("\n\n LA PALABRA %s YA FUE ENCONTRADA ANTES",palabra); //no se cuenta como fallo
	}
	else
	{
	  tabla[k].acierto=1;
	  acierto++;
	  dibuja(tabla, k, fallos);
	}
      pasoaqui=1;
      break;
      }
    }
    if(pasoaqui!=1)
    {
      intentos--; //solo para visualizar los intentos que quedan
      textcolor(RED);
      cprintf("\n HA FALLADO LA PALABRA NO ESTA EN LA SOPA, si fallas %d mas pierdes", intentos);
      fallos++;
    }
  }
  if(fallos==3)
  {
    for(k=0;k<N;k++)
    {
      if(tabla[k].acierto==0)
	dibuja(tabla, k, fallos);
    }
    gotoxy(10,30);
    printf("\Pulsa una tecla para terminar(arriba las palabras que no acertaste)");
    getch();
    clrscr();
    gotoxy(10,9);
    textcolor(YELLOW);
    cprintf("*******************************************************");
    gotoxy(10,10);
    textcolor(YELLOW);
    cprintf("HAS PERDIDO, vete al oculista o aprende a leer, zoquete");
    gotoxy(10,11);
    textcolor(YELLOW);
    cprintf("*******************************************************");
  }
  if(acierto==N)
  {
    gotoxy(2,20);
    textcolor(GREEN);
    cprintf("­­­FELICIDADES, eres un campe¢n, las acertastes todas HAS GANADO!!!");
  }
  getch();
}

void dibuja(struct tipo tabla[], int k, int fallos)
{
  int l=0;
  if(fallos<3)
    textcolor(GREEN);
  else
    textcolor(RED);
  while(tabla[k].marca[l]!='\0')
  {
    gotoxy(tabla[k].columna,tabla[k].fila);
    cprintf("%c",tabla[k].marca[l]);
    switch(tabla[k].sentido)
    {
      case 1:
	l++;
	tabla[k].fila--;
	break;
      case 2:
	l++;
	tabla[k].fila++;
	break;
      case 3:
	l++;
	tabla[k].columna+=2;
	break;
      case 4:
	l++;
	tabla[k].columna-=2;
	break;
    }
  }
  textcolor(WHITE);
}