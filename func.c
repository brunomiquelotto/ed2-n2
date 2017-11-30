#include <stdio.h>
#include <stdlib.h>
#include "func.h"


void inicializa (No **arvore) {
	*arvore = NULL;
}

void inserir (No **arvore, int IdInclusao) {
	No *novo;   
	No *atual;                
	No *pai;    

	novo = (No*) malloc (sizeof(No));

	novo->Id = IdInclusao;
	novo->pai = NULL;
	novo->esq = NULL;
	novo->dir = NULL;

	if (estaVazia(*arvore))
		*arvore = novo;
	else {        
		atual = *arvore;
		while (atual != NULL) {
			pai = atual;
			if (IdInclusao < atual->Id)
				atual = atual->esq;   
			else
				atual = atual->dir;  
		} 
		novo->pai = pai;
		if (IdInclusao < pai->Id)
			pai->esq = novo;   
		else
			pai->dir = novo;    
	} 
} 

int estaVazia (No* lista) {
	return (lista == NULL);
}

void preOrdem (No *arvore) {
	if (arvore != NULL) {
		printf("%d ", arvore->Id); 
		preOrdem(arvore->esq);    
		preOrdem(arvore->dir);     
	}
}

void posOrdem (No *arvore) {
	if (arvore != NULL) { 
		posOrdem(arvore->esq);    
		posOrdem(arvore->dir);    
		printf("%d ", arvore->Id); 
	}
}

void emOrdem (No *arvore) {
	if (arvore != NULL) {
		emOrdem(arvore->esq);        
		printf("%d ", arvore->Id);   
		emOrdem(arvore->dir);      
	}
}

int ehRaiz(No *arvore){
	No* atual = arvore;
	if(!estaVazia(atual) && atual->pai == NULL)
		return atual->Id;
	return 0;
}

void printRaiz(No *arvore) {
	if (!ehRaiz(arvore)) return;
	printf("%d\n", arvore->Id);
}

void nosRamo (No *arvore){
	No* atual = arvore;
	if(estaVazia(atual)) return; 

	if(atual->pai != NULL && (atual->dir != NULL || atual->esq != NULL)){
		printf("%d ",  atual->Id);		
	}
	nosRamo(atual->esq);
	nosRamo(atual->dir);
} 

void noFolha (No *arvore){
	No* atual = arvore;
	if(estaVazia(atual)) return; 

	if(atual->dir == NULL && atual->esq == NULL){
		printf("%d ",  atual->Id);		
	}
	noFolha(atual->esq);
	noFolha(atual->dir);
} 
int maior(int a, int b) {
	return a > b ? a : b;
}

int alturaArvore(No *arvore){
	No* atual = arvore;
	if(estaVazia(atual)) return 0; 

	if(atual->dir == NULL && atual->esq == NULL) return 0;

	return maior(alturaArvore(atual->esq), alturaArvore(atual->dir)) + 1;
}

int profundidadeArvore(No *arvore) {
	return alturaArvore(arvore);
}

int grauArvore(No* arvore, int max) {
	No* atual = arvore;
	if (max == 2) return max;
	if (estaVazia(atual)) return 0;
	if (atual->esq == NULL && atual->dir == NULL) return max;
	if (atual->esq != NULL && atual->dir != NULL) return 2;
	if (atual->esq != NULL) return maior(grauArvore(atual->esq, 1), max);
	return maior(grauArvore(atual->dir, 1), max);
}

int alturaNo(No *node){
	return 1;
}

int profundidadeNo(No *node){
	return 1;
}

int grauNo(No *node){
	No* atual = node;
	if (atual->esq != NULL && atual->dir != NULL) return 2;
	if (atual->esq != NULL || atual->dir != NULL) return 1;
	return 0;
}

int nivelNo(No *node){
	No* atual = node;
	if (atual->pai) return nivelNo(atual) + 1;
	return 1;
}

int ancestral(No *arvore, int noPesquisa, int achou){
	
	if(arvore != NULL && arvore->Id != noPesquisa){
		if(arvore->Id > noPesquisa)
		achou = ancestral(arvore->esq, noPesquisa, achou);
		else
		achou = ancestral(arvore->dir, noPesquisa, achou);
	}
	
	if(arvore->Id == noPesquisa)
	return 1;    
	
	if(achou)
	printf("%d ", arvore->Id);
	
	return achou; 
}


void descendente(No *arvore, int noPesquisa){
	
	if(arvore != NULL && arvore->Id != noPesquisa){
		if(arvore->Id > noPesquisa)
		descendente(arvore->esq, noPesquisa);
		else
		descendente(arvore->dir, noPesquisa);
	}
	
	if(arvore->Id == noPesquisa){
		preOrdem(arvore);
	}

	return;
}