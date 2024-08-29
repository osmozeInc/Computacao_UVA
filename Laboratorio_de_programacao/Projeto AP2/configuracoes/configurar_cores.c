#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include "configuracoes.h"


void CorDeDestaqueMenuConfig() {
    const char* fundo = CorDeDestaqueMenu();
    const char* texto = CorDoTextoMenu();
    const char* resetar = reset();
    int opcao = 1;

    printf("%sEscolha uma cor de fundo para o menu:%s\n", texto, resetar);
    printf("\n\n\n\n\n");
    while (1)
    {

        if (opcao == 1)
        {
        ApagarLinha(5);
        printf("%s>>> Azul%s\n", fundo, resetar);
        printf("%s    Verde%s\n", texto, resetar);
        printf("%s    Vermelho%s\n", texto, resetar);
        printf("%s    Amarelo%s\n", texto, resetar);
        printf("%s    Roxo%s\n", texto, resetar);
        }

        if (opcao == 2)
        {
        ApagarLinha(5);
        printf("%s    Azul%s\n", texto, resetar);
        printf("%s>>> Verde%s\n", fundo, resetar);
        printf("%s    Vermelho%s\n", texto, resetar);
        printf("%s    Amarelo%s\n", texto, resetar);
        printf("%s    Roxo%s\n", texto, resetar);
        }

        if (opcao == 3)
        {
        ApagarLinha(5);
        printf("%s    Azul%s\n", texto, resetar);
        printf("%s    Verde%s\n", texto, resetar);
        printf("%s>>> Vermelho%s\n", fundo, resetar);
        printf("%s    Amarelo%s\n", texto, resetar);
        printf("%s    Roxo%s\n", texto, resetar);
        }

        if (opcao == 4)
        {
        ApagarLinha(5);
        printf("%s    Azul%s\n", texto, resetar);
        printf("%s    Verde%s\n", texto, resetar);
        printf("%s    Vermelho%s\n", texto, resetar);
        printf("%s>>> Amarelo%s\n", fundo, resetar);
        printf("%s    Roxo%s\n", texto, resetar);
        }

        if (opcao == 5)
        {
        ApagarLinha(5);
        printf("%s    Azul%s\n", texto, resetar);
        printf("%s    Verde%s\n", texto, resetar);
        printf("%s    Vermelho%s\n", texto, resetar);
        printf("%s    Amarelo%s\n", texto, resetar);
        printf("%s>>> Roxo%s\n", fundo, resetar);
        }

        char tecla = _getch();
        if (tecla == 0)
        {
            tecla = _getch();
            if (tecla == 72 && opcao > 1)
                opcao--;
            else if (tecla == 80 && opcao < 5)
                opcao++;
        }
        else if (tecla == 13) break;
    }

    FILE *arquivo = fopen("configuracoes/fundo_do_menu.txt", "w");
    if (arquivo == NULL) {
        perror("Não foi possível abrir o arquivo");
        return;
    }

    else if (opcao == 1) {
        fprintf(arquivo, "\\033[44m");
        fclose(arquivo);
    }
    else if (opcao == 2) {
        fprintf(arquivo, "\\033[42m");
        fclose(arquivo);
    }
    else if (opcao == 3) {
        fprintf(arquivo, "\\033[41m");
        fclose(arquivo);
    }
    else if (opcao == 4)
    {
        fprintf(arquivo, "\\033[43m");
        fclose(arquivo);
    }
    else if (opcao == 5)
    {
        fprintf(arquivo, "\\033[45m");
        fclose(arquivo);
    }
    ApagarLinha(6);
}

void CorDoTextoMenuConfig() {
    const char* fundo = CorDeDestaqueMenu();
    const char* texto = CorDoTextoMenu();
    const char* resetar = reset();
    int opcao = 1;

    printf("%sEscolha uma cor para o texto do menu:%s\n", texto, resetar);
    printf("\n\n\n\n\n");
    while (1)
    {

        if (opcao == 1)
        {
        ApagarLinha(5);
        printf("%s>>> Cinza%s\n", fundo, resetar);
        printf("\033[32m    Verde%s\n", resetar);
        printf("\033[36m    Ciano%s\n", resetar);
        printf("\033[33m    Amarelo%s\n", resetar);
        printf("\033[31m    Vermelho%s\n", resetar);
        }

        if (opcao == 2)
        {
        ApagarLinha(5);
        printf("\033[90m    Cinza%s\n", resetar);
        printf("%s>>> Verde%s\n", fundo, resetar);
        printf("\033[36m    Ciano%s\n", resetar);
        printf("\033[33m    Amarelo%s\n", resetar);
        printf("\033[31m    Vermelho%s\n", resetar);
        }

        if (opcao == 3)
        {
        ApagarLinha(5);
        printf("\033[90m    Cinza%s\n", resetar);
        printf("\033[32m    Verde%s\n", resetar);
        printf("%s>>> Vermelho%s\n", fundo, resetar);
        printf("\033[33m    Amarelo%s\n", resetar);
        printf("\033[31m    Vermelho%s\n", resetar);
        }

        if (opcao == 4)
        {
        ApagarLinha(5);
        printf("\033[90m    Cinza%s\n", resetar);
        printf("\033[32m    Verde%s\n", resetar);
        printf("\033[36m    Ciano%s\n", resetar);
        printf("%s>>> Amarelo%s\n", fundo, resetar);
        printf("\033[31m    Vermelho%s\n", resetar);
        }

        if (opcao == 5)
        {
        ApagarLinha(5);
        printf("\033[90m    Cinza%s\n", resetar);
        printf("\033[32m    Verde%s\n", resetar);
        printf("\033[36m    Ciano%s\n", resetar);
        printf("\033[33m    Amarelo%s\n", resetar);
        printf("%s>>> Vermelho%s\n", fundo, resetar);
        }

        char tecla = _getch();
        if (tecla == 0)
        {
            tecla = _getch();
            if (tecla == 72 && opcao > 1)
                opcao--;
            else if (tecla == 80 && opcao < 5)
                opcao++;
        }
        else if (tecla == 13) break;
    }

    FILE *arquivo = fopen("configuracoes/texto_do_menu.txt", "w");
    if (arquivo == NULL) {
        perror("Não foi possível abrir o arquivo");
        return;
    }

    else if (opcao == 1) {
        fprintf(arquivo, "\\033[90m");
        fclose(arquivo);
    }
    else if (opcao == 2) {
        fprintf(arquivo, "\\033[32m");
        fclose(arquivo);
    }
    else if (opcao == 3) {
        fprintf(arquivo, "\\033[36m");
        fclose(arquivo);
    }
    else if (opcao == 4)
    {
        fprintf(arquivo, "\\033[33m");
        fclose(arquivo);
    }
    else if (opcao == 5)
    {
        fprintf(arquivo, "\\033[31m");
        fclose(arquivo);
    }
    ApagarLinha(6);

}

void CorDeFundoJogoConfig() {
    const char* fundo = CorDeDestaqueMenu();
    const char* texto = CorDoTextoMenu();
    const char* resetar = reset();
    int opcao = 1;

    printf("%sEscolha uma cor para o texto em destaque no jogo:%s\n", texto, resetar);
    printf("\n\n\n\n\n");
    while (1)
    {

        if (opcao == 1)
        {
            ApagarLinha(5);
            printf("%s>>> Cinza%s\n", fundo, resetar);
            printf("\033[32m    Verde%s\n", resetar);
            printf("\033[36m    Ciano%s\n", resetar);
            printf("\033[33m    Amarelo%s\n", resetar);
            printf("\033[31m    Vermelho%s\n", resetar);
        }

        if (opcao == 2)
        {
            ApagarLinha(5);
            printf("\033[90m    Cinza%s\n", resetar);
            printf("%s>>> Verde%s\n", fundo, resetar);
            printf("\033[36m    Ciano%s\n", resetar);
            printf("\033[33m    Amarelo%s\n", resetar);
            printf("\033[31m    Vermelho%s\n", resetar);
        }

        if (opcao == 3)
        {
            ApagarLinha(5);
            printf("\033[90m    Cinza%s\n", resetar);
            printf("\033[32m    Verde%s\n", resetar);
            printf("%s>>> Vermelho%s\n", fundo, resetar);
            printf("\033[33m    Amarelo%s\n", resetar);
            printf("\033[31m    Vermelho%s\n", resetar);
        }

        if (opcao == 4)
        {
            ApagarLinha(5);
            printf("\033[90m    Cinza%s\n", resetar);
            printf("\033[32m    Verde%s\n", resetar);
            printf("\033[36m    Ciano%s\n", resetar);
            printf("%s>>> Amarelo%s\n", fundo, resetar);
            printf("\033[31m    Vermelho%s\n", resetar);
        }

        if (opcao == 5)
        {
            ApagarLinha(5);
            printf("\033[90m    Cinza%s\n", resetar);
            printf("\033[32m    Verde%s\n", resetar);
            printf("\033[36m    Ciano%s\n", resetar);
            printf("\033[33m    Amarelo%s\n", resetar);
            printf("%s>>> Vermelho%s\n", fundo, resetar);
        }

        char tecla = _getch();
        if (tecla == 0)
        {
            tecla = _getch();
            if (tecla == 72 && opcao > 1)
                opcao--;
            else if (tecla == 80 && opcao < 5)
                opcao++;
        }
        else if (tecla == 13) break;
    }

    FILE *arquivo = fopen("configuracoes/destaque_do_jogo.txt", "w");
    if (arquivo == NULL) {
        perror("Não foi possível abrir o arquivo");
        return;
    }

    else if (opcao == 1) {
        fprintf(arquivo, "\\033[90m");
        fclose(arquivo);
    }
    else if (opcao == 2) {
        fprintf(arquivo, "\\033[32m");
        fclose(arquivo);
    }
    else if (opcao == 3) {
        fprintf(arquivo, "\\033[36m");
        fclose(arquivo);
    }
    else if (opcao == 4)
    {
        fprintf(arquivo, "\\033[33m");
        fclose(arquivo);
    }
    else if (opcao == 5)
    {
        fprintf(arquivo, "\\033[31m");
        fclose(arquivo);
    }
    ApagarLinha(6);
}

void CorDoTextoJogoConfig() {
    const char* fundo = CorDeDestaqueMenu();
    const char* texto = CorDoTextoMenu();
    const char* resetar = reset();
    int opcao = 1;

    printf("%sEscolha uma cor para o texto do jogo:%s\n", texto, resetar);
    printf("\n\n\n\n\n");
    while (1)
    {

        if (opcao == 1)
        {
            ApagarLinha(5);
            printf("%s>>> Cinza%s\n", fundo, resetar);
            printf("\033[32m    Verde%s\n", resetar);
            printf("\033[36m    Ciano%s\n", resetar);
            printf("\033[33m    Amarelo%s\n", resetar);
            printf("\033[31m    Vermelho%s\n", resetar);
        }

        if (opcao == 2)
        {
            ApagarLinha(5);
            printf("\033[90m    Cinza%s\n", resetar);
            printf("%s>>> Verde%s\n", fundo, resetar);
            printf("\033[36m    Ciano%s\n", resetar);
            printf("\033[33m    Amarelo%s\n", resetar);
            printf("\033[31m    Vermelho%s\n", resetar);
        }

        if (opcao == 3)
        {
            ApagarLinha(5);
            printf("\033[90m    Cinza%s\n", resetar);
            printf("\033[32m    Verde%s\n", resetar);
            printf("%s>>> Vermelho%s\n", fundo, resetar);
            printf("\033[33m    Amarelo%s\n", resetar);
            printf("\033[31m    Vermelho%s\n", resetar);
        }

        if (opcao == 4)
        {
            ApagarLinha(5);
            printf("\033[90m    Cinza%s\n", resetar);
            printf("\033[32m    Verde%s\n", resetar);
            printf("\033[36m    Ciano%s\n", resetar);
            printf("%s>>> Amarelo%s\n", fundo, resetar);
            printf("\033[31m    Vermelho%s\n", resetar);
        }

        if (opcao == 5)
        {
            ApagarLinha(5);
            printf("\033[90m    Cinza%s\n", resetar);
            printf("\033[32m    Verde%s\n", resetar);
            printf("\033[36m    Ciano%s\n", resetar);
            printf("\033[33m    Amarelo%s\n", resetar);
            printf("%s>>> Vermelho%s\n", fundo, resetar);
        }

        char tecla = _getch();
        if (tecla == 0)
        {
            tecla = _getch();
            if (tecla == 72 && opcao > 1)
                opcao--;
            else if (tecla == 80 && opcao < 5)
                opcao++;
        }
        else if (tecla == 13) break;
    }

    FILE *arquivo = fopen("configuracoes/texto_do_jogo.txt", "w");
    if (arquivo == NULL) {
        perror("Não foi possível abrir o arquivo");
        return;
    }

    else if (opcao == 1) {
        fprintf(arquivo, "\\033[90m");
        fclose(arquivo);
    }
    else if (opcao == 2) {
        fprintf(arquivo, "\\033[32m");
        fclose(arquivo);
    }
    else if (opcao == 3) {
        fprintf(arquivo, "\\033[36m");
        fclose(arquivo);
    }
    else if (opcao == 4)
    {
        fprintf(arquivo, "\\033[33m");
        fclose(arquivo);
    }
    else if (opcao == 5)
    {
        fprintf(arquivo, "\\033[31m");
        fclose(arquivo);
    }
    ApagarLinha(6);

}


int Menu() {
    const char* fundo = CorDeDestaqueMenu();
    const char* texto = CorDoTextoMenu();
    const char* resetar = reset();

    int opcao = 1;
    printf("\n\n\n\n\n");

    while (1)
    {
        ApagarLinha(6);

        if (opcao == 1)
        {
            printf("%sEscolha uma opção:%s\n", texto, resetar);
            printf("%s>>> Escolher cor do texto em destaque do menu%s\n", fundo, resetar);
            printf("%s    Escolher cor do texto do menu%s\n", texto, resetar);
            printf("%s    Escolher cor do texto destaque nos jogos%s\n", texto, resetar);
            printf("%s    Escolher cor do texto nos jogos%s\n", texto, resetar);
            printf("%s    Sair%s\n", texto, resetar);
        }

        if (opcao == 2)
        {
            printf("%sEscolha uma opção:%s\n", texto, resetar);
            printf("%s    Escolher cor do texto em destaque do menu%s\n", texto, resetar);
            printf("%s>>> Escolher cor do texto do menu%s\n", fundo, resetar);
            printf("%s    Escolher cor do texto destaque nos jogos%s\n", texto, resetar);
            printf("%s    Escolher cor do texto nos jogos%s\n", texto, resetar);
            printf("%s    Sair%s\n", texto, resetar);
        }

        if (opcao == 3)
        {
            printf("%sEscolha uma opção:%s\n", texto, resetar);
            printf("%s    Escolher cor do texto em destaque do menu%s\n", texto, resetar);
            printf("%s    Escolher cor do texto do menu%s\n", texto, resetar);
            printf("%s>>> Escolher cor do texto destaque nos jogos%s\n", fundo, resetar);
            printf("%s    Escolher cor do texto nos jogos%s\n", texto, resetar);
            printf("%s    Sair%s\n", texto, resetar);
        }
        
        if (opcao == 4)
        {
            printf("%sEscolha uma opção:%s\n", texto, resetar);
            printf("%s    Escolher cor do texto em destaque do menu%s\n", texto, resetar);
            printf("%s    Escolher cor do texto do menu%s\n", texto, resetar);
            printf("%s    Escolher cor do texto destaque nos jogos%s\n", texto, resetar);
            printf("%s>>> Escolher cor do texto nos jogos%s\n", fundo, resetar);
            printf("%s    Sair%s\n", texto, resetar);

        }

        if (opcao == 5)
        {
            printf("%sEscolha uma opção:%s\n", texto, resetar);
            printf("%s    Escolher cor do texto em destaque do menu%s\n", texto, resetar);
            printf("%s    Escolher cor do texto do menu%s\n", texto, resetar);
            printf("%s    Escolher cor do texto destaque nos jogos%s\n", texto, resetar);
            printf("%s    Escolher cor do texto nos jogos%s\n", texto, resetar);
            printf("%s>>> Sair%s\n", fundo, resetar);
        }

        char tecla = _getch();
        if (tecla == 0)
        {
            tecla = _getch();
            if (tecla == 72 && opcao > 1)
                opcao--;
            else if (tecla == 80 && opcao < 5)
                opcao++;
        }
        else if (tecla == 13)
            break;
    }

    ApagarLinha(6);
    return opcao;
}


int main() {
    int opcao;

    system("cls");
    while (1)
    {
        opcao = Menu();
        if (opcao == 1)  CorDeDestaqueMenuConfig();
        if (opcao == 2)  CorDoTextoMenuConfig();
        if (opcao == 3)  CorDeFundoJogoConfig();
        if (opcao == 4)  CorDoTextoJogoConfig();
        if (opcao == 5)
        {
            printf("Retornando ao menu");
            for (int i = 0; i < 3; i++)
            {
                printf(".");
                Sleep(800);
            }
            break;
        }
    }
    system("game_house.exe");

    return 0;
}