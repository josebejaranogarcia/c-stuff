#include <conio.h>
#include <stdio.h>
#include <alloc.h>

struct lista * delante(struct lista *inicio);
struct lista * detras(struct lista *inicio);
void visualiza(struct lista *inicio);
struct lista * borrar(struct lista *inicio);
void buscar(struct lista *inicio);
struct lista * ordenar(struct lista *inicio);
struct lista * insord(struct lista *inicio);
void burbu(struct lista *inicio);

struct lista
{
  int num;
  struct lista *sig;
};

void main(void)
{
  struct lista *inicio=NULL;
  int op=0;
  do
  {
    clrscr();
    gotoxy(10,3);
    printf("MENU");
    gotoxy(8,6);
    printf("1.-INSERTAR POR DELANTE");
    gotoxy(8,8);
    printf("2.-INSERTAR POR DETRAS");
    gotoxy(8,10);
    printf("3.-VISUALIZAR LISTA");
    gotoxy(8,12);
    printf("4.-ELIMINAR ELEMENTO DE LA LISTA");
    gotoxy(8,14);
    printf("5.-BUSCAR ELEMENTO EN LA LISTA");
    gotoxy(8,16);
    printf("6.-ORDENAR LISTA POR ELEMENTOS");
    gotoxy(8,18);
    printf("7.-INSERTAR ELEMENTO EN ORDEN");
    gotoxy(8,20);
    printf("8.-ORDENAR POR EL METODO DE LA BURBUJA");
    gotoxy(8,22);
    printf("9.-SALIR");
    gotoxy(8,25);
    printf("ELIJA UNA OPCION: ");
    scanf("%d",&op);
    switch(op)
    {
      case 1:
	inicio=delante(inicio);
	break;
      case 2:
	inicio=detras(inicio);
	break;
      case 3:
	visualiza(inicio);
	break;
      case 4:
	inicio=borrar(inicio);
	break;
      case 5:
	buscar(inicio);
	break;
      case 6:
	inicio=ordenar(inicio);
	break;
      case 7:
	inicio=insord(inicio);
	break;
      case 8:
	burbu(inicio);
	break;
    }
  }while(op!=9);
  getch();
}

struct lista * delante(struct lista *inicio)
{
  struct lista *aux;
  aux=(struct lista *)malloc(sizeof(struct lista));
  clrscr();
  printf("INTRODUZCA UN NUMERO: ");
  scanf("%d",&aux->num);
  aux->sig=NULL;
  if(inicio==NULL)
    inicio=aux;
  else
  {
    aux->sig=inicio;
    inicio=aux;
  }
  return(inicio);
}

struct lista * detras(struct lista *inicio)
{
  struct lista *aux,*ultimo;
  aux=(struct lista *)malloc(sizeof(struct lista));
  aux->sig=NULL;
  if(inicio==NULL)
    inicio=aux;
  else
  {
    ultimo=inicio;
    while(ultimo->sig!=NULL)
    {
      ultimo=ultimo->sig;
    }
  }
  ultimo->sig=aux;
  clrscr();
  printf("INTRODUCE UN NUMERO:  ");
  scanf("%d",&aux->num);
  return(inicio);

}
void visualiza(struct lista *inicio)
{
  int cont=1;
  struct lista *aux;
  if(inicio==NULL)
  {
    clrscr();
    printf("LA LISTA ESTA VACIA");
    getch();
    return;
  }
  else
  {
    clrscr();
    aux=inicio;
    while(aux->sig!=NULL)
    {
      printf("\n\n ELEMENTO %d: %d",cont,aux->num);
      aux=aux->sig;
      cont++;
    }
    if(aux->sig==NULL)
      printf("\n\n ELEMENTO %d: %d",cont,aux->num);
    getch();
  }
}

struct lista * borrar(struct lista *inicio)
{
  int elem;
  struct lista *ant,*aux;
  clrscr();
  if(inicio==NULL)
  {
    clrscr();
    printf("LA LISTA ESTA VACIA, NO HAY ELEMENTOS QUE BORRAR");
    getch();
    return(inicio);
  }
  printf("INTRODUZCA EL ELEMENTO QUE DESEA ELIMINAR: ");
  scanf("%d",&elem);
  ant=aux=inicio;
  while(aux->num!=elem && aux->sig!=NULL)
  {
    if(aux==inicio)
      aux=aux->sig;
    else
    {
      aux=aux->sig;
      ant=ant->sig;
    }
  }
  if(aux->num==elem)
  {
    if(aux==inicio)
    {
      inicio=aux->sig;
      free(aux);
      free(ant);
    }
    else
    {
      ant->sig=aux->sig;
      free(aux);
    }
    clrscr();
    printf("ELEMENTO ELIMINADO");
    getch();
    visualiza(inicio);
    return(inicio);
  }
  else
  {
    clrscr();
    printf("EL NUMERO QUE DESEA BORRAR NO EXISTE EN LA LISTA");
    getch();
    return(inicio);
  }
}

void buscar(struct lista *inicio)
{
  int elem,cont=0;
  struct lista *ant,*aux;
  clrscr();
  if(inicio==NULL)
  {
    printf("LA LISTA ESTA VACIA, NO HAY NADA QUE BUSCAR");
    return;
  }
  printf("INTRODUZCA EL ELEMENTO QUE DESEA BUSCAR: ");
  scanf("%d",&elem);
  ant=aux=inicio;
  while(aux->num!=elem && aux->sig!=NULL)
  {
    if(aux==inicio)
    {
      aux=aux->sig;
      cont++;
    }
    else
    {
      cont++;
      aux=aux->sig;
      ant=ant->sig;
    }
  }
  if(aux->num==elem)
    cont++;
  else
  {
    clrscr();
    printf("EL ELEMENTO QUE USTED BUSCA NO EXISTE EN LA LISTA");
    getch();
    return;
  }
  clrscr();
  printf("EL ELEMENTO %d ESTA EN LA POSICION %d",elem,cont);
  getch();
  return;
}

struct lista * ordenar(struct lista *inicio)
{
  struct lista *ant,*aux,*ult;
  aux=(struct lista *)malloc(sizeof(struct lista));
  aux->sig=NULL;
  ant=ult=inicio;
  ult=ult->sig;
  while(ant->sig!=NULL)
  {
    if(ult->num<ant->num)
    {
     aux->num=ult->num;
     ult->num=ant->num;
     ant->num=aux->num;
     ant=inicio;
     ult=ant->sig;
    }
    else
    {
     ant=ant->sig;
     ult=ult->sig;
    }
  }
  clrscr();
  printf("LA LISTA HA SIDO ORDENADA");
  getch();
  free(aux);
  visualiza(inicio);
  return(inicio);
}

struct lista * insord(struct lista *inicio)
{
  struct lista *aux, *ant, *ult;
  aux=(struct lista *)malloc(sizeof(struct lista));
  clrscr();
  printf("INTRODUZCA UN NUMERO: ");
  scanf("%d",&aux->num);
  aux->sig=NULL;
  if(inicio==NULL)
  {
    inicio=aux;
    return(inicio);
  }
  else
  {
    ult=ant=inicio;
    while(ult->num<aux->num && ult!=NULL)
    {
      if(ult==inicio)
	ult=ult->sig;
      else
      {
	ant=ant->sig;
	ult=ult->sig;
      }
    }
    if(ult==inicio)
    {
      aux->sig=inicio;
      inicio=aux;
    }
    else if(ult==NULL)
      ant->sig=aux;
    else
    {
      ant->sig=aux;
      aux->sig=ult;
    }
  }
  visualiza(inicio);
  return(inicio);
}

void burbu(struct lista *inicio)
{
  int n=0,i,j;
  struct lista *aux, *ant, *ult;
  aux=(struct lista *)malloc(sizeof(struct lista));
  aux->sig=NULL;
  ult=ant=inicio;
  if(inicio==NULL)
  {
    clrscr();
    printf("LA LISTA ESTA VACIA, NO HAY NADA QUE ORDENAR");
    return;
  }
  while(ult->sig!=NULL)
  {
    ult=ult->sig;
    n++;
  }
  for(i=0;i<n;i++)
  {
     ult=ant=inicio;
     ult=ult->sig;
     for(j=0;j<n;j++)
     {
       if(ant->num>ult->num)
       {
	 aux->num=ult->num;
	 ult->num=ant->num;
	 ant->num=aux->num;
       }
       ult=ult->sig;
       ant=ant->sig;
     }
  }
  free(aux);
  visualiza(inicio);
  return;
}
























