#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include "grafos.h"

int main(int argc, char *argv[]) {

	int lin, col, v,r,r1;
	printf("Digite quantidade de vertices: ");
	scanf("%d", &v);
	lin=v;
	col=v;
	
	MatrizDinamica m1;
	
	printf("Eh o grafo da avaliacao?? (1-SIM / 0-NAO)");
	scanf("%d",&r1);
	
	if(r1==0){
	

	if (inicializa_matriz(&m1, lin, col) == ERRO_COORDENADA_INVALIDA){
		printf("Erro!\n");
	}
	else{
		
		
			for(lin=0;lin<v;lin++){
				for(col=0;col<v;col++){
					printf("Digite um valor para a coordenada %d %d\n",lin+1,col+1);
					scanf("%d",&r);
					modifica_valor_matriz(&m1, lin, col, r);
				}
			}
	
		mostra_matriz(m1);
	}
	}else{
		if (inicializa_matriz(&m1, lin, col) == ERRO_COORDENADA_INVALIDA){
		printf("Erro!\n");
	}
	else{
		modifica_valor_matriz(&m1, 0, 1, 1);
		modifica_valor_matriz(&m1, 0, 2, 1);
		modifica_valor_matriz(&m1, 0, 3, 1);
		modifica_valor_matriz(&m1, 1, 0, 1);
		modifica_valor_matriz(&m1, 1, 4, 1);
		modifica_valor_matriz(&m1, 2, 0, 1);
		modifica_valor_matriz(&m1, 2, 5, 1);
		modifica_valor_matriz(&m1, 2, 6, 1);
		modifica_valor_matriz(&m1, 3, 0, 1);
		modifica_valor_matriz(&m1, 3, 5, 1);
		modifica_valor_matriz(&m1, 4, 1, 1);
		modifica_valor_matriz(&m1, 4, 6, 1);
		modifica_valor_matriz(&m1, 5, 2, 1);
		modifica_valor_matriz(&m1, 5, 3, 1);
		modifica_valor_matriz(&m1, 5, 7, 1);
		modifica_valor_matriz(&m1, 6, 2, 1);
		modifica_valor_matriz(&m1, 6, 5, 1);
		modifica_valor_matriz(&m1, 7, 5, 1);
		
		mostra_matriz(m1);
	}
	}
	
	
	
	int *vs; 
  	int b;
  	
  	vs=(int*)malloc(v*sizeof(int));
  	
  	for (b=0;b<v;b++){
    	vs[b]=0;
  	}
  	
  	int *va; 
  	int w;
  	
  	va=(int*)malloc(v*sizeof(int));
  	
  	for (w=0;w<v;w++){
    	va[w]=0;
  	}
	
	Pilha a1;
	Fila f1;
	int ini,y,x,i,fin;
	bool ACHOU;
	
	/*inicializa_fila(&f1,v);
	
	printf("Digite o vertice inicial: \n");
	scanf("%d",&ini);
	printf("Digite o vertice final: \n");
	scanf("%d",&fin);
	
	vs[ini-1]=1;
	inserir(&f1,ini);
	ACHOU=false;
	
	while(!fila_vazia(f1) && !ACHOU){
		remover(&f1,&x);
		if(x==fin){
			ACHOU=true;
		}
		for(i=0;i<v+1;i++){
			le_valor_matriz(m1,x-1,i-1,&y);
				if(y==1){
					if(vs[i-1]==0){
						vs[i-1]=1;
						va[i-1]=x;
						inserir(&f1,i);	
				}
			}	
		}
	}
	if(ACHOU==true){
		inicializa_pilha(&a1,v);
			while(x!=0){
				empilha(&a1,x);
				x=va[x-1];
			}
			while(!pilha_vazia(a1)){
				desempilha(&a1,&x);
				printf("---------\n%d\n",x);
			}
	}else{
		printf("%d nao eh alcancavel a partir de %d",fin,ini);
	}
	*/
	
	inicializa_pilha(&a1, v*4);
	
	printf("Digite o vertice de busca: \n");
	scanf("%d",&ini);
	
	empilha(&a1,ini);
	
	while(!pilha_vazia(a1)){
	
		desempilha(&a1,&x);
		if(vs[x-1]==0){
			printf("---------\n%d\n",x);
			vs[x-1]=1;
			for(i=0;i<v+1;i++){
				le_valor_matriz(m1,x-1,i-1,&y);
					if(y==1){
						if(vs[i-1]==0){
							empilha(&a1, i);
						
							
					}
				}	
			}
		}
				
	}	
	


	
	free(vs);
	desaloca_matriz(&m1);
	desaloca_pilha(&a1);
	desaloca_Fila(&f1);
	

	
	return 0;
}

