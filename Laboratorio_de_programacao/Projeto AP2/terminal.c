#include <stdio.h>
#include <stdlib.h>

// Função para escolher o sistema
int Systema()
{
    int sistema;

    printf("Qual seu sistema?\n");
    printf("1 - Windows\n");
    printf("2 - Linux ou Mac\n");
    printf("3 - Sair\n");

    scanf("%d", &sistema);
    return sistema;
}

int main() {
    system("cls || clear");

    int sistema = Systema();

    if (sistema == 1) {
        system("cd Proj_windows && gcc main_wind.c");  // apagar após terminar o código
        system("cd Proj_windows && main_wind.exe");

    } else if (sistema == 2) {
        system("cd ~/Proj_linux_mac && ./main");

    } else if (sistema == 3) {
        printf("Saindo...\n");
        return 0;

    } else {
        printf("Opção inválida!\n");
    }

    return 0;
}
