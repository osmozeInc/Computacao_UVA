#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

// Define as setas do teclado
#define UP_ARROW 65
#define DOWN_ARROW 66
#define ENTER 10

// Códigos ANSI para cor de fundo verde e amarelo
#define GREEN_BG "\033[42m"
#define YELLOW_BG "\033[48;5;226m"
#define RESET "\033[0m"

void desativarBufferDeEntrada() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~(ICANON | ECHO);  // Desativa entrada canônica e eco
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void ativarBufferDeEntrada() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= ICANON | ECHO;  // Ativa entrada canônica e eco
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void printMenu(int selected) {
    system("clear");  // Limpa a tela

    printf("Use as setas para navegar e Enter para selecionar:\n\n");

    if (selected == 0) 
        printf(GREEN_BG " -> 1. Opção 1" RESET "\n");
    else 
        printf("    1. Opção 1\n");

    if (selected == 1) 
        printf(GREEN_BG " -> 2. Opção 2" RESET "\n");
    else 
        printf("    2. Opção 2\n");

    if (selected == 2) 
        printf(GREEN_BG " -> 3. Opção 3" RESET "\n");
    else 
        printf("    3. Opção 3\n");
}

int main() {
    int selected = 0;
    char key;

    desativarBufferDeEntrada();  // Desativa o buffer de entrada

    while (1) {
        printMenu(selected);

        key = getchar();  // Lê o caractere

        if (key == '\033') {  // Se a tecla for uma sequência de escape
            getchar();        // Ignora o caractere '['
            switch(getchar()) {
                case UP_ARROW:
                    if (selected > 0) selected--;
                    break;
                case DOWN_ARROW:
                    if (selected < 2) selected++;
                    break;
            }
        } else if (key == ENTER) {
            break;  // Sai do loop se a tecla Enter for pressionada
        }
    }

    ativarBufferDeEntrada();  // Reativa o buffer de entrada

    printf("\nVocê selecionou a Opção %d\n", selected + 1);

    return 0;
}
