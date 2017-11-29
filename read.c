#include <stdio.h>
#include "read.h"
#include "func.h"


void getTreeFromFile(char* fileName, No** arvore) {
    inicializa(arvore);
    FILE *arq;
    arq = fopen(fileName, "r");
    if (!arq) return;
    int nodeValue = 0;
    while (fscanf(arq, "%d", &nodeValue) != EOF) {
        inserir(arvore, nodeValue);
    }
}

void getGrafoFromFile(char* fileName) {
    printf("\nReadingGrafoFromFile..............");
}
