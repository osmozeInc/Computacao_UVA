#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

    const char* Fbranco = "\033[44m"; //fundo branco
    const char* Tamarelo = "\033[90m"; //texto amarelo
    const char* reset = "\033[0m";


void printTituloASCII() {
    printf("  _____                                                                 \n");
    printf(" / ____|                         _    _                                 \n");
    printf("| |  __  __ _ _ __ ____  ___    | |  | |      _   _  ___  ___           \n");
    printf("| | |_ |/ _` | '_ ` _ \\ / _ \\   |  __  |/ _ \\| | | |/ __|/ _ \\      \n");
    printf("| |__| | (_| | | | | | |  __/   | |  | | (_) | |_| |\\__ \\  __/        \n");
    printf(" \\_____/\\__,_|_| |_| |_|\\___|   |_|  |_|\\___/ \\___/ |___/\\___|    \n");
    printf("                                                                      \n\n");
}


int Menu() {
    int opcao = 1;
            printf("Escolha uma opção:\n%s>>> Jogo da Velha%s\n%s    Jogo da forca%s\n%s    Jogo de 21%s\n%s    Jogo de dados%s\n%s    Configurações%s\n%s    Sair%s\n\n\n", Fbranco, reset, Tamarelo, reset, Tamarelo, reset, Tamarelo, reset, Tamarelo, reset, Tamarelo, reset);

    while (1)
    {
        char tecla = _getch();
        if (tecla == 0)
        {
            tecla = _getch();
            if (tecla == 72 && opcao > 1)
                opcao--;
            else if (tecla == 80 && opcao < 6)
                opcao++;
        }
        else if (tecla == 13)
            break;

        for (int i = 0; i < 9; i++)
        {
            printf("\33[A");
            printf("\33[K");
        }

        if (opcao == 1)
        {
            printf("Escolha uma opção:\n");
            printf("%s>>> Jogo da Velha%s\n", Fbranco, reset);
            printf("%s    Jogo da forca%s\n", Tamarelo, reset);
            printf("%s    Jogo de 21%s\n", Tamarelo, reset);
            printf("%s    Jogo de dados%s\n", Tamarelo, reset);
            printf("%s    Configurações%s\n", Tamarelo, reset);
            printf("%s    Sair%s\n\n\n", Tamarelo, reset);
        }

        if (opcao == 2)
        {
            printf("Escolha uma opção:\n");
            printf("%s    Jogo da Velha%s\n", Tamarelo, reset);
            printf("%s>>> Jogo da forca%s\n", Fbranco, reset);
            printf("%s    Jogo de 21%s\n", Tamarelo, reset);
            printf("%s    Jogo de dados%s\n", Tamarelo, reset);
            printf("%s    Configurações%s\n", Tamarelo, reset);
            printf("%s    Sair%s\n\n\n", Tamarelo, reset);
        }

        if (opcao == 3)
        {
            printf("Escolha uma opção:\n");
            printf("%s    Jogo da Velha%s\n", Tamarelo, reset);
            printf("%s    Jogo da forca%s\n", Tamarelo, reset);
            printf("%s>>> Jogo de 21%s\n", Fbranco, reset);
            printf("%s    Jogo de dados%s\n", Tamarelo, reset);
            printf("%s    Configurações%s\n", Tamarelo, reset);
            printf("%s    Sair%s\n\n\n", Tamarelo, reset);
        }
        
        if (opcao == 4)
        {
            printf("Escolha uma opção:\n");
            printf("%s    Jogo da Velha%s\n", Tamarelo, reset);
            printf("%s    Jogo da forca%s\n", Tamarelo, reset);
            printf("%s    Jogo de 21%s\n", Tamarelo, reset);
            printf("%s>>> Jogo de dados%s\n", Fbranco, reset);
            printf("%s    Configurações%s\n", Tamarelo, reset);
            printf("%s    Sair%s\n\n\n", Tamarelo, reset);
        }

        if (opcao == 5)
        {
            printf("Escolha uma opção:\n");
            printf("%s    Jogo da Velha%s\n", Tamarelo, reset);
            printf("%s    Jogo da forca%s\n", Tamarelo, reset);
            printf("%s    Jogo de 21%s\n", Tamarelo, reset);
            printf("%s    Jogo de dados%s\n", Tamarelo, reset);
            printf("%s>>> Configurações%s\n", Fbranco, reset);
            printf("%s    Sair%s\n\n\n", Tamarelo, reset);
        }

        if (opcao == 6)
        {
            printf("Escolha uma opção:\n");
            printf("%s    Jogo da Velha%s\n", Tamarelo, reset);
            printf("%s    Jogo da forca%s\n", Tamarelo, reset);
            printf("%s    Jogo de 21%s\n", Tamarelo, reset);
            printf("%s    Jogo de dados%s\n", Tamarelo, reset);
            printf("%s    Configurações%s\n", Tamarelo, reset);
            printf("%s>>> Sair%s\n\n\n", Fbranco, reset);
        }
    }

    return opcao;
}


int main() {
    system("chcp 65001");
    system("cls || clear");


    printTituloASCII();
    int opcao = Menu();

    if (opcao == 1)
    {
        system("cls || clear");
        printf("Jogo da Velha\n");
    }
    else if (opcao == 2)
    {
        system("cls || clear");
        printf("Jogo da forca\n");
    }
    else if (opcao == 3)
    {
        system("cls || clear");
        printf("Jogo de 21\n");
    }
    else if (opcao == 4)
    {
        system("cls || clear");
        printf("Jogo de dados\n");
    }
    else if (opcao == 5)
    {
        system("cls || clear");
        printf("Configurações\n");
    }
    else if (opcao == 6)
    {
        printf("Saindo...\n");
        return 0;
    }
    
    return 0;
}
