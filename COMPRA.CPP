#include <conio.h>
#include <stdio.h>

#define N 6

struct tipo1
{
  int cliente;
  float total;
};

struct tipo2
{
  int cliente;
  float precio;
};


void visualiza(int client,struct tipo2 clientes[],struct tipo1 compra[]);


void main()
{
  int client,k;
  struct tipo2 clientes[N]={3,382.15,
			    1,167.70,
			    2,213.61,
			    3,189.15,
			    2,122.88,
			    1,57.5};

  struct tipo1 compra[1];
  clrscr();
  textcolor(YELLOW);
  gotoxy(6,6);
  cprintf("INTRODUZCA EL CLIENTE: ");
  textcolor(WHITE);
  scanf("%d",&client);
  visualiza(client, clientes, compra);
  getch();
}

void visualiza(int client,struct tipo2 clientes[N],struct tipo1 compra[])
{
 int i,cont=0;
 clrscr();

 for(i=0;i<N;i++)
 {
   if(clientes[i].cliente==client)
   {
     compra[0].cliente=client;
     compra[0].total=compra[0].total+clientes[i].precio;
     cont++;
   }
 }
 if(cont==0)
 {
   gotoxy(20,10);
   textcolor(RED);
   cprintf("EL CLIENTE NO EXISTE");
   textcolor(WHITE);
 }
 else
 {
   textcolor(GREEN);
   gotoxy(3,10);
   cprintf("EL CLIENTE %d ha realizado %d compras cuyo total es: %.2f",client,cont,compra[0].total);
   textcolor(WHITE);
 }
 getch();
}