#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>
#include "configuracoes.h"

const char* CorDeDestaqueMenu()
{
    char conteudo[10];

    FILE *arquivo = fopen("fundo_do_menu.txt", "r");
    fgets(conteudo, 9, arquivo);
    fclose(arquivo);

    if (conteudo[6] == 4) {
        return "\033[44m"; // Azul
    } else if (conteudo[6] == 2) {
        return "\033[42m"; // Verde
    } else if (conteudo[6] == 1) {
        return "\033[41m"; // Vermelho
    } else if (conteudo[6] == 3) {
        return "\033[43m"; // Amarelo
    } else if (conteudo[6] == 5) {
        return "\033[45m"; // Roxo
    } else {
        return "\033[102m"; // Reset ou cor padrão
    }} 

const char* CorDoTextoMenu()
{
return "\033[90m";
}

const char* reset()
{
return "\033[0m";
}