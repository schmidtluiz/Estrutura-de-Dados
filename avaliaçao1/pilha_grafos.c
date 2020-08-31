#include "grafos.h"
#include <stdio.h>
#include <stdlib.h>

void inicializa_pilha (Pilha *a, int c){
   a->d=malloc(sizeof(int) * c);
   a->cap=c;
   a->t=-1;
}

int pilha_vazia (Pilha a){
   return a.t==-1;
}

int pilha_cheia (Pilha a){
   return a.t==a.cap - 1;
}

int empilha (Pilha *a, int inf){
   if( pilha_cheia (*a))
      return ERRO_PILHA_CHEIA;

   a->t++;
   a->d[a->t]=inf;
   return 1; 
}

int desempilha (Pilha *a,int *inf){
   if (pilha_vazia (*a))
      return ERRO_PILHA_VAZIA;

   *inf=a->d[a->t];
   a->t--;
   return 1;
}

int mostra_pilha (Pilha a){
   if( pilha_vazia (a))
      printf("Pilha vazia!\n");
   else{
      printf("Dados da Pilha:\n");
      int i;
      for(i=0;i<=a.t;i++)
         printf("%d\n", a.d[i]);
   }
}

void desaloca_pilha(Pilha *a){
	free(a->d);
}



