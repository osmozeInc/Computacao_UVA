#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "configuracoes.h"


void CorDeDestaqueMenuConfig() {
    const char* fundo = CorDeDestaqueMenu();
    const char* texto = CorDoTextoMenu();
    const char* resetar = reset();
    char tecla_char;
    int tecla_int, opcao = 1;

    system("cls || clear");
    printf("%sEscolha uma cor de fundo para o menu:%s\n", texto, resetar);
    printf("\n\n\n\n\n\n\n");
    while (1)
    {
        ApagarLinha(7);

        if (opcao == 1)
        {
            printf("%s1. Azul (enter)%s\n", fundo, resetar);
            printf("%s2. Verde\n", texto);
            printf("3. Vermelho\n");
            printf("4. Amarelo\n");
            printf("5. Roxo\n");
            printf("Escolha uma opção: ");
        }

        if (opcao == 2)
        {
            printf("%s1. Azul\n", texto);
            printf("%s2. Verde (enter)%s\n", fundo, resetar);
            printf("%s3. Vermelho\n", texto);
            printf("4. Amarelo\n");
            printf("5. Roxo\n");
            printf("Escolha uma opção: ");
        }

        if (opcao == 3)
        {
            printf("%s1. Azul\n", texto);
            printf("2. Verde%s\n", resetar);
            printf("%s3. Vermelho (enter)%s\n", fundo, resetar);
            printf("%s4. Amarelo\n", texto);
            printf("5. Roxo\n");
            printf("Escolha uma opção: ");
        }

        if (opcao == 4)
        {
            printf("%s1. Azul\n", texto);
            printf("2. Verde\n");
            printf("3. Vermelho%s\n", resetar);
            printf("%s4. Amarelo (enter)%s\n", fundo, resetar);
            printf("%s5. Roxo\n", texto);
            printf("Escolha uma opção: ");
        }

        if (opcao == 5)
        {
            printf("%s1. Azul\n", texto);
            printf("2. Verde\n");
            printf("3. Vermelho\n");
            printf("4. Amarelo%s\n", resetar);
            printf("%s5. Roxo (enter)%s\n", fundo, resetar);
            printf("%sEscolha uma opção: ", texto);
        }

        tecla_char = getchar();
        if (tecla_char == '\n') break;
        else
        {
            tecla_int = tecla_char - '0';
            if (tecla_int >= 1 && tecla_int <= 5)
            {
                opcao = tecla_int;
                getchar();
                printf("\n");
            }
            else
            {
                getchar();
                printf("\n");
            }
        }
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
    char tecla_char;
    int tecla_int, opcao = 1;

    system("cls || clear");
    printf("%sEscolha uma cor para o texto do menu:%s\n", texto, resetar);
    printf("\n\n\n\n\n\n\n");

    while (1)
    {
        ApagarLinha(7);

        if (opcao == 1)
        {
        printf("%s1. Cinza (enter)%s\n", fundo, resetar);
        printf("\033[32m2. Verde%s\n", resetar);
        printf("\033[36m3. Ciano%s\n", resetar);
        printf("\033[33m4. Amarelo%s\n", resetar);
        printf("\033[31m5. Vermelho%s\n", resetar);
        printf("%sEscolha uma opção: ", texto);
        }

        if (opcao == 2)
        {
        printf("\033[90m1. Cinza%s\n", resetar);
        printf("%s2. Verde (enter)%s\n", fundo, resetar);
        printf("\033[36m3. Ciano%s\n", resetar);
        printf("\033[33m4. Amarelo%s\n", resetar);
        printf("\033[31m5. Vermelho%s\n", resetar);
        printf("%sEscolha uma opção: ", texto);
        }

        if (opcao == 3)
        {
        printf("\033[90m1. Cinza%s\n", resetar);
        printf("\033[32m2. Verde%s\n", resetar);
        printf("%s3. Ciano (enter)%s\n", fundo, resetar);
        printf("\033[33m4. Amarelo%s\n", resetar);
        printf("\033[31m5. Vermelho%s\n", resetar);
        printf("%sEscolha uma opção: ", texto);
        }

        if (opcao == 4)
        {
        printf("\033[90m1. Cinza%s\n", resetar);
        printf("\033[32m2. Verde%s\n", resetar);
        printf("\033[36m3. Ciano%s\n", resetar);
        printf("%s4. Amarelo (enter)%s\n", fundo, resetar);
        printf("\033[31m5. Vermelho%s\n", resetar);
        printf("%sEscolha uma opção: ", texto);
        }

        if (opcao == 5)
        {
        printf("\033[90m1. Cinza%s\n", resetar);
        printf("\033[32m2. Verde%s\n", resetar);
        printf("\033[36m3. Ciano%s\n", resetar);
        printf("\033[33m4. Amarelo%s\n", resetar);
        printf("%s5. Vermelho (enter)%s\n", fundo, resetar);
        printf("%sEscolha uma opção: ", texto);
        }

        tecla_char = getchar();
        if (tecla_char == '\n') break;
        else
        {
            tecla_int = tecla_char - '0';
            if (tecla_int >= 1 && tecla_int <= 5)
            {
                opcao = tecla_int;
                getchar();
                printf("\n");
            }
            else
            {
                getchar();
                printf("\n");
            }
        }
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
}

int Menu() {
    const char* fundo = CorDeDestaqueMenu();
    const char* texto = CorDoTextoMenu();
    const char* resetar = reset();
    char tecla_char;
    int tecla_int, opcao = 1;

    system("cls || clear");
    printf("%sMenu de personalização de cores\n", texto);
    printf("\n\n\n\n\n");

    while (1)
    {
        ApagarLinha(5);

        if (opcao == 1)
        {
            printf("%s1. Escolher cor do texto em destaque do menu (enter)%s\n", fundo, resetar);
            printf("%s2. Escolher cor do texto do menu\n", texto);
            printf("3. Sair\n");
            printf("Escolha uma opção: ");
        }

        if (opcao == 2)
        {
            printf("%s1. Escolher cor do texto em destaque do menu%s\n", texto, resetar);
            printf("%s2. Escolher cor do texto do menu (enter)%s\n", fundo, resetar);
            printf("%s3. Sair\n", texto);
            printf("Escolha uma opção: ");
        }

        if (opcao == 3)
        {
            printf("%s1. Escolher cor do texto em destaque do menu\n", texto);
            printf("2. Escolher cor do texto do menu%s\n", resetar);
            printf("%s3. Sair (enter)%s\n", fundo, resetar);
            printf("%sEscolha uma opção: ", texto);
        }
        
        tecla_char = getchar();
        if (tecla_char == '\n') break;
        else
        {
            tecla_int = tecla_char - '0';
            if (tecla_int >= 1 && tecla_int <= 3)
            {
                opcao = tecla_int;
                getchar();
                printf("\n");
            }
            else
            {
                getchar();
                printf("\n");
            }
        }
    }
    return opcao;
}


int main() {

    system("cls");
    while (1)
    {
        int opcao;
        opcao = Menu();
        if (opcao == 1)  CorDeDestaqueMenuConfig();
        if (opcao == 2)  CorDoTextoMenuConfig();
        if (opcao == 3) // Sair
        {
            char mensagem[22] = "Retornando ao menu...";
            for (int i = 0; i < 22; i++)
            {
                printf("%c", mensagem[i]);
                Sleep(100);
            }
            break;
        }
    }
}