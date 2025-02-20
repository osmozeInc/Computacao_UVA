#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


static char palavra_secreta[12];   // palavra que deve ser descorberta
static char palavra_usuario[12];   // palavra que o jogador deve adivinhar
static char letras_digitadas[15];

void BuscarPalavra(){
    char palavra_aleatoria[12];
    int contador_linha = 0;
    srand(time(NULL));
    int linha = rand() % 20 + 1;

    FILE* arquivo = fopen("jogo\\palavras_por_linha.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while (fgets(palavra_aleatoria, sizeof(palavra_aleatoria), arquivo))
    {
        contador_linha++;
        if (contador_linha == linha) {
            printf("%d-%s-", linha, palavra_aleatoria);
            break;
        }
    }

    fclose(arquivo);
    strcpy(palavra_secreta, palavra_aleatoria);
}

void DefinirTamanhoPalavra(){
    int tamanho = strlen(palavra_secreta);

    for (int i = 0; i < tamanho; i++)
    {
        if (palavra_secreta[i] != '\n')
            palavra_usuario[i] = '_';
        else{
            palavra_usuario[i] = '\0';
            palavra_secreta[i] = '\0';
            // evita bugs que ocorriam
        }
    }
}

int VerificarLetra(){
    int houve_acerto = 0;
    char letra;

    // O espaço antes do %c faz com que o scanf ignore espaços em branco e caracteres de nova linha (\n), garantindo que apenas a letra digitada seja capturada.
    printf("Digite uma letra: ");
    scanf(" %c", &letra);

    // falta verificar se a letra ja foi digitada
    letras_digitadas[strlen(letras_digitadas)] = letra;

    for (int i = 0; i < strlen(palavra_secreta); i++)
    {
        if (letra == palavra_secreta[i])
        {
            palavra_usuario[i] = letra;
            houve_acerto = 1;
        }
    }
    
    return houve_acerto;
}

void MensagemFinal(int tentativas){
    system("cls");

    if (tentativas == 0)
        printf("YOU LOSE!\n\n");
    else
        printf("YOU WIN!\n\n");

    printf("A Resposta era: %s", palavra_secreta);
}


int main(){
    int tentativas = 5;
    int acerto = 0;

    // escolhe uma palavra aleatória e define o tanto de hifens na palavra
    BuscarPalavra();
    DefinirTamanhoPalavra(palavra_secreta, palavra_usuario);

    for (int i = 0; i < tentativas; tentativas--)
    {
        system("cls");
        printf("Tentativas: %d", (tentativas));

        for (int i = 0; i < strlen(letras_digitadas); i++)
        {
            printf(" %c", letras_digitadas[i]);
        }
        
        printf("\nPalavra: %s\n", (palavra_usuario));
        acerto = VerificarLetra(palavra_secreta, palavra_usuario);

        if (acerto == 1){
            tentativas ++;

            if (strcmp(palavra_secreta, palavra_usuario) == 0)
                break;
        }
    }

    MensagemFinal(tentativas);
    
    return 0;
}