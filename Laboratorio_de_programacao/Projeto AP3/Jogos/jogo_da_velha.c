#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "..\configuracoes\configuracoes.h"


void JogoDaVelha() 
{
    system("cls || clear");
    printf("\n");
    printf("\e[15C|[====================================================================]|  \n");
    printf("\e[15C|[                                                                    ]|  \n");
    printf("\e[15C|[                        JOGO DA VELHA                               ]|  \n");
    printf("\e[15C|[                                                                    ]|  \n");
    printf("\e[15C|[====================================================================]|  \n\n\n");
}


int OpcoesDoJogo() 
{
    const char* fundo = CorDeDestaqueJogo();
    const char* texto = CorDoTextoJogo();
    const char* resetar = reset();
    char tecla_char;
    int tecla_int;
    int opcao = 1;

    printf("Jogador 1: \'X\' ou \'O\' ?\n\n\n\n\n\n");    
    while (1)
    {
        ApagarLinha(4);
        if (opcao == 1)
        {
            printf("%s1. X (enter)%s\n", fundo, resetar);
            printf("%s2. O%s\n", texto, resetar);
            printf("%s>>>: %s", texto, resetar);
        }

        else if (opcao == 2)
        {
            printf("%s1. X%s\n", texto, resetar);
            printf("%s2. O (enter)%s\n", fundo, resetar);
            printf("%s>>>: %s", texto, resetar);
        }

        tecla_char = getchar();
        if (tecla_char == '\n')
            break;
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
    const char* fundo = CorDeDestaqueJogo();
    const char* texto = CorDoTextoJogo();
    const char* resetar = reset();
    int coluna, linha;

    printf("%sJogador %d\n",texto, player);
    printf("Ecolha uma posição%s\n", resetar);
    while (1)
    {
        while (1)
        {
            printf("%sLinha: %s", texto, resetar);
            scanf("%d", &linha);
            if (linha < 1 || linha > 3) printf("\e[A\e[K");
            else break;
        }

        while (1)
        {
            printf("%sColuna: %s", texto, resetar);
            scanf("%d", &coluna);
            if (coluna < 1 || coluna > 3) printf("\e[A\e[K");
            else break;
        }
        
        if (tabuleiro[linha - 1][coluna - 1] == ' '){
            tabuleiro[linha - 1][coluna - 1] = jogador_ou_adversario;
            break;
        }
        else {
            printf("%sespaço ocupado, tente de novo%s\n", texto, resetar);
            Sleep(2000);
            ApagarLinha(4);
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
    
    int espacos_vazios = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tabuleiro[i][j] == ' ')
            {
                espacos_vazios++;
            }
        }
    }
    if (espacos_vazios == 0) return 0;

    return 2;
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
        if (fim_do_jogo == 1){
            fim_do_jogo = 1;
            break;
        }
        else if (fim_do_jogo == 0){
            fim_do_jogo = 0;
            break;
        }
        
        DesenharJogo(tabuleiro);
        RealizarJogada(tabuleiro, adversario, 2);
        fim_do_jogo = VerificarVitoria(tabuleiro, adversario);
        if (fim_do_jogo == 1){
            fim_do_jogo = -1;
            break;
        }   
    }

    DesenharJogo(tabuleiro);
    if (fim_do_jogo > 0) printf("\nVITORIA DO JOGADOR 1");
    else if (fim_do_jogo < 0) printf("\nVITORIA DO JOGADOR 2");
    else if  (fim_do_jogo == 0) {
        printf("\nEMPATE");
        return 0;
    }

    return 15;
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
        LimparBuffer();
        int resposta = JogarNovamante();
        if (resposta == 2) break;
    }

    int resposta = EscolherRegistrar(pontuacao);
    //if (resposta == 1) RegistrarPlacar(pontuacao, 'V');

    printf(">>> Retornando ao menu\n");
    Sleep(3000);

    system("game_house.exe");
}