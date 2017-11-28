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
void nosRamo(No *arvore);
void noFolha(No *arvore);

int alturaArvore(No *arvore);
int maior(int a, int b);

void grau(No *arvore);

#endif