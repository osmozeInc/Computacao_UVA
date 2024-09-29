#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "configuracoes\configuracoes.h"


void GameHouse() 
{
    const char* resetar = reset();
    system("cls || clear");
    printf("%s", resetar);
    printf("  _____                          _    _                                 \n");
    printf(" / ____|                        | |  | |                                \n");
    printf("| |  __  __ _ _ __ ____  ___    | |__| | ___  _   _  ___  ___           \n");
    printf("| | |_ |/ _` | '_ ` _ \\ / _ \\   |  __  |/ _ \\| | | |/ __|/ _ \\      \n");
    printf("| |__| | (_| | | | | | |  __/   | |  | | (_) | |_| |\\__ \\  __/        \n");
    printf(" \\_____/\\__,_|_| |_| |_|\\___|   |_|  |_|\\___/ \\___/ |___/\\___|    \n");
    printf("                                                                      \n\n");
}

int Menu() 
{
    const char* fundo = CorDeDestaqueMenu();
    const char* texto = CorDoTextoMenu();
    const char* resetar = reset();
    char tecla_char;
    int tecla_int, opcao = 1;
    printf("\n\n\n\n\n\n\n");

    while (1)
    {
        ApagarLinha(7);
        if (opcao == 1)
        {
            printf("%s1. Jogo da Velha (enter)%s\n", fundo, resetar);
            printf("%s2. Jogo de dados\n", texto);
            printf("3. Configurações\n");
            printf("4. Placar de jogadores\n");
            printf("5. Sair\n");
            printf("Escolha uma opção: ");
        }
        
        if (opcao == 2)
        {
            printf("%s1. Jogo da Velha%s\n", texto, resetar);
            printf("%s2. Jogo de dados (enter)%s\n", fundo, resetar);
            printf("%s3. Configurações\n", texto);
            printf("4. Placar de jogadores\n");
            printf("5. Sair\n");
            printf("Escolha uma opção: ");
        }

        if (opcao == 3)
        {
            printf("%s1. Jogo da Velha\n", texto);
            printf("2. Jogo de dados%s\n", resetar);
            printf("%s3. Configurações (enter)%s\n", fundo, resetar);
            printf("%s4. Placar de jogadores\n", texto);
            printf("5. Sair\n");
            printf("Escolha uma opção: ");
        }

        if (opcao == 4)
        {
            printf("%s1. Jogo da Velha\n", texto);
            printf("2. Jogo de dados\n");
            printf("3. Configurações%s\n",resetar);
            printf("%s4. Placar de jogadores (enter)%s\n", fundo, resetar);
            printf("%s5. Sair\n", texto);
            printf("Escolha uma opção: ");
        }

        if (opcao == 5)
        {
            printf("%s1. Jogo da Velha\n", texto);
            printf("2. Jogo de dados\n");
            printf("3. Configurações\n");
            printf("4. Placar de jogadores%s\n", resetar);
            printf("%s5. Sair (enter)%s\n", fundo, resetar);
            printf("%sEscolha uma opção: ", texto);
        }

        // alterei a forma de ler a tecla pressionada
        // antes era usado a biblioteca conion.h
        // agora está sendo usado o getchar() que é padrão do C

        tecla_char = getchar();
        if (tecla_char == '\n') break;
        else{
            tecla_int = tecla_char - '0';
            if (tecla_int >= 1 && tecla_int <= 5)
            {
                opcao = tecla_int;
                getchar();
                printf("\n");
            }
            else
            {
                getchar();
                printf("\n");
            }
        }
    }
    return opcao;
}

int main() 
{
    while (1)
    {
        system("cls || clear");
        GameHouse();
        int opcao = Menu();
        if (opcao == 1) system(".\\Jogos\\jogo_da_velha.exe");

        else if (opcao == 2) system(".\\Jogos\\jogo_de_dados.exe");

        else if (opcao == 3) system(".\\configuracoes\\configurar_cores.exe");

        else if (opcao == 4) system(".\\ranking\\placar_ranking.exe");

        else if (opcao == 5) // sair
        {
            char mensagem[23] = "\nObrigado por jogar!\n\n";
            for (int i = 0; i < 22; i++) 
            {
                printf("%c", mensagem[i]);
                Sleep(100);
            }
            return 0;
        }
    }
}
