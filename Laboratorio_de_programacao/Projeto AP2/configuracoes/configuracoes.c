#include <stdio.h>
#include "configuracoes.h"

char* cor_de_destaque_menu = "\033[44m";

const char* CorDeDestaqueMenu()
{
    char conteudo[10];

    FILE *arquivo = fopen("fundo_do_menu.txt", "r");
    fgets(conteudo, 9, arquivo);
    fclose(arquivo);

    return cor_de_destaque_menu;
} 

const char* CorDoTextoMenu()
{
    return "\033[90m";
}

const char* reset()
{
return "\033[0m";
}