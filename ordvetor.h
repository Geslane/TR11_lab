#include <stdio.h>
#include <stdlib.h>

#ifndef ORDVETOR_H
#define ORDVETOR_H

/*funcao comparacao:
Esta funcao recebe dois valores x e y e retorna

1 : se x e menor que y.
0 : se x e equivalente a y.
-1: se x e maior que y na ordem.

*/
typedef int COMP(void* x, void* y);

/*Vetor ordenado estatico. Os elementos do vetor estao colocados no vetor
de acordo com a ordem indicada pelo comparador.*/

typedef struct vet{
	int N;	//tamanho do vetor
	int P;	//numero de elementos no vetor
	void** elems;	//o vetor de elementos
	COMP* comparador;	//a funcao de comparacao
}VETORORD;

/*
Cria um vetor ordernado vazio de tamanho n e com funcao de comparacao compara

@param n: o tamanho do vetor
@param compara: a funcao de comparacao

@return um ponteiro(que aponta para a estrutura) para uma estrutura VETORORD.
*/
VETORORD* VETORD_create(int n, COMP* compara);

/*
Adiciona o elemento newelem ao vetor ordenado, na posicao correta e se for possível
ainda incluir o elemento (se existe espaco no vetor).

@param vetor: o vetor ordenado a ter o elemento incluído
@param newelem: o elemento a ser adicionado
*/
void VETORD_add(VETORORD* vetor, void* newelem);

/*
Remove o menor elemento do vetor, de acordo com a funcao compara.

@param vetor: o vetor a ter seu elemento removido

@return um ponteiro para o elemento que foi removido do vetor.
*/
void* VETORD_remove(VETORORD* vetor);

#endif
