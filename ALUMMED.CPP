#include <conio.h>
#include <stdio.h>
#include <string.h>

struct tipo1
{
  char nombre[10];
  char apellido[10];
  char curso[10];
  int num;
  int exp;
};

struct tipo2
{
  int exp;
  float not1;
  float not2;
  float not3;
};

int buscar(struct tipo1 alumno[],char curso[],int num);
void media(struct tipo2 notas[],int exp);

void main()
{
  char curso[10];
  int num,exp;
  struct tipo1 alumno[6]={"Pepe","Leon","1§ asi",2,5,
		                                 "Maria","Magdalena","3§ asi",1,3,
						  "Juan","Garcia","2§ asi",3,4,
						  "Luis","LLana","1§ asi",5,2,
						  "Eva","Maria","2§ asi",4,6,
						  "Fany","Torrente","3§ asi",6,1};
  struct tipo2 notas[6]={5,5.5,7.5,9,
						 4,3.2,4.3,2.2,
						 2,6.8,5.9,7,
						 3,3.4,6.5,8.9,
						 1,1.1,2.5,3.3,
						 6,9,10,10};
  clrscr();
  gotoxy(10,10);
  printf("INTRODUZCA EL CURSO DEL ALUMNO: ");
  gets(curso);
  gotoxy(10,14);
  printf("INTRODUZCA EL NUMERO DEL ALUMNO: ");
  scanf("%d",&num);
  exp=buscar(alumno,curso,num);
  if(exp==-1)
  {
	gotoxy(10,10);
	printf("EL ALUMNO NO EXISTE O NO HA INTRODUCIDO BIEN LOS DATOS");
  }
  else
    media(notas,exp);
  getch();
}

int buscar(struct tipo1 alumno[],char curso[],int num)
{
  int i,exp;
  clrscr();
  for(i=0;i<6;i++)
  {
	if(strcmp(curso,alumno[i].curso)==0 && num==alumno[i].num)
	{
	  exp=alumno[i].exp;
	  return(exp);
	}
  }
  return(-1);
}
void media(struct tipo2 notas[],int exp)
{
 int i;
 float notmed;
 clrscr();
 for(i=0;i<6;i++)
 {
   if(notas[i].exp==exp)
   {
	 notmed=(notas[i].not1+notas[i].not2+notas[i].not3)/3;
	 gotoxy(10,10);
	 printf("1¦ NOTA: %.1f",notas[i].not1);
	 gotoxy(10,12);
	 printf("2¦ NOTA: %.1f",notas[i].not2);
	 gotoxy(10,14);
	 printf("3¦ NOTA: %.1f",notas[i].not3);
	 gotoxy(10,17);
	 printf("LA MEDIA DEL ALUMNO ES %.1f",notmed);
   }
 }
}