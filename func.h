#ifndef FUNC_H
#define FUNC_H

typedef struct _no {
    int Id;              
    struct _no *pai;    
    struct _no *esq;    
    struct _no *dir;    
} No;


void inicializa (No **arvore);
int estaVazia (No *arvore);

void preOrdem (No *arvore);
void posOrdem (No *arvore);
void emOrdem (No *arvore);

void inserir (No **arvore, int IdInclusao);
void pesquisar (No *arvore, int IdPesquisar);

int ehRaiz(No *arvore);
void printRaiz(No *arvore);
void nosRamo(No *arvore);
void noFolha(No *arvore);

int alturaArvore(No *arvore);
int profundidadeArvore(No *arvore);
int grauArvore(No *arvore, int max);

int alturaNo(No *arvore, int numero);
int profundidadeNo(No *arvore, int numero);
int grauNo(No *arvore, int numero);
int nivelNo(No *arvore, int numero);

void ancestral(No *arvore, int noPesquisa);
void descendente(No *arvore, int noPesquisa);

int maior(int a, int b);

int existeNo(No *arvore, int noPesquisa);

#endif