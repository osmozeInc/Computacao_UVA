#include <stdio.h>

int main() {
    printf("\033[10;10H"); // Mover o cursor para a linha 10, coluna 10
    printf("Texto na posição (10, 10)\n");

    scanf("%*c"); // Aguardar a entrada do usuário
    printf("\033[2J"); // Limpar a tela

    return 0;
}
