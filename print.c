#include <stdio.h>
#include "print.h"
#include "func.h"
#ifndef PRINT_H
#define PRINT_H

void printGrafo() {
    printf("\nPrinting Grafo to screen..............");
}

void printGrafoInfo() {
    printf("\nPrinting Grafo info to screen..............");
}

void printTree(No* arvore) {
    No *atual = arvore;
    if (atual == NULL) return;
    printf(" %d", atual->Id);
    if (atual->esq != NULL || atual->dir != NULL) {
        printf(" (");
        printTree(atual->esq);
        printTree(atual->dir);
        printf(" )");
    }
}


void printTreeInfo(No* arvore) {
    printf("No raiz: ");
    printRaiz(arvore);

    printf("Nos ramos: ");
    nosRamo(arvore);
    printf("\n");

    printf("Nos folha: ");
    noFolha(arvore);
    printf("\n");

    printf("Grau arvore: %d\n", grauArvore(arvore,0));

    printf("Altura arvore: %d\n", alturaArvore(arvore));

    printf("Profundidade arvore: %d\n", profundidadeArvore(arvore));
    //ancestrais dependentes determinado nó
    printf("Ancestrais: %d\n", ancestral(arvore,44,0));
    printf("Descendentes: %d\n", descendente(arvore,44));

    //grau, altura, profundidade, nivel de um nó
    
    printf("Pre ordem: ");
    preOrdem(arvore);
    printf("\n");

    printf("Pos ordem: ");
    posOrdem(arvore);
    printf("\n");

    printf("Em ordem:");
    emOrdem(arvore);
    printf("\n");
}

#endif