#include <stdio.h>
#include <stdlib.h>
#include "func.h"


int estaVazia (NoLista* lista) {

    return (lista == NULL);

}

void ehRaiz(No *arvore){

	No* atual = arvore;

	if(!ehVazia(atual) && atual->pai == NULL)
		return atual->Id;
}