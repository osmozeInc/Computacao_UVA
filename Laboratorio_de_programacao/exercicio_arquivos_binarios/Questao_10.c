#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int vetor[11] = {10};
    int vetor_recebido[11];
    FILE *arq;
    srand(time(NULL));

    for(int i = 1; i < 11; i++)
        vetor[i] = rand() % 100;

    arq = fopen("binarinho.bb", "wb");
    fwrite(vetor, sizeof(int), 11, arq);
    fclose(arq);

    arq = fopen("binarinho.bb", "rb");
    fread(vetor_recebido, sizeof(int), 11, arq);

    printf("tamanho do vetor: %d \nVetor = {", vetor_recebido[0]);
    for (int i = 1; i < 11; i++)
    {
        printf("%d, ", vetor_recebido[i]);
        if (i == 10) printf("\b\b}");
    }
}
