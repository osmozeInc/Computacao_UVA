#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "..\configuracoes.h"


void JogoDeDados() 
{
    printf("\e[15C|[====================================================================]|  \n");
    printf("\e[15C||                                                                    ]|  \n");
    printf("\e[15C||                              DADOS                                 ]|  \n");
    printf("\e[15C||                       ADIVINHE O RESULTADO                         ]|  \n");
    printf("\e[15C||                                                                    ]|  \n");
    printf("\e[15C|[====================================================================]|  \n\n\n");
}

void ApagarLinha(int numero_de_linhas) 
{
    for (int i = 0; i < numero_de_linhas; i++)
    {
        printf("\e[A");
        printf("\e[K");
    }
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
    printf("faça sua aposta entre 1 e %d\n>>>", *numero_de_dados * 6);
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
        
        int dado = time(NULL) % numero_de_dados * 6 + 1;
        printf("\n\nO resultado foi %d\n", dado);
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

int JogarNovamante(const char* fundo, const char* texto, const char* resetar)
{
    int opcao = 1;
        printf("\n\n>>> Deseja jogar novamente? \n");
        printf("%s>>> Sim%s\n", fundo, resetar);
        printf("%s    Não%s\n", texto, resetar);

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

    return 0;
}

int main() {
    const char* fundo = CorDeFundo();
    const char* texto = CorDoTexto();
    const char* resetar = reset();

    int numero_de_dados = 0;
    int aposta = 0;
    int pontuacao = 0;

    system("chcp 65001");
    system("cls || clear");

    JogoDeDados();
    while (1)
    {
        Preparacao(&numero_de_dados, &aposta);
        OpcoesDoJogo(numero_de_dados, aposta);
        pontuacao += JogarDados(numero_de_dados, aposta);
        JogarNovamante(fundo, texto, resetar);
    }
}