#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main(){
    system("chcp 65001");
    system("cls || clear");

    printf("iniciando programa");
    for (int i = 0; i < 3; i++)
    {
        printf(".");
        Sleep(800);
    }
    
    system("gcc configuracoes/configuracoes.c game_house.c -o game_house.exe");
    system("gcc configuracoes/configuracoes.c configuracoes/configurar_cores.c -o configuracoes/configurar_cores.exe");
    system("gcc configuracoes/configuracoes.c Jogos/jogo_da_velha.c -o Jogos/jogo_da_velha.exe");
    system("gcc configuracoes/configuracoes.c Jogos/jogo_da_forca.c -o Jogos/jogo_da_forca.exe");
    system("gcc configuracoes/configuracoes.c Jogos/jogo_de_21.c -o Jogos/jogo_de_21.exe");
    system("gcc configuracoes/configuracoes.c Jogos/jogo_de_dados.c -o Jogos/jogo_de_dados.exe");

    printf("\nprograma iniciado com sucesso!\n");
    system("game_house.exe");
}