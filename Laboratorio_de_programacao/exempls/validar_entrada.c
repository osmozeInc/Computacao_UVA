#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validarOpcaoNumerica(int inicioIntervalo, int fimIntervalo, int valorSaida) {
    
    char opcaoDigitado[20];
    char valorSaidaString[20];
    int opcao = 0;

    // Transforma 'valorSaida' de inteiro para string
    sprintf(valorSaidaString, "%d", valorSaida);

    while (1) {
        // Salva a posicao atual do cursor
        printf("\e[s");

        // Le a opcao como uma string
        scanf("%s", opcaoDigitado);

        // Digitou 'valorSaida' para sair
        if (strcmp(opcaoDigitado, valorSaidaString) == 0) {
            break;
        }
        else {
            // Converte a string lida em um inteiro
            opcao = atoi(opcaoDigitado);

            if (opcao < inicioIntervalo || opcao > fimIntervalo) {
                printf("\e[u"); // Restaura a posicao do cursor salva anteriormente
                printf("\e[K"); // Limpa da posicao atual do cursor ate o final da linha
            }
            else
                break;
                
        }
    }

    return opcao;
}

int main () {
    int numeroDigitado;
    printf("Digite um numero entre 3 e 12 (digite 0 para sair)\n");
    
    printf("--> ");
    numeroDigitado = validarOpcaoNumerica(3, 12, 0);

    printf("O numero digitado foi %d\n", numeroDigitado);
    return 0;
}