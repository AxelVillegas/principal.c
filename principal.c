#include<stdio.h>
#include<stdlib.h>

typedef struct vehiculo{
  char placa[10];
  char motor[20];
  char marca[20];
  char submarca[20];
  char anio[4];
  char propietario[50];
  struct vehiculo *sig;
  struct vehiculo *multas;
}VEH;

extern void agregar_v(VEH **inicio_v, VEH **aux_v);
extern void borrar_v(VEH *inicio_v);

int main(void)
{
  FILE *fp;
  VEH *inicio_v, *aux_v, *nodo;
  int menu=0;//menu es la variable del ciclo del menu
  inicio_v==NULL;
  fp=fopen("datos.bin","r+b");
  if(fp!=NULL){
    while(fp!=NULL){
      nodo=malloc(sizeof(VEH));
      fread(nodo,sizeof(VEH),1,fp);
      if(inicio_v==NULL){
	inicio_v=nodo;
	aux_v=inicio_v;
      }
      else{
	aux_v->sig=nodo;
	aux_v=nodo;
      }
    }
  }
  while(menu==0){
    printf("Menu:\n1-Agregar un vehiculo.\n2-Agregar una multa.\n");
    printf("3-Buscar vehiculo.\n4-Borrar vehiculo\n");
    printf("5-Borrar una multa.\n6-Salir.\n");
    scanf("%d",&menu);
    getchar();
    fflush(stdin);
    if(menu<1||menu>6){
      printf("Numero ingresado invalido, cerrando programa..");
      exit(1);
    }
    else if(menu==1){
      agregar_v(&inicio_v,&aux_v);
      menu=0;
    }
    else if(menu==4){
      borrar_v(inicio_v);
      menu=0;
    }
  }
}
