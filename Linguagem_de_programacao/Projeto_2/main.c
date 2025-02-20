// tela de inicio
// decidir forma de jogo

// 1 jogo comum
// 1 definição das variaveis do jogo
// 1 inicio da tela de jogo
// 1 fim do jogo 

// 2 jogo personalizado
// 2 definição das variaveis do jogo pelo usuário
// 2 inicio da tela de jogo personalizado
// 2 fim do jogo 

// mensagem final de fim de jogo



#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void Carregamento(){
    system("cls");
    printf("\n\nIniciando Jogo...\n"
           "|=================================|======|\n");

    for (int porcentagem = 1; porcentagem <= 11; porcentagem++)    // a porcentagem sobe em 9
    {
        printf("|");

        for (int barra = 0; barra < porcentagem; barra++)     //completa a barra de carregamento dependendo da poecentagem
            printf("###");
        for (int espaco = porcentagem; espaco < 11; espaco++)    // cria os espaços da barra até o fim
            printf("   ");

        // exibe a linha de porcentagem de 0 a 99
            printf("|%4d%% |\n", porcentagem * 9);
            printf("|=================================|======|\n");
            
            Sleep(200);
            printf("\e[A\e[A");
    }
}

void Tela_de_Inicio(){
    // exibe o nome do jogo piscando
    for (int loop_da_funcao = 0; loop_da_funcao < 1; loop_da_funcao++)
    {
        system("cls");
        Sleep(500);
        printf( " _    _                                            \n"
                "| |  | |                                           \n"
                "| |__| | __ _ _ ___  __ _ _ __ ___   __ _ _ ___    \n"
                "|  __  |/ _` | '_  \\/ _` | '_ ` _ \\ / _` | '_  \\   \n"
                "| |  | | (_| | | | | (_| | | | | | | (_| | | | |   \n"
                "|_|  |_|\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_|   \n"
                "                     __| |                         \n"
                "                    |____/                         \n");
        Sleep(500);
    }
}

int Escolher_Jogo(){
    while (1)
    {
        system("cls");
        printf( "Escolha um modo:\n\n"
            "1 - Jogo Padrão\n"
            "2 - Jogo Personalizado\n"
            "> ");

        int dificuldade;
        scanf("%d", &dificuldade);

        if (dificuldade == 1 || dificuldade == 2)
            return dificuldade; // sai da função

        printf("Opção inválida\n"); // caso não saia da função
        Sleep(1000);
    }
}


int main(){
    system("chcp 65001");
    Tela_de_Inicio();

    short int jogo = Escolher_Jogo();

    if (jogo == 1)
        system("gcc jogo\\hangman_classico.c -o jogo\\jogo.exe");
    else
        system("gcc jogo\\hangman_personalizado.c -o jogo\\jogo.exe");

    Carregamento();
    system("cls");
    return system("jogo\\jogo.exe");
}