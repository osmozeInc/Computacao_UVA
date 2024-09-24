#include <stdio.h>
#include <stdlib.h>
#include "configuracoes\configuracoes.h"


void GameHouse() {
    printf("  _____                                                                 \n");
    printf(" / ____|                         _    _                                 \n");
    printf("| |  __  __ _ _ __ ____  ___    | |  | |      _   _  ___  ___           \n");
    printf("| | |_ |/ _` | '_ ` _ \\ / _ \\   |  __  |/ _ \\| | | |/ __|/ _ \\      \n");
    printf("| |__| | (_| | | | | | |  __/   | |  | | (_) | |_| |\\__ \\  __/        \n");
    printf(" \\_____/\\__,_|_| |_| |_|\\___|   |_|  |_|\\___/ \\___/ |___/\\___|    \n");
    printf("                                                                      \n\n");
}

int Menu() {
    const char* fundo = CorDeDestaqueMenu();
    const char* texto = CorDoTextoMenu();
    const char* resetar = reset();
    char tecla_char;
    int tecla_int;

    int opcao = 1;
            printf("\n\n\n\n\n\n");

    while (1)
    {
        ApagarLinha(7);
        if (opcao == 1)
        {
            printf("%s\n1. Jogo da Velha (enter)%s\n", fundo, resetar);
            printf("%s2. Jogo de dados%s\n", texto, resetar);
            printf("%s3. Configurações%s\n", texto, resetar);
            printf("%s4. Sair%s\n", texto, resetar);
            printf("%sEscolha uma opção: %s", texto, resetar);
        }
        
        if (opcao == 2)
        {
            printf("%s\n1. Jogo da Velha%s\n", texto, resetar);
            printf("%s2. Jogo de dados (enter)%s\n", fundo, resetar);
            printf("%s3. Configurações%s\n", texto, resetar);
            printf("%s4. Sair%s\n", texto, resetar);
            printf("%sEscolha uma opção: %s", texto, resetar);
        }

        if (opcao == 3)
        {
            printf("%s\n1. Jogo da Velha%s\n", texto, resetar);
            printf("%s2. Jogo de dados%s\n", texto, resetar);
            printf("%s3. Configurações (enter)%s\n", fundo, resetar);
            printf("%s4. Sair%s\n", texto, resetar);
            printf("%sEscolha uma opção: %s", texto, resetar);
        }

        if (opcao == 4)
        {
            printf("%s\n1. Jogo da Velha%s\n", texto, resetar);
            printf("%s2. Jogo de dados%s\n", texto, resetar);
            printf("%s3. Configurações%s\n", texto, resetar);
            printf("%s4. Sair (enter)%s\n", fundo, resetar);
            printf("%sEscolha uma opção: %s", texto, resetar);
        }

        // alterei a forma de ler a tecla pressionada
        // antes era usado a biblioteca conion.h, mas ela não é compatível com todos os sistemas
        // agora está sendo usado o getchar() que é padrão do C

        tecla_char = getchar();
        if (tecla_char == '\n')
            break;
        else{
            tecla_int = tecla_char - '0';
            if (tecla_int >= 1 && tecla_int <= 4)
            {
                opcao = tecla_int;
                getchar();
                printf("\n");
            }
            else{
                printf("\n");
                getchar();
            }
        }
    }

    return opcao;
}

int main() {
    system("cls || clear");

    GameHouse();
    int opcao = Menu();


    if (opcao == 1)
        system(".\\Jogos\\jogo_da_velha.exe");
    else if (opcao == 2)
        system(".\\Jogos\\jogo_de_dados.exe");
    else if (opcao == 3)
        system(".\\configuracoes\\configurar_cores.exe");
    else if (opcao == 4)
        return 0;

}
