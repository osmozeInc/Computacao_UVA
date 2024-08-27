#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "..\configuracoes\configuracoes.h"

void ApagarLinha(int numero_de_linhas) 
{
    for (int i = 0; i < numero_de_linhas; i++)
    {
        printf("\e[A\e[K");
    }
}


void JogoDaVelha() 
{
    system("cls || clear");
    printf("\n");
    printf("\e[15C|[====================================================================]|  \n");
    printf("\e[15C||                                                                    ]|  \n");
    printf("\e[15C||                        JOGO DA VELHA                               ]|  \n");
    printf("\e[15C||                                                                    ]|  \n");
    printf("\e[15C|[====================================================================]|  \n\n\n");
}


int OpcoesDoJogo() 
{
    int opcao = 1;

    printf("Jogador 1: \'X\' ou \'O\' ?\n\n\n\n");    
    while (1)
    {
        ApagarLinha(2);
        if (opcao == 1)
        {
            printf("\e[32m>>> X\e[0m\n");
            printf("\e[90m    O\e[0m\n");
        }

        else if (opcao == 2)
        {
            printf("\e[90m    X\e[0m\n");
            printf("\e[32m>>> O\e[0m\n");
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

    ApagarLinha(4);
    if (opcao == 1) return 'X';
    if (opcao == 2) return 'O';
}


char DefinirAdversario(char jogador)
{
        if (jogador == 'X') {
            return 'O';
        }
        else {
            return 'X';
        }
}


void RealizarJogada(char tabuleiro[3][3], char jogador_ou_adversario, int player)
{
    int coluna, linha;

    printf("Jogador %d\n", player);
    printf("Ecolha uma posição\n");
    while (1)
    {
        while (1)
        {
            printf("Coluna: ");
            scanf("%d", &coluna);
            if (coluna < 1 || coluna > 3) printf("\e[A\e[K");
            else break;
        }
        
        while (1)
        {
            printf("Linha: ");
            scanf("%d", &linha);
            if (linha < 1 || linha > 3) printf("\e[A\e[K");
            else break;
        }

        if (tabuleiro[linha - 1][coluna - 1] == ' '){
            tabuleiro[linha - 1][coluna - 1] = jogador_ou_adversario;
            break;
        }
        else {
            printf("espaço ocupado, tente de novo\n");
            Sleep(2000);
            ApagarLinha(5);
        }
    }
}


int VerificarVitoria(char tabuleiro[3][3], char ganhador)
{
    for (int i = 0; i < 3; i++)
    {
        if ((tabuleiro[i][0] == ganhador && tabuleiro[i][1] == ganhador && tabuleiro[i][2] == ganhador) || (tabuleiro[0][i] == ganhador && tabuleiro[1][i] == ganhador && tabuleiro[2][i] == ganhador))
        {
            return 1;
        }
    }

    if ((tabuleiro[0][0] == ganhador && tabuleiro[1][1] == ganhador && tabuleiro[2][2] == ganhador) || (tabuleiro[0][2] == ganhador && tabuleiro[1][1] == ganhador && tabuleiro[2][0] == ganhador))
    {
        return 1;
    }
    
    return 0;
}


void DesenharJogo(char tabuleiro[3][3])
{
    system("cls || clear");
        printf("\e[15C   1   2   3\n");
        printf("\e[15C 1 %c | %c | %c \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
        printf("\e[15C  ---|---|---\n");
        printf("\e[15C 2 %c | %c | %c \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
        printf("\e[15C  ---|---|---\n");
        printf("\e[15C 3 %c | %c | %c \n\n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);

}


int Jogar(char jogador, char adversario)
{
    char tabuleiro[3][3] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    int fim_do_jogo = 0;

    while (1)
    {
        DesenharJogo(tabuleiro) ;       
        RealizarJogada(tabuleiro, jogador, 1);
        fim_do_jogo = VerificarVitoria(tabuleiro, jogador);
        if (fim_do_jogo){
            fim_do_jogo = 1;
            break;
        }
        
        DesenharJogo(tabuleiro);
        RealizarJogada(tabuleiro, adversario, 2);
        fim_do_jogo = VerificarVitoria(tabuleiro, adversario);
        if (fim_do_jogo){
            fim_do_jogo = -1;
            break;
        }   
    }

    DesenharJogo(tabuleiro);
    if (fim_do_jogo > 0) printf("\nVITORIA DO JOGADOR 1");
    else if (fim_do_jogo < 0) printf("\nVITORIA DO JOGADOR 2");
    return 15;
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
            else if (tecla == 80 && opcao < 3)
                opcao++;
        }
        else if (tecla == 13)
            break;
    }

    ApagarLinha(5);
    return opcao;
}

int main() {
    char jogador = 0;
    int adversario = 0;
    int pontuacao = 0;

    while (1)
    {
        JogoDaVelha();
        jogador = OpcoesDoJogo();
        adversario = DefinirAdversario(jogador);
        pontuacao += Jogar(jogador, adversario);
        
        int resposta = JogarNovamante();
        if (resposta == 2) break;
    }

    printf("\n\n>>> Sua pontuação foi de %d pontos\n", pontuacao);
    Sleep(2000);
    printf(">>> Retornando ao menu\n");
    Sleep(3000);

    system("game_house.exe");
}