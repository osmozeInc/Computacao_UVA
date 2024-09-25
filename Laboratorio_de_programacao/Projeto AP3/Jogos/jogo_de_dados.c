#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "..\configuracoes\configuracoes.h"


void JogoDeDados() 
{
    system("cls || clear");
    printf("\e[15C|[====================================================================]|  \n");
    printf("\e[15C||                                                                    ]|  \n");
    printf("\e[15C||                              DADOS                                 ]|  \n");
    printf("\e[15C||                       ADIVINHE O RESULTADO                         ]|  \n");
    printf("\e[15C||                                                                    ]|  \n");
    printf("\e[15C|[====================================================================]|  \n\n\n");
}


void OpcoesDoJogo(int numero_de_dados, int aposta) 
{
    printf("jogando com %d dados\n", numero_de_dados);
    printf("Numero apostado: %d\n\n", aposta);
}


int Preparacao(int *numero_de_dados, int *aposta)
{
    OpcoesDoJogo(*numero_de_dados, *aposta);
    printf("com quantos dados quer jogar? ");
    scanf("%d", numero_de_dados);
    ApagarLinha(4);
    
    OpcoesDoJogo(*numero_de_dados, *aposta);
    printf("faça sua aposta entre 1 e %d\n>>> ", *numero_de_dados * 6);
    scanf("%d", aposta);
    ApagarLinha(5);

}


int JogarDados(int  numero_de_dados, int aposta)
{
        printf("jogando dados");
        for (int i = 0; i < 3; i++)
        {
            printf(".");
            Sleep(800);
        }
        printf("\e[K\n");
        ApagarLinha(2);

        srand(time(NULL));
        int dado = rand() % (numero_de_dados * 6) + 1;
        printf("\nO resultado foi %d\n", dado);
        if (dado == aposta) 
        {
            printf(">>> VOCÊ GANHOU! <<<");
            return 100 * numero_de_dados;
        }
        else 
        {
            printf(">>> VOCÊ PERDEU! <<<");
            return 0;
        }
}


int main() {
    int pontuacao = 0;
    int resposta = 1;

    while (resposta != 2)
    {
        int numero_de_dados = 0;
        int aposta = 0;

        JogoDeDados();
        Preparacao(&numero_de_dados, &aposta);
        OpcoesDoJogo(numero_de_dados, aposta);
        pontuacao += JogarDados(numero_de_dados, aposta);
        LimparBuffer();
        resposta = JogarNovamante();
    }

    //resposta = EscolherRegistrar(pontuacao);
    //if (resposta == 1) RegistrarPlacar(pontuacao, 'D');

    printf(">>> Retornando ao menu\n");
    Sleep(3000);

    system("game_house.exe");
}