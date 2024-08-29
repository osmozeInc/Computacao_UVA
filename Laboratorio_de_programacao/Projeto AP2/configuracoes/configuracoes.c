#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>
#include "configuracoes.h"

void ApagarLinha(int numero_de_linhas) 
{
    for (int i = 0; i < numero_de_linhas; i++)
    {
        printf("\e[A\e[K");
    }
}

int JogarNovamante()
{
    const char* fundo = CorDeDestaqueMenu();
    const char* texto = CorDoTextoMenu();
    const char* resetar = reset();
    int opcao = 1;

    printf("\n\n\n\n\n\n");    
    while (1)
    {
        ApagarLinha(5);
        if (opcao == 1)
        {
            printf("\n\n>>> Deseja jogar novamente? \n");
            printf("%s>>> Sim%s\n", fundo, resetar);
            printf("%s    Não%s\n", texto, resetar);
        }

        else if (opcao == 2)
        {
            printf("\n\n>>> Deseja jogar novamente? \n");
            printf("%s    Sim%s\n", texto, resetar);
            printf("%s>>> Não%s\n", fundo, resetar);
        }

    char tecla = _getch();
        if (tecla == 0)
        {
            tecla = _getch();
            if (tecla == 72 && opcao > 1)
                opcao--;
            else if (tecla == 80 && opcao < 2)
                opcao++;
        }
        else if (tecla == 13)
            break;
    }

    ApagarLinha(5);
    return opcao;
}

const char* CorDeDestaqueMenu()
{
    char conteudo[10];

    FILE *arquivo = fopen("configuracoes/fundo_do_menu.txt", "r");
    fgets(conteudo, 9, arquivo);
    fclose(arquivo);

    if (conteudo[6] == '4') {
        return "\033[44m"; // Azul
    } else if (conteudo[6] == '2') {
        return "\033[42m"; // Verde
    } else if (conteudo[6] == '1') {
        return "\033[41m"; // Vermelho
    } else if (conteudo[6] == '3') {
        return "\033[43m"; // Amarelo
    } else if (conteudo[6] == '5') {
        return "\033[45m"; // Roxo
    } else {
        return "\033[0m"; // Reset ou cor padrão
    }
} 

const char* CorDoTextoMenu()
{
    char conteudo[10];

    FILE *arquivo = fopen("configuracoes/texto_do_menu.txt", "r");
    fgets(conteudo, 9, arquivo);
    fclose(arquivo);

    if (conteudo[6] == '0') {
        return "\033[90m"; // Cinza
    } else if (conteudo[6] == '2') {
        return "\033[32m"; // Verde
    } else if (conteudo[6] == '6') {
        return "\033[36m"; // Ciano
    } else if (conteudo[6] == '3') {
        return "\033[33m"; // Amarelo
    } else if (conteudo[6] == '1') {
        return "\033[31m"; // Vermelho
    } else {
        return "\033[0m"; // Reset ou cor padrão
    }
}

const char* CorDeDestaqueJogo()
{
    char conteudo[10];

    FILE *arquivo = fopen("configuracoes/destaque_do_jogo.txt", "r");
    fgets(conteudo, 9, arquivo);
    fclose(arquivo);

    if (conteudo[6] == '0') {
        return "\033[90m"; // Cinza
    } else if (conteudo[6] == '2') {
        return "\033[32m"; // Verde
    } else if (conteudo[6] == '6') {
        return "\033[36m"; // Ciano
    } else if (conteudo[6] == '3') {
        return "\033[33m"; // Amarelo
    } else if (conteudo[6] == '1') {
        return "\033[31m"; // Vermelho
    } else {
        return "\033[0m"; // Reset ou cor padrão
    }
}

const char* CorDoTextoJogo()
{
    char conteudo[10];

    FILE *arquivo = fopen("configuracoes/texto_do_jogo.txt", "r");
    fgets(conteudo, 9, arquivo);
    fclose(arquivo);

    if (conteudo[6] == '0') {
        return "\033[90m"; // Cinza
    } else if (conteudo[6] == '2') {
        return "\033[32m"; // Verde
    } else if (conteudo[6] == '6') {
        return "\033[36m"; // Ciano
    } else if (conteudo[6] == '3') {
        return "\033[33m"; // Amarelo
    } else if (conteudo[6] == '1') {
        return "\033[31m"; // Vermelho
    } else {
        return "\033[0m"; // Reset ou cor padrão
    }
}

const char* reset()
{
    return "\033[0m";
}