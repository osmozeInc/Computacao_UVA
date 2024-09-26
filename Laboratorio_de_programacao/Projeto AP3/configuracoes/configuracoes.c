#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "configuracoes.h"
#include "../ranking/ranking.h"

void ApagarLinha(int numero_de_linhas) 
{
    for (int i = 0; i < numero_de_linhas; i++)
    {
        printf("\e[A\e[K");
    }
}

void Ranking(int pontuacao, int jogo)
{
    int resposta = Config_EscolherRegistrar(pontuacao);
    Config_RegistrarPlacar(resposta, pontuacao, jogo);
}

int JogarNovamente()
{
    const char* fundo = CorDeDestaqueMenu();
    const char* texto = CorDoTextoMenu();
    const char* resetar = reset();
    char tecla_char;
    int tecla_int;
    int opcao = 1;

    printf("\n\n\n\n\n\n\n");

    while (1)
    {
        ApagarLinha(5);
        if (opcao == 1)
        {
            printf("%sDeseja jogar novamente? %s\n", texto, resetar);
            printf("%s1. Sim (enter)%s\n", fundo, resetar);
            printf("%s2. Não%s\n", texto, resetar);
            printf("%s>>> %s", texto, resetar);
        }

        else if (opcao == 2)
        {
            printf("%sDeseja jogar novamente? %s\n", texto, resetar);
            printf("%s1. Sim%s\n", texto, resetar);
            printf("%s2. Não (enter)%s\n", fundo, resetar);
            printf("%s>>> %s", texto, resetar);
        }

        tecla_char = getchar();
        if (tecla_char == '\n') break;
        else{
            tecla_int = tecla_char - '0';
            if (tecla_int >= 1 && tecla_int <= 2){
                opcao = tecla_int;
                getchar();
                printf("\n");
            }
            else{
                printf("\n");
                getchar();
            }
        }
    }

    return opcao;
}

void LimparBuffer() 
{
    int c;
    // Lê até encontrar um caractere de nova linha ou EOF
    while ((c = getchar()) != '\n' && c != EOF);
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
        return "\033[0m"; // cor padrão
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