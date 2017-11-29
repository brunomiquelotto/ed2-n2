#include <stdio.h>
#include "print.h"
#include "read.h"
#include "func.h"



int main() { 
    //TODO: Alterar
    No* arvore;
    getTreeFromFile("arvore.txt", &arvore);
    printTree(arvore);
    printf("\n");
    printTreeInfo(arvore);

    getGrafoFromFile("filename");
    printGrafo();
    printGrafoInfo();
    return 0;
}