#include <stdio.h>
#include "print.h"
#include "func.h"
#ifndef PRINT_H
#define PRINT_H

// void printGrafo() {
//     printf("\nPrinting Grafo to screen..............");
// }

// void printGrafoInfo() {
//     printf("\nPrinting Grafo info to screen..............");
// }

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
    int noAncestral, noDescendente, noGrau, noNivel;
    printf("\n");
    printf("======INSERIR NUMEROS PARA PESQUISA===== \n\n");
    printf("Numero para seus ANCESTRAIS: ");
    scanf("%d", &noAncestral);
    printf("\n");
    printf("Numero para seus DESCENTES: ");
    scanf("%d",&noDescendente);
    printf("\n");
    printf("Numero para seu GRAU: ");
    scanf("%d",&noGrau);
    printf("\n");
    printf("Numero para seu NIVEL: ");
    scanf("%d",&noNivel);
    printf("\n\n");
    
    printf("======================\n\n");
    printf("[INFORMACOES DA ARVORE] \n\n");
   
    printf("No raiz: ");
    printRaiz(arvore);

    printf("Nos ramos: ");
    nosRamo(arvore);
    printf("\n");

    printf("Nos folha: ");
    noFolha(arvore);
    printf("\n\n");

    printf("Grau arvore: %d\n", grauArvore(arvore,0));    
    printf("Altura arvore: %d\n", alturaArvore(arvore));
    printf("Profundidade arvore: %d\n\n", profundidadeArvore(arvore));

    printf("[INFORMACOES DOS NOS]\n\n");    
    
    printf("Ancestrais do NO[%d]: ", noAncestral);
    ancestral(arvore,noAncestral);    
    printf("\n");

    printf("Descendentes do NO[%d]: ", noDescendente);
    descendente(arvore,noDescendente);
    printf("\n");

    printf("Grau do NO[%d]: %d\n", noGrau, grauNo(arvore, noGrau));

    printf("Nivel No[%d]: %d\n", noNivel, nivelNo(arvore, noNivel));
    printf("\n");
    
    printf("[ORDENACOES DA ARVORE]\n\n");
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