#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Traduzir_bomdia(char* argv[]) {
    if (strcmp(argv[1], "-1") == 0 || strcmp(argv[1], "--pt") == 0) printf("Bom dia!");                // Português
    else if (strcmp(argv[1], "-2") == 0 || strcmp(argv[1], "--en") == 0) printf("Good Morning!");      // Inglês
    else if (strcmp(argv[1], "-3") == 0 || strcmp(argv[1], "--es") == 0) printf("Buen día!");          // Espanhol
    else if (strcmp(argv[1], "-4") == 0 || strcmp(argv[1], "--fr") == 0) printf("Bonjour!");           // Francês
    else if (strcmp(argv[1], "-5") == 0 || strcmp(argv[1], "--it") == 0) printf("Buongiorno!");        // Italiano
    else if (strcmp(argv[1], "-6") == 0 || strcmp(argv[1], "--aa") == 0) printf("좋은 아침이에요!");     // Coreano
    else if (strcmp(argv[1], "-7") == 0 || strcmp(argv[1], "--aa") == 0) printf("おはよう!");           // Japonês
    else if (strcmp(argv[1], "-8") == 0 || strcmp(argv[1], "--ru") == 0) printf("Доброе утро!");       // Russo
    else printf("Argumento invalido!\n");
}

void Exibir_Documentacao(char* argv[]) {
    printf("Exibir documentação do projeto\n");
    return;
}

void Ler_argumento(char* argv[]) {
    char* type;
    int num = strtol(argv[1], &type, 10);

    if ((strcmp(type, "\0") == 0) || (len(argv[1]) == 4)) Traduzir_bomdia(argv);
    else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0) printf("Versão 1.0.0");
    else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) Exibir_Documentacao(argv);
    else printf("Argumento invalido!\n");
}


int main(int argc,char* argv[]) {
    system("chcp 65001 > null");

    if (argc == 1) printf("Bom dia!");
    else if (argc == 2) {
        Ler_argumento(argv);
    }
    else printf("Quantidade de argumentos invalida!\n");

    return 0;
}
