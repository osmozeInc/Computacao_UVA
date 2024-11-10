#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Mensagem_de_Erro(int erro) {
    if (erro == 1) printf("\033[33mErro:\033[0m Quantidade de argumentos insuficientes\n"
                          "Execute o programa seguido de uma opção.\n");

    if (erro == 2) printf("\033[33mErro:\033[0m Quantidade de argumentos inválida\n"
                          "digite \033[33m\'./bomdia -h\'\033[0m para mais informações\n");
    
    if (erro == 3) printf("\033[33mErro:\033[0m Opção inválida\n"
                          "digite \033[33m\'./bomdia -h\'\033[0m para mais informações\n");

    printf("\n\n\033[90m"
           "Lista de opções aceitas:\n\n"
           "--help ou -h (documentação do software)\n"
           "--version ou -v (versão do software)\n"
           "--pt ou -1 (idioma português)\n"
           "--en ou -2 (idioma inglês)\n"
           "--es ou -3 (idioma espanhol)\n"
           "--fr ou -4 (idioma francês)\n"
           "--it ou -5 (idioma italiano)\n"
           "--co ou -6 (idioma coreano)\n"
           "--ja ou -7 (idioma japonês)\n"
           "--ru ou -8 (idioma russo)\033[0m\n\n");

}

void Traduzir_bomdia(char* argv[]) {
    if (strcmp(argv[1], "-1") == 0 || strcmp(argv[1], "--pt") == 0) printf("Bom dia!");                // Português
    else if (strcmp(argv[1], "-2") == 0 || strcmp(argv[1], "--en") == 0) printf("Good Morning!");      // Inglês
    else if (strcmp(argv[1], "-3") == 0 || strcmp(argv[1], "--es") == 0) printf("Buen día!");          // Espanhol
    else if (strcmp(argv[1], "-4") == 0 || strcmp(argv[1], "--fr") == 0) printf("Bonjour!");           // Francês
    else if (strcmp(argv[1], "-5") == 0 || strcmp(argv[1], "--it") == 0) printf("Buongiorno!");        // Italiano
    else if (strcmp(argv[1], "-6") == 0 || strcmp(argv[1], "--aa") == 0) printf("좋은 아침이에요!");     // Coreano
    else if (strcmp(argv[1], "-7") == 0 || strcmp(argv[1], "--aa") == 0) printf("おはよう!");           // Japonês
    else if (strcmp(argv[1], "-8") == 0 || strcmp(argv[1], "--ru") == 0) printf("Доброе утро!");       // Russo
    else Mensagem_de_Erro(3);
}

void Exibir_Documentacao(char* argv[]) {
    printf("Exibir documentação do projeto\n");
    return;
}

void Ler_argumento(char* argv[]) {
    char* type;
    int num = strtol(argv[1], &type, 10);

    if ((strcmp(type, "\0") == 0) || (strlen(argv[1]) == 4)) Traduzir_bomdia(argv);
    else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0) printf("Versão 1.0.0");
    else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) Exibir_Documentacao(argv);
    else Mensagem_de_Erro(3);}


int main(int argc,char* argv[]) {
    system("chcp 65001 > null");
    system("cls");
    

    if (argc == 1) Mensagem_de_Erro(1);
    else if (argc == 2) Ler_argumento(argv);
    else Mensagem_de_Erro(2);

    return 0;
}
