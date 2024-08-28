#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>
#include "configuracoes.h"

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
        return "\033[3m"; // Amarelo
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
        return "\033[3m"; // Amarelo
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
        return "\033[3m"; // Amarelo
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