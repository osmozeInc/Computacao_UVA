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
    const char* texto = corDoTextoMenu();
    const char* resetar = reset();
    int opcao = 1;

    while (1)
    {
        printff("Escolha uma cor de fundo para o menu:\n");
        printf("\n\n\n\n\n\n");

        if (opcao == 1)
        {
        ApagarLinha(6);
        printf("%s>>> Azul%s\n", fundo, resetar);
        printf("%s    Verde%s\n", texto, resetar);
        printf("%s    Vermelho%s\n", texto, resetar);
        printf("%s    Amarelo%s\n", texto, resetar);
        printf("%s    Roxo%s\n", texto, resetar);
        }

        if (opcao == 2)
        {
        ApagarLinha(6);
        printf("%s    Azul%s\n", texto, resetar);
        printf("%s>>> Verde%s\n", fundo, resetar);
        printf("%s    Vermelho%s\n", texto, resetar);
        printf("%s    Amarelo%s\n", texto, resetar);
        printf("%s    Roxo%s\n", texto, resetar);
        }

        if (opcao == 3)
        {
        ApagarLinha(6);
        printf("%s    Azul%s\n", texto, resetar);
        printf("%s    Verde%s\n", texto, resetar);
        printf("%s>>> Vermelho%s\n", fundo, resetar);
        printf("%s    Amarelo%s\n", texto, resetar);
        printf("%s    Roxo%s\n", texto, resetar);
        }

        if (opcao == 4)
        {
        ApagarLinha(6);
        printf("%s    Azul%s\n", texto, resetar);
        printf("%s    Verde%s\n", texto, resetar);
        printf("%s    Vermelho%s\n", texto, resetar);
        printf("%s>>> Amarelo%s\n", fundo, resetar);
        printf("%s    Roxo%s\n", texto, resetar);
        }

        if (opcao == 5)
        {
        ApagarLinha(6);
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
    else {
        fprintf(arquivo, "\\033[44m\n\\033[37m\n\\033[47m\n\\033[30m");
        fclose(arquivo);
    }




}

void CorDoTextoMenuConfig() {

}

void CorDeFundoJogoConfig() {
}

void CorDoTextoJogoConfig() {
}


void ReceberConfiguracoes() {
    FILE *arquivo = fopen("configuracoes/configuracoes.txt", "r");
    if (arquivo == NULL) {
        perror("Não foi possível abrir o arquivo");
        return;
    }

    char corFundoMenu[20]; // Buffer para a cor de fundo do menu
    char corTextoMenu[20]; // Buffer para a cor do texto do menu
    char corFundoJogo[20]; // Buffer para a cor de fundo do jogo
    char corTextoJogo[20]; // Buffer para a cor do texto do jogo

    // Lê a primeira linha e armazena na variável corFundoMenu
    if (fgets(corFundoMenu, sizeof(corFundoMenu), arquivo) == NULL) {
        perror("Erro ao ler a configuração de cor de fundo do menu");
        fclose(arquivo);
        return;
    }

    // Remove o caractere de nova linha, se presente
    corFundoMenu[strcspn(corFundoMenu, "\n")] = 0;

    // Lê a segunda linha e armazena na variável corTextoMenu
    if (fgets(corTextoMenu, sizeof(corTextoMenu), arquivo) == NULL) {
        perror("Erro ao ler a configuração de cor do texto do menu");
        fclose(arquivo);
        return;
    }

    // Remove o caractere de nova linha, se presente
    corTextoMenu[strcspn(corTextoMenu, "\n")] = 0;

    // Lê a terceira linha e armazena na variável corFundoJogo
    if (fgets(corFundoJogo, sizeof(corFundoJogo), arquivo) == NULL) {
        perror("Erro ao ler a configuração de cor de fundo do jogo");
        fclose(arquivo);
        return;
    }

    // Remove o caractere de nova linha, se presente
    corFundoJogo[strcspn(corFundoJogo, "\n")] = 0;

    // Lê a quarta linha e armazena na variável corTextoJogo
    if (fgets(corTextoJogo, sizeof(corTextoJogo), arquivo) == NULL) {
        perror("Erro ao ler a configuração de cor do texto do jogo");
        fclose(arquivo);
        return;
    }

    // Remove o caractere de nova linha, se presente
    corTextoJogo[strcspn(corTextoJogo, "\n")] = 0;

    fclose(arquivo);

    // Exibir as cores lidas
    printf("Cor de fundo do menu: %s\n", corFundoMenu);
    printf("Cor do texto do menu: %s\n", corTextoMenu);
    printf("Cor de fundo do jogo: %s\n", corFundoJogo);
    printf("Cor do texto do jogo: %s\n", corTextoJogo);
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
        }

        if (opcao == 2)
        {
            printf("Escolha uma opção:\n");
            printf("%s    Escolher cor do texto em destaque do menu%s\n", texto, resetar);
            printf("%s>>> Escolher cor do texto do menu%s\n", fundo, resetar);
            printf("%s    Escolher cor do texto destaque nos jogos%s\n", texto, resetar);
            printf("%s    Escolher cor do texto nos jogos%s\n", texto, resetar);
        }

        if (opcao == 3)
        {
            printf("Escolha uma opção:\n");
            printf("%s    Escolher cor do texto em destaque do menu%s\n", texto, resetar);
            printf("%s    Escolher cor do texto do menu%s\n", texto, resetar);
            printf("%s>>> Escolher cor do texto destaque nos jogos%s\n", fundo, resetar);
            printf("%s    Escolher cor do texto nos jogos%s\n", texto, resetar);
        }
        
        if (opcao == 4)
        {
            printf("Escolha uma opção:\n");
            printf("%s    Escolher cor do texto em destaque do menu%s\n", texto, resetar);
            printf("%s    Escolher cor do texto do menu%s\n", texto, resetar);
            printf("%s    Escolher cor do texto destaque nos jogos%s\n", texto, resetar);
            printf("%s>>> Escolher cor do texto nos jogos%s\n", fundo, resetar);
        }

        char tecla = _getch();
        if (tecla == 0)
        {
            tecla = _getch();
            if (tecla == 72 && opcao > 1)
                opcao--;
            else if (tecla == 80 && opcao < 4)
                opcao++;
        }
        else if (tecla == 13)
            break;
    }

    return opcao;
}

int main() {
    int opcao;

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