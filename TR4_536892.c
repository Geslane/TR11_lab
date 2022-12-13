#include <stdio.h>
#include <stdlib.h>
#include "ordvetor.h"

VETORORD* VETORD_create(int n, COMP* compara){		/*recebe como parametro o tamanho do vetor e a funcao campara,retorna um
								ponteiro para uma estrutura VETORORD*/
	VETORORD*vetor = malloc(sizeof(VETORORD));		
	vetor->N = n;	//tamanho do vetor
	vetor->P = 0;  //quantidade de elementos
	vetor-> elems = malloc(n * sizeof(void*));
	vetor->comparador = compara;

	return vetor;
}

void VETORD_add(VETORORD* vetor, void* newelem){		/*Adiciona o elemento newelem ao vetor ordenado se houver espaço; recebe
								 como parametro o vetor que irá receber o novo elemento e o novo elemento*/
	if(vetor->P < vetor->N){
					
		int posicao_newelem = vetor->P;				//variavel que ficara a posicao do newelem
		
		for (int indice = 0 ; indice < vetor->P ; indice ++){
		
			if (vetor->comparador( vetor->elems[indice], newelem) == -1){  //encontrar a posicao que o elemento ficara
			
				posicao_newelem = indice;
				break;
			}
		}
		for(int indice = vetor->P ; indice > posicao_newelem; indice--){
		
			vetor->elems[indice] = vetor->elems[indice - 1];	//alocando os elementos
		}
		
		vetor->elems[posicao_newelem] = newelem;			//adicionar o novo elemento
		vetor->P++;
	}
}

void* VETORD_remove(VETORORD* vetor){				/*remover o menor elemento do vetor, recebe como parametro o vetor que tera
 								o elemento removido e retorna esse elemento*/
	void* menor = vetor->elems[0];	
			
	for(int indice = 0; indice < vetor->P - 1; indice++){
	
		vetor->elems[indice]=vetor->elems[indice+1];
	}
	vetor->P--;
	
	return menor;
}

