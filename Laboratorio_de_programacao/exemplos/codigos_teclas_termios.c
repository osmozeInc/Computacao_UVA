#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

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

int main() {
    int teclaPressionada;
    char k = 0;

    desativarBufferDeEntrada();
    
    while (1) {
        teclaPressionada = getchar();  // Lê o caractere

        if (teclaPressionada == '\e') {  // Se a tecla for uma sequência de escape
            getchar();  // Ignora o caractere '['
            
            k = getchar();
            printf("-> %d\n", k);
        } 
        else if (teclaPressionada == 10) {
            break;  // Sai do loop se a tecla Enter for pressionada
        }
        else {
            printf("-> %d\n", teclaPressionada);
        }
    }
    
    ativarBufferDeEntrada();
}