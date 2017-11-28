#include <stdio.h>
#include "print.h"
#include "read.h"
#include "func.h"



int main() { 
    //TODO: Alterar

    getTreeFromFile("filename");
    printTree();
    printTreeInfo();

    getGrafoFromFile("filename");
    printGrafo();
    printGrafoInfo();
    return 0;
}