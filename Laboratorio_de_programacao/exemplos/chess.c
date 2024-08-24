#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VAZIO 0

typedef enum {REI_B=1,RAINHA_B,TORRE_B,BISPO_B,CAVALO_B,PEAO_B,
			  REI_P,  RAINHA_P,TORRE_P,BISPO_P,CAVALO_P,PEAO_P} Tipo;
typedef enum {P=44, B=46} Cor;
typedef int Peca;

Peca tabuleiro[8][8] = {VAZIO};

void reset() {
	Peca peca[32] = {TORRE_P,CAVALO_P,BISPO_P,RAINHA_P, REI_P,BISPO_P,CAVALO_P,TORRE_P,
					  PEAO_P,  PEAO_P, PEAO_P,  PEAO_P,PEAO_P, PEAO_P,  PEAO_P, PEAO_P,
					  PEAO_B,  PEAO_B, PEAO_B,  PEAO_B,PEAO_B, PEAO_B,  PEAO_B, PEAO_B,
					 TORRE_B,CAVALO_B,BISPO_B,RAINHA_B, REI_B,BISPO_B,CAVALO_B,TORRE_B};
	int i, j, p = 0;
	for (i = 0; i < 2; i++)
		for (j = 0; j < 8; j++, p++)
			tabuleiro[i][j] = peca[p];
	for (i = 6; i < 8; i++)
		for (j = 0; j < 8; j++, p++)
			tabuleiro[i][j] = peca[p];	
}

void printPeca(Peca p, Cor fundo) {
	switch (p) {
		case REI_B:
			printf("\e[%dm \u2654 \e[m", fundo);
			break;
		case RAINHA_B:
			printf("\e[%dm \u2655 \e[m", fundo);
			break;
		case TORRE_B:
			printf("\e[%dm \u2656 \e[m", fundo);
			break;
		case BISPO_B:
			printf("\e[%dm \u2657 \e[m", fundo);
			break;
		case CAVALO_B:
			printf("\e[%dm \u2658 \e[m", fundo);
			break;
		case PEAO_B:
			printf("\e[%dm \u2659 \e[m", fundo);
			break;
		case REI_P:
			printf("\e[%dm \u265a \e[m", fundo);
			break;
		case RAINHA_P:
			printf("\e[%dm \u265b \e[m", fundo);
			break;
		case TORRE_P:
			printf("\e[%dm \u265c \e[m", fundo);
			break;
		case BISPO_P:
			printf("\e[%dm \u265d \e[m", fundo);
			break;
		case CAVALO_P:
			printf("\e[%dm \u265e \e[m", fundo);
			break;
		case PEAO_P:
			printf("\e[%dm \u265f \e[m", fundo);
			break;
	}
}

void show() {
	int i, j, l = 8;
	char c[] = " abcdefgh";
	
	for (j = 0; j < 9; j++)
		printf(" %c ", c[j]);
	printf("\n");

	for (i = 0; i < 8; i++) {
		printf(" %d ",l--);

		for (j = 0; j < 8; j++) {
			if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) {
				
				if (tabuleiro[i][j])
					printPeca(tabuleiro[i][j], B);
				else
					printf("\e[46m   \e[m");
			}
			else {

				if (tabuleiro[i][j])
					printPeca(tabuleiro[i][j], P);
				else
					printf("\e[44m   \e[m");
			}
		}
		printf("\n");
	}
}

int main() {
	reset();
	show();
	return 0;
}
