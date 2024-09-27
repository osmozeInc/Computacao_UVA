#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../configuracoes/configuracoes.h"
#include "./ranking.h"

void CriarArquivo()
{
        FILE *arquivo = fopen("ranking.txt", "r");
        if (arquivo == NULL)
        {
            arquivo = fopen("ranking.txt", "w");
            fprintf(arquivo, "JOGADOR         PONTUAÇÃO      JOGO\n-----------------------------------------\n");
            fclose(arquivo);
        }
        fclose(arquivo);
}

void SubistituirPontuacao(char nome[11], char senha[9])
{
    // aqui vai ser substituido a pontuação do usuário
    printf("Usuário encontrado. Pontuação substituída.\n");
}

void BuscarUsuario(char nome[11], char senha[9])
{
    LimparBuffer();
    char linha_arquivo[25]; 
    char linha_procurada[25];
    sprintf(linha_procurada, "%s,%s", nome, senha);

    FILE *arquivo = fopen("ranking/usuario_senha.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while (fgets(linha_arquivo, sizeof(linha_arquivo), arquivo) != NULL)
    {
        if (strstr(linha_arquivo, linha_procurada) != NULL)
        {
            SubistituirPontuacao(nome, senha);
            break;
        }
    }
    if (feof(arquivo)) printf("Fim do arquivo.\n");
}

int Config_EscolherRegistrar(int pontuacao)
{
    const char* fundo = CorDeDestaqueMenu();
    const char* texto = CorDoTextoMenu();
    const char* resetar = reset();
    char tecla_char;
    int tecla_int;
    int opcao = 1;

    system("cls || clear");
    printf("\n%sSua pontuação foi de %d pontos%s\n",texto, pontuacao, resetar);
    printf("%sQuer registrar o placar?%s\n\n", texto, resetar);
    
    while (1)
    {
        if (opcao == 1)
        {
            printf("%s1. Registrar como anônimo%s\n", fundo, resetar);
            printf("%s2. Registrar como novo jogador%s\n", texto, resetar);
            printf("%s3. Registrar como jogador existente%s\n", texto, resetar);
            printf("%s4. Não registrar%s\n", texto, resetar);
            printf("%sEscolha uma opção:  %s", texto, resetar);
        }

        else if (opcao == 2)
        {
            printf("%s1. Registrar como anônimo%s\n", texto, resetar);
            printf("%s2. Registrar como novo jogador%s\n", fundo, resetar);
            printf("%s3. Registrar como jogador existente%s\n", texto, resetar);
            printf("%s4. Não registrar%s\n", texto, resetar);
            printf("%sEscolha uma opção:  %s", texto, resetar);
        }

        else if (opcao == 3)
        {
            printf("%s1. Registrar como anônimo%s\n", texto, resetar);
            printf("%s2. Registrar como novo jogador%s\n", texto, resetar);
            printf("%s3. Registrar como jogador existente%s\n", fundo, resetar);
            printf("%s4. Não registrar%s\n", texto, resetar);
            printf("%sEscolha uma opção:  %s", texto, resetar);
        }

        else if (opcao == 4)
        {
            printf("%s1. Registrar como anônimo%s\n", texto, resetar);
            printf("%s2. Registrar como novo jogador%s\n", texto, resetar);
            printf("%s3. Registrar como jogador existente%s\n", texto, resetar);
            printf("%s4. Não registrar%s\n", fundo, resetar);
            printf("%sEscolha uma opção:  %s", texto, resetar);
        }

        tecla_char = getchar();
        if (tecla_char == '\n')
            break;
        else{
            tecla_int = tecla_char - '0';
            if (tecla_int >= 1 && tecla_int <= 4){
                opcao = tecla_int;
                getchar();
                printf("\n");
            }
            else{
                printf("\n");
                getchar();
            }
        }
        ApagarLinha(6);
    }

    return opcao;
}

void Config_RegistrarPlacar(int resposta, int pontuacao, int jogo)
{
    const char* fundo = CorDeDestaqueMenu();
    const char* texto = CorDoTextoMenu();
    const char* resetar = reset();

    if (resposta == 1) // Registrar como anônimo
    {
        char nome[8] = "Anônimo";
        if (jogo == 1) Config_RegistrarInformacoesJV("Anônimo", pontuacao, "Jogo da velha");
        if (jogo == 2) Config_RegistrarInformacoesJD("Anônimo", pontuacao, "Jogo de dados");
    }

    else if (resposta == 2) // Registrar como novo jogador
    {
        char nome[11], senha[9];

        printf("\n%sEscolha seu nickname: ", texto);
        scanf("%10s", nome);
        printf("\nEscolha uma senha: %s", resetar);
        scanf("%8s", senha);

        if (jogo == 1) Config_RegistrarInformacoesJV(nome, pontuacao, "Jogo da velha");
        if (jogo == 2) Config_RegistrarInformacoesJD(nome, pontuacao, "Jogo de dados");
        Config_UsuarioSenha(nome, senha);
    }

    else if (resposta == 3) // Registrar como jogador existente
    {
        char nome[11], senha[9];

        printf("\n%sQual seu nickname: ", texto);
        scanf("%10s", nome);
        printf("\nQual sua senha: ");
        scanf("%8s", senha);

        BuscarUsuario(nome, senha);

        int resposta;
        scanf("%d", &resposta);
    }

    else if (resposta == 4) // Não registrar
    {
        // placar não será registrado
    }
}

void Config_RegistrarInformacoesJV(char nome[11], int pontuacao, char jogo[15])
{
    FILE *arquivo = fopen("./ranking/rankingJV.txt", "a+");
    fprintf(arquivo, "%-15s %-10d %s\n", nome, pontuacao, jogo);
    fclose(arquivo);
}

void Config_RegistrarInformacoesJD(char nome[11], int pontuacao, char jogo[15])
{

    FILE *arquivo = fopen("./ranking/rankingJD.txt", "a+");
    fprintf(arquivo, "%-15s %-10d %s\n", nome, pontuacao, jogo);
    fclose(arquivo);
}

void Config_UsuarioSenha(char nome[11], char senha[9])
{
    FILE *arquivo = fopen("ranking/usuario_senha.txt", "a");
    fprintf(arquivo, "%s,%s\n", nome, senha);
    fclose(arquivo);
}


