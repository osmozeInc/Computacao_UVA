#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include "configuracoes.h"


void ApagarLinha(int numero_de_linhas) 
{
    for (int i = 0; i < numero_de_linhas; i++)
    {
        printf("\e[A\e[K");
    }
}


void CorDeDestaqueMenuConfig() {
    const char* fundo = CorDeDestaqueMenu();
    const char* texto = CorDoTextoMenu();
    const char* resetar = reset();
    int opcao = 1;

    printf("Escolha uma cor de fundo para o menu:\n");
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

}

void CorDoTextoMenuConfig() {

}

void CorDeFundoJogoConfig() {
}

void CorDoTextoJogoConfig() {
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
            printf("Escolha uma opção:\n");
            printf("%s>>> Escolher cor do texto em destaque do menu%s\n", fundo, resetar);
            printf("%s    Escolher cor do texto do menu%s\n", texto, resetar);
            printf("%s    Escolher cor do texto destaque nos jogos%s\n", texto, resetar);
            printf("%s    Escolher cor do texto nos jogos%s\n", texto, resetar);
            printf("%s    Sair%s\n", texto, resetar);
        }

        if (opcao == 2)
        {
            printf("Escolha uma opção:\n");
            printf("%s    Escolher cor do texto em destaque do menu%s\n", texto, resetar);
            printf("%s>>> Escolher cor do texto do menu%s\n", fundo, resetar);
            printf("%s    Escolher cor do texto destaque nos jogos%s\n", texto, resetar);
            printf("%s    Escolher cor do texto nos jogos%s\n", texto, resetar);
            printf("%s    Sair%s\n", texto, resetar);
        }

        if (opcao == 3)
        {
            printf("Escolha uma opção:\n");
            printf("%s    Escolher cor do texto em destaque do menu%s\n", texto, resetar);
            printf("%s    Escolher cor do texto do menu%s\n", texto, resetar);
            printf("%s>>> Escolher cor do texto destaque nos jogos%s\n", fundo, resetar);
            printf("%s    Escolher cor do texto nos jogos%s\n", texto, resetar);
            printf("%s    Sair%s\n", texto, resetar);
        }
        
        if (opcao == 4)
        {
            printf("Escolha uma opção:\n");
            printf("%s    Escolher cor do texto em destaque do menu%s\n", texto, resetar);
            printf("%s    Escolher cor do texto do menu%s\n", texto, resetar);
            printf("%s    Escolher cor do texto destaque nos jogos%s\n", texto, resetar);
            printf("%s>>> Escolher cor do texto nos jogos%s\n", fundo, resetar);
            printf("%s    Sair%s\n", texto, resetar);

        }

        if (opcao == 5)
        {
            printf("Escolha uma opção:\n");
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
            printf("É necessário reiniciar o programa para aplicar as alterações.\n");
            Sleep(1000);
            printf("Fechando...\n");
            Sleep(1000);
            printf("Execute novamente o programa\n");
            break;
        }
    }

    return 0;
}