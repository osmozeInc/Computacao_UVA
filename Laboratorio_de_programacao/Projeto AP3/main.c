#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main(){
    system("chcp 65001");
    system("cls || clear");
    char mensagem[22] = "iniciando programa...";

    for (int i = 0; i < 22; i++)
    {
        printf("%c", mensagem[i]);
        Sleep(100);
    }
    
    system("gcc configuracoes/configuracoes.c ranking/ranking.c game_house.c -o game_house.exe");
    system("gcc configuracoes/configuracoes.c ranking/ranking.c Jogos/jogo_da_velha.c -o Jogos/jogo_da_velha.exe");
    system("gcc configuracoes/configuracoes.c ranking/ranking.c Jogos/jogo_de_dados.c -o Jogos/jogo_de_dados.exe");
    system("gcc configuracoes/configuracoes.c ranking/ranking.c configuracoes/configurar_cores.c -o configuracoes/configurar_cores.exe");
    system("gcc configuracoes/configuracoes.c ranking/ranking.c ranking/placar_ranking.c -o ranking/placar_ranking.exe");

    system("game_house.exe");
}