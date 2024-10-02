#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "..\configuracoes\configuracoes.h"


void JogoDeDados() 
{
    const char* resetar = reset();
    system("cls || clear");
    printf("%s", resetar);
    printf("\e[15C|[====================================================================]|  \n");
    printf("\e[15C||                                                                    ]|  \n");
    printf("\e[15C||                              DADOS                                 ]|  \n");
    printf("\e[15C||                       ADIVINHE O RESULTADO                         ]|  \n");
    printf("\e[15C||                                                                    ]|  \n");
    printf("\e[15C|[====================================================================]|  \n\n\n");
}

void OpcoesDoJogo(int numero_de_dados, int aposta) 
{
    const char* texto = CorDoTextoMenu();
    const char* resetar = reset();

    printf("%sjogando com %d dados\n", texto, numero_de_dados);
    printf("Numero apostado: %d%s\n\n", aposta, resetar);
}

int Preparacao(int *numero_de_dados, int *aposta)
{
    const char* texto = CorDoTextoMenu();
    const char* resetar = reset();

    OpcoesDoJogo(*numero_de_dados, *aposta);
    printf("%scom quantos dados quer jogar? ", texto);
    scanf("%d", numero_de_dados);
    ApagarLinha(4);
    
    OpcoesDoJogo(*numero_de_dados, *aposta);
    printf("%sfaça sua aposta entre 1 e %d\n>>> ", texto, *numero_de_dados * 6);
    scanf("%d", aposta);
    ApagarLinha(5);

}

int JogarDados(int  numero_de_dados, int aposta)
{
    const char* texto = CorDoTextoMenu();
    const char* resetar = reset();

    printf("%sjogando dados", texto);
    for (int i = 0; i < 3; i++)
    {
        printf(".");
        Sleep(800);
    }
    printf("\e[K\n");
    ApagarLinha(2);

    srand(time(NULL));
    int dado = rand() % (numero_de_dados * 6) + 1;
    printf("\n%sO resultado foi %d\n%s", texto, dado, resetar);
    if (dado == aposta) 
    {
        printf("%s>>> VOCÊ GANHOU! <<<%s", texto, resetar);
        return 25 * numero_de_dados;
    }
    else 
    {
        printf("%s>>> VOCÊ PERDEU! <<<%s", texto, resetar);
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
        JogoDeDados(); // cabeçalho do jogo
        Preparacao(&numero_de_dados, &aposta); // define as caracteristicas do jogo (quantidade de dados e aposta)
        OpcoesDoJogo(numero_de_dados, aposta); // faz parte do layout do jogo
        pontuacao += JogarDados(numero_de_dados, aposta); 
        LimparBuffer();
        resposta = JogarNovamente(); // se não, retorna 2
    }
    if (pontuacao > 0) Ranking(pontuacao, 2); // registro do placar

}