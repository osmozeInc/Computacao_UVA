/*
> JOGO DA FORCA 

> OBJETIVO: acertar uma palavra secreta (PS)

> o jogador sabe a quantidade de letras da PS

> o jogador tem N tentativas de escolha de letras que podem estar na palavra
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void Menu()
{
    int dificuldade;

    while (1)
    {
        system("cls");
        printf("selecione a dificuldade:\n\n");
        printf("1- Facil\n"
        "> Palavras simples\n"
        "> palavras fáceis\n\n"
        "2- Difícil\n"
        "> Palavras compostas\n"
        "> palavras difíceis\n\n"
        "(digite 1 ou 2)\n"
        "> ");
        scanf("%d", &dificuldade);

        if (dificuldade == 1)
        {
            printf("dificuldade facil\n");
            break;
        }
        else if (dificuldade == 2)
        {
            printf("dificuldade difícil\n");
            break;
        }
        else
        {
            printf("Opção inválida, repita!");
            Sleep(1000);
        }
    }
}



int main()
{
    system("chcp 65001");

    Menu();

    return 0;
}