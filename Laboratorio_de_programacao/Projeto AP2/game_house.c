#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
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

    int opcao = 1;
            printf("\n\n\n\n\n");

    while (1)
    {
        ApagarLinha(5);
        if (opcao == 1)
        {
            printf("%sEscolha uma opção:%s\n", texto, resetar);
            printf("%s>>> Jogo da Velha%s\n", fundo, resetar);
            printf("%s    Jogo de dados%s\n", texto, resetar);
            printf("%s    Configurações%s\n", texto, resetar);
            printf("%s    Sair%s\n", texto, resetar);
        }
        
        if (opcao == 2)
        {
           printf("%sEscolha uma opção:%s\n", texto, resetar);
            printf("%s    Jogo da Velha%s\n", texto, resetar);
            printf("%s>>> Jogo de dados%s\n", fundo, resetar);
            printf("%s    Configurações%s\n", texto, resetar);
            printf("%s    Sair%s\n", texto, resetar);
        }

        if (opcao == 3)
        {
           printf("%sEscolha uma opção:%s\n", texto, resetar);
            printf("%s    Jogo da Velha%s\n", texto, resetar);
            printf("%s    Jogo de dados%s\n", texto, resetar);
            printf("%s>>> Configurações%s\n", fundo, resetar);
            printf("%s    Sair%s\n", texto, resetar);
        }

        if (opcao == 4)
        {
           printf("%sEscolha uma opção:%s\n", texto, resetar);
            printf("%s    Jogo da Velha%s\n", texto, resetar);
            printf("%s    Jogo de dados%s\n", texto, resetar);
            printf("%s    Configurações%s\n", texto, resetar);
            printf("%s>>> Sair%s\n", fundo, resetar);
        }

        char tecla = _getch();
        if (tecla == 0)
        {
            tecla = _getch();
            if (tecla == 72 && opcao > 1)
                opcao--;
            else if (tecla == 80 && opcao < 4)
                opcao++;
        }
        else if (tecla == 13)
            break;
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
