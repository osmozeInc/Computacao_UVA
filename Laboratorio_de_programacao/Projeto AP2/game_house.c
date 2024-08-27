#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "configuracoes\configuracoes.h"

void ApagarLinha(int numero_de_linhas) 
{
    for (int i = 0; i < numero_de_linhas; i++)
    {
        printf("\e[A\e[K");
    }
}


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
            printf("Escolha uma opção:\n%s>>> Jogo da Velha%s\n%s    Jogo da forca%s\n%s    Jogo de 21%s\n%s    Jogo de dados%s\n%s    Configurações%s\n%s    Sair%s\n", fundo, resetar, texto, resetar, texto, resetar, texto, resetar, texto, resetar, texto, resetar);

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

        ApagarLinha(7);

        if (opcao == 1)
        {
            printf("Escolha uma opção:\n");
            printf("%s>>> Jogo da Velha%s\n", fundo, resetar);
            printf("%s    Jogo da forca%s\n", texto, resetar);
            printf("%s    Jogo de 21%s\n", texto, resetar);
            printf("%s    Jogo de dados%s\n", texto, resetar);
            printf("%s    Configurações%s\n", texto, resetar);
            printf("%s    Sair%s\n", texto, resetar);
        }

        if (opcao == 2)
        {
            printf("Escolha uma opção:\n");
            printf("%s    Jogo da Velha%s\n", texto, resetar);
            printf("%s>>> Jogo da forca%s\n", fundo, resetar);
            printf("%s    Jogo de 21%s\n", texto, resetar);
            printf("%s    Jogo de dados%s\n", texto, resetar);
            printf("%s    Configurações%s\n", texto, resetar);
            printf("%s    Sair%s\n", texto, resetar);
        }

        if (opcao == 3)
        {
            printf("Escolha uma opção:\n");
            printf("%s    Jogo da Velha%s\n", texto, resetar);
            printf("%s    Jogo da forca%s\n", texto, resetar);
            printf("%s>>> Jogo de 21%s\n", fundo, resetar);
            printf("%s    Jogo de dados%s\n", texto, resetar);
            printf("%s    Configurações%s\n", texto, resetar);
            printf("%s    Sair%s\n", texto, resetar);
        }
        
        if (opcao == 4)
        {
            printf("Escolha uma opção:\n");
            printf("%s    Jogo da Velha%s\n", texto, resetar);
            printf("%s    Jogo da forca%s\n", texto, resetar);
            printf("%s    Jogo de 21%s\n", texto, resetar);
            printf("%s>>> Jogo de dados%s\n", fundo, resetar);
            printf("%s    Configurações%s\n", texto, resetar);
            printf("%s    Sair%s\n", texto, resetar);
        }

        if (opcao == 5)
        {
            printf("Escolha uma opção:\n");
            printf("%s    Jogo da Velha%s\n", texto, resetar);
            printf("%s    Jogo da forca%s\n", texto, resetar);
            printf("%s    Jogo de 21%s\n", texto, resetar);
            printf("%s    Jogo de dados%s\n", texto, resetar);
            printf("%s>>> Configurações%s\n", fundo, resetar);
            printf("%s    Sair%s\n", texto, resetar);
        }

        if (opcao == 6)
        {
            printf("Escolha uma opção:\n");
            printf("%s    Jogo da Velha%s\n", texto, resetar);
            printf("%s    Jogo da forca%s\n", texto, resetar);
            printf("%s    Jogo de 21%s\n", texto, resetar);
            printf("%s    Jogo de dados%s\n", texto, resetar);
            printf("%s    Configurações%s\n", texto, resetar);
            printf("%s>>> Sair%s\n", fundo, resetar);
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
        system(".\\Jogos\\jogo_da_forca.exe");
    else if (opcao == 3)
        system(".\\Jogos\\jogo_de_21.exe");
    else if (opcao == 4)
        system(".\\Jogos\\jogo_de_dados.exe");
    else if (opcao == 5)
        system(".\\configuracoes\\configurar_cores.exe");
    else if (opcao == 6)
        return 0;

}
