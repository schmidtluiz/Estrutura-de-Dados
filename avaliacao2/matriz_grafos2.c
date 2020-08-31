#include "grafos2.h"
#include <stdio.h>
#include <stdlib.h>

int inicializa_matriz(MatrizDinamica *p, int l, int c){
    int i, j;
    
	p->m = malloc(l * sizeof(int*) );
	if(p->m == NULL)
		return 0; // Faltou memória...
	for(i=0; i<l; i++){
		p->m[i] = malloc(c * sizeof(int) );
		if(p->m[i] == NULL)
	   		return 0; // Faltou memória...
	}

	p->lin = l;
	p->col = c;

	for(i=0; i<l; i++)
		for(j=0; j<c; j++)
			p->m[i][j] = 0;
	
	return 1; // Sucesso
}

void desaloca_matriz(MatrizDinamica *p){
	int i;
	for(i=0; i<p->lin; i++)
		free(p->m[i]);
	free(p->m);
}

void mostra_matriz(MatrizDinamica x){
	int i, j;
	for(i=0; i<x.lin; i++){
		for(j=0; j<x.col; j++)
			printf("%4d ", x.m[i][j]);
		printf("\n");
	}
	printf("_________________________________\n\n");
}

int modifica_valor_matriz(MatrizDinamica *p, int i, int j, int valor){
	if(i >= p->lin || j >= p->col)
		return ERRO_COORDENADA_INVALIDA;
	
	p->m[i][j] = valor;
	return 1; // Sucesso;
}

int le_valor_matriz(MatrizDinamica x, int i, int j, int *pValor){
	if(i >= x.lin || j >= x.col)
		return ERRO_COORDENADA_INVALIDA;
	
	*pValor = x.m[i][j];
	return 1; // Sucesso;
}

