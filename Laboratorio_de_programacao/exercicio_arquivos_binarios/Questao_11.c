#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int vetor_lido[11];
    int vetor_novo[10];
    FILE *arq;
    srand(time(NULL));

    arq = fopen("binarinho.bb", "rb");
    fread(vetor_lido, sizeof(int), 11, arq);
    fclose(arq);

    arq = fopen("binarinho.bb", "wb+");
    fwrite(vetor_novo, sizeof(int), 10, arq);
    fclose(arq);


    arq = fopen("binarinho.bb", "wb+");
    fwrite(vetor_novo, sizeof(int), 10, arq);
    fclose(arq);


    printf("VETOR LIDO:\n");
    printf("tamanho do vetor: %d \nVetor = {", vetor_lido[0]);
    for (int i = 1; i < 11; i++)
    {
        printf("%d, ", vetor_lido[i]);
        if (i == 10) printf("\b\b}\n\n");
    }

    printf("VETOR NOVO:\n");
    printf("tamanho do vetor: %d \nVetor = {", vetor_lido[0]);
    for (int i = 1; i < 11; i++)
    {
        printf("%d, ", vetor_lido[i]);
        if (i == 10) printf("\b\b}\n");
    }
}
