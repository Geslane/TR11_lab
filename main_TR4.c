#include <stdio.h>
#include <stdlib.h>
#include "ordvetor.h"

//funcao compara
int compara(void* x, void* y) {
	int xx = *((int*) x);
	int yy = *((int*) y);

	if(xx > yy ){
		return -1;
	}else{
		if(xx < yy ) return 1;
		else return 0;
	}
}	

//funcao para imprimir os elementos do vetor

void print(void** vetor, int fim){
	for (int indice = 0; indice < fim ; indice++) {
		printf("%d - ", *((int*) vetor[indice]));
	}
	printf("\n\n");
}

int main() {
	
	int tam = 10; int remove = 3;
	
	// criando vetor
	
	VETORORD* vetor = VETORD_create(tam, compara);


	// iniciando vetor com numeros aleatorios
	//imprimir os valores
	
	printf("VETOR NAO ORDENADO:\n");
	
	for (int indice = 0; indice < tam; indice++) {
	
		int * x = malloc(sizeof(int));
		*x = rand() % tam;
		VETORD_add(vetor, x);
		
		printf("%d - ", *x);
	}
	printf("\n\n");
	
	//imprimir o vetor inicial ordenado
	
	printf("VETOR INICIAL DE TAMANHO %d:\n", vetor->P);
	print(vetor->elems, vetor->P);
	
	//imprimir os elementos a serem removidos e remover
	
	printf("REMOVIDOS:\n");
	print(vetor->elems, remove);
	
	for (int indice = 0; indice < remove; indice++) {
		VETORD_remove(vetor);
	}

	//imprimir o vetor final
	
	printf("VETOR FINAL DE TAMANHO %d:\n", vetor->P);
	print(vetor->elems, vetor->P);

	return 0;
}
