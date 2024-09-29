#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "../configuracoes/configuracoes.h"
#include "./ranking.h"

void NomeRanking()
{
    const char* resetar = reset();
    system("cls || clear");
    printf("%s", resetar);
    printf(" ____                                                   \n");
    printf("|  _  \\             _   __ _                           \n");
    printf("| |_| |  __ _ _ __ | | / /|_| _ __    ___ _             \n");
    printf("|     / / _` | '_ \\| |/ /  _ | '_ \\  / _ ' |          \n");
    printf("| |\\_\\ | (_| | | | | |\\ \\ | || | | || (_)  |        \n");
    printf("|_| \\_\\ \\__,_|_| |_|_| \\_\\|_||_| |_| \\___| |      \n");
    printf("                                       __| |            \n");
    printf("                                      |____/            \n");
    
}

int Menu() 
{
    const char* fundo = CorDeDestaqueMenu();
    const char* texto = CorDoTextoMenu();
    const char* resetar = reset();
    char tecla_char;
    int tecla_int, opcao = 1;

    printf("\n\n\n\n\n\n\n");

    while (1)
    {
        ApagarLinha(7);
        if (opcao == 1)
        {
            printf("%s1. Ranking geral (enter)%s\n", fundo, resetar);
            printf("%s2. Resetar ranking do jogo da velha\n", texto);
            printf("3. Resetar ranking do jogo de dados\n");
            printf("4. Excluir ranking\n");
            printf("5. Voltar\n");
            printf("Escolha uma opção: ");
        }
        else if (opcao == 2)
        {
            printf("%s1. Ranking geral\n%s", texto, resetar);
            printf("%s2. Resetar ranking do jogo da velha (enter)%s\n", fundo, resetar);
            printf("%s3. Resetar ranking do jogo de dados\n", texto);
            printf("4. Excluir ranking\n");
            printf("5. Voltar\n");
            printf("Escolha uma opção: ");
        }
        else if (opcao == 3)
        {
            printf("%s1. Ranking geral\n", texto);
            printf("2. Resetar ranking do jogo da velha%s\n", resetar);
            printf("%s3. Resetar ranking do jogo de dados (enter)%s\n", fundo, resetar);
            printf("%s4. Excluir ranking\n", texto);
            printf("5. Voltar\n");
            printf("Escolha uma opção: ");
        }
        else if (opcao == 4)
        {
            printf("%s1. Ranking geral\n", texto);
            printf("2. Resetar ranking do jogo da velha\n");
            printf("3. Resetar ranking do jogo de dados%s\n", resetar);
            printf("%s4. Excluir ranking (enter)%s\n", fundo, resetar);
            printf("%s5. Voltar\n", texto);
            printf("Escolha uma opção: ");
        }
        else if (opcao == 5)
        {
            printf("%s1. Ranking geral\n", texto);
            printf("2. Resetar ranking do jogo da velha\n");
            printf("3. Resetar ranking do jogo de dados\n");
            printf("4. Excluir ranking%s\n", resetar);
            printf("%s5. Voltar (enter)%s\n", fundo, resetar);
            printf("%sEscolha uma opção: ", texto);
        }

        tecla_char = getchar();
        if (tecla_char == '\n') break;
        else{
            tecla_int = tecla_char - '0';
            if (tecla_int >= 1 && tecla_int <= 5)
            {
                opcao = tecla_int;
                getchar();
                printf("\n");
            }
            else{
                getchar();
                printf("\n");
            }
        }
    }
    return opcao;
}

int Confirmacao() // confitma se eu realmente quero fazer uma ação
{
    const char* fundo = CorDeDestaqueMenu();
    const char* texto = CorDoTextoMenu();
    const char* resetar = reset();
    char tecla_char;
    int tecla_int, opcao = 1;

    printf("\n\n\n\n\n\n");

    while (1)
    {
        ApagarLinha(5);

        if (opcao == 1)
        {
            printf("%sTem certeza que deseja realizar esta ação?%s\n", texto, resetar);
            printf("%s1. Sim (enter)%s\n", fundo, resetar);
            printf("%s2. Não\n", texto);
            printf(">>> ");
        }

        else if (opcao == 2)
        {
            printf("%sTem certeza que deseja realizar esta ação?\n", texto);
            printf("1. Sim\n%s", resetar);
            printf("%s2. Não (enter)%s\n", fundo, resetar);
            printf("%s>>> ", texto);
        }

        tecla_char = getchar();
        if (tecla_char == '\n') break;
        else{
            tecla_int = tecla_char - '0';
            if (tecla_int >= 1 && tecla_int <= 2)
            {
                opcao = tecla_int;
                getchar();
                printf("\n");
            }
            else{
                getchar();
                printf("\n");
            }
        }
    }
    return opcao;
}

void MostrarRanking() // abre os dois arquivos e mostra o ranking no terminal
{
    const char* resetar = reset();
    system("cls || clear");
    printf("%s", resetar);

    FILE *arquivo1 = fopen("./ranking/rankingJV.txt", "r");
    FILE *arquivo2 = fopen("./ranking/rankingJD.txt", "r");

    printf("JOGADOR      PONTUAÇÃO              JOGO\n");
    printf("----------------------------------------\n");
    char linha[50];
    while (fgets(linha, sizeof(linha), arquivo1) != NULL)
    {
        printf("%s", linha);
    }

    printf("----------------------------------------\n");

    while (fgets(linha, sizeof(linha), arquivo2) != NULL)
    {
        printf("%s", linha);
    }
    printf("\n");

    printf("Pressione enter para continuar...");
    getchar();

    fclose(arquivo1);
    fclose(arquivo2);
}

void ResetarRankingJV()
{
    int resposta = Confirmacao();
    if (resposta == 1)
    {
        FILE *arquivo = fopen("./ranking/rankingJV.txt", "w");
        fclose(arquivo);
        printf("Ranking resetado com sucesso!\n");
    }
    else
    {
        printf("Operação cancelada!\n");
    }
    Sleep(2000);
}

void ResetarRankingJD()
{
    int resposta = Confirmacao();
    if (resposta == 1)
    {
        FILE *arquivo = fopen("./ranking/rankingJD.txt", "w");
        fclose(arquivo);
        printf("Ranking resetado com sucesso!\n");
    }
    else
    {
        printf("Operação cancelada!\n");
    }
    Sleep(2000);
}

void ExcluirRanking()
{
    int resposta = Confirmacao();
    if (resposta == 1)
    {
        remove("./ranzing/rankingJV.txt");
        remove("./ranzing/rankingJD.txt");
        remove("./ranzing/usuario_senha.txt");
        printf("Ranking excluído com sucesso!\n");
    }
    else
    {
        printf("Operação cancelada!\n");
    }
}


int main() {
    int resposta = 0;

    while (resposta != 4)
    {
        NomeRanking();
        resposta = Menu();

        if (resposta == 1) MostrarRanking();
        else if (resposta == 2) ResetarRankingJV(); // reabre o arquivo modo escrita subistindo o conteudo anterior
        else if (resposta == 3) ResetarRankingJD(); // reabre o arquivo modo escrita subistindo o conteudo anterior
        else if (resposta == 4) ExcluirRanking(); // exclui os dois arquivos que guardam os rankings
        else if (resposta == 5) break; // retorna ao menu principal
    }
}