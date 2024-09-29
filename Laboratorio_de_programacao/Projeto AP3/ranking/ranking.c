#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "../configuracoes/configuracoes.h"
#include "./ranking.h"


typedef struct {
    char jogador[15];
    int pontuacao;
    char jogo[15];
} Registro;


void SubistituirPontuacao(char nome[11], int jogo, int pontuacao)
{
    char linha_nova[50], nome_do_arquivo[25];

    if (jogo == 1)
    {
        sprintf(linha_nova, "%-15s %-10d %s\n", nome, pontuacao, "Jogo da velha");
        sprintf(nome_do_arquivo, "./ranking/rankingJV.txt");
    } 

    if (jogo == 2) 
    {
        sprintf(linha_nova, "%-15s %-10d %s\n", nome, pontuacao, "Jogo de dados");
        sprintf(nome_do_arquivo, "./ranking/rankingJD.txt");
    }

    FILE *arquivo = fopen(nome_do_arquivo, "r"); // arquivo original
    FILE *temp = fopen("./ranking/temp.txt", "w"); // arquivo temporário

    if (arquivo == NULL || temp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha_lida[50]; // Buffer para armazenar cada linha lida

    

    
    while (fgets(linha_lida, sizeof(linha_lida), arquivo) != NULL) // Lê cada linha do arquivo original
    {
        if (strstr(linha_lida, nome)) // Verifica se a linha atual é a que deve ser substituída
        {
            fprintf(temp, "%s", linha_nova); // Se for, escreve a linha nova no arquivo temporário
        } 

        else 
        {
            fprintf(temp, "%s", linha_lida); // Caso contrário, escreve a linha original no arquivo temporário
        }
    }

    // Fecha os arquivos
    fclose(arquivo);
    fclose(temp);

    // Remove o arquivo original e renomeia o temporário para o nome original
    remove(nome_do_arquivo);
    rename("./ranking/temp.txt", nome_do_arquivo);


    printf("Usuário encontrado. Pontuação substituída.\n");
}

void BuscarUsuario(char nome[11], char senha[9], int jogo, int pontuacao)
{
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
            SubistituirPontuacao(nome, jogo, pontuacao);
            break;
        }
    }
    if (feof(arquivo)) printf("Fim do arquivo.\n");
    fclose(arquivo);
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
    printf("\n%sSua pontuação foi de %d pontos\n",texto, pontuacao);
    printf("Quer registrar o placar?\n\n");
    
    while (1)
    {
        if (opcao == 1)
        {
            printf("%s1. Registrar como anônimo%s\n", fundo, resetar);
            printf("%s2. Registrar como novo jogador\n", texto);
            printf("3. Registrar como jogador existente\n");
            printf("4. Não registrar\n");
            printf("Escolha uma opção: ");
        }

        else if (opcao == 2)
        {
            printf("%s1. Registrar como anônimo\n%s", texto, resetar);
            printf("%s2. Registrar como novo jogador%s\n", fundo, resetar);
            printf("%s3. Registrar como jogador existente\n", texto);
            printf("4. Não registrar\n");
            printf("Escolha uma opção: ");
        }

        else if (opcao == 3)
        {
            printf("%s1. Registrar como anônimo\n", texto);
            printf("2. Registrar como novo jogador%s\n", resetar);
            printf("%s3. Registrar como jogador existente%s\n", fundo, resetar);
            printf("%s4. Não registrar\n", texto);
            printf("Escolha uma opção: ");
        }

        else if (opcao == 4)
        {
            printf("%s1. Registrar como anônimo\n", texto);
            printf("2. Registrar como novo jogador\n");
            printf("3. Registrar como jogador existente%s\n", resetar);
            printf("%s4. Não registrar%s\n", fundo, resetar);
            printf("%sEscolha uma opção: ", texto);
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
        if (jogo == 1) Config_RegistrarInformacoesJV("Anônimo ", pontuacao, "Jogo da velha");
        if (jogo == 2) Config_RegistrarInformacoesJD("Anônimo ", pontuacao, "Jogo de dados");
        printf("\n%sPontuação registrada com sucesso!\n", texto);
        Sleep(2000);

    }

    else if (resposta == 2) // Registrar como novo jogador
    {
        char nome[11], senha[9];

        printf("\n%sEscolha seu nickname: ", texto);
        scanf("%10s", nome);
        printf("\nEscolha uma senha: ", resetar);
        scanf("%8s", senha);

        Config_UsuarioSenha(nome, senha);
        if (jogo == 1) Config_RegistrarInformacoesJV(nome, pontuacao, "Jogo da velha");
        if (jogo == 2) Config_RegistrarInformacoesJD(nome, pontuacao, "Jogo de dados");
        printf("\n%sUsuário registrado com sucesso!\n", texto);
        Sleep(2000);
    }

    else if (resposta == 3) // Registrar como jogador existente
    {
        char nome[11], senha[9];

        printf("\n%sQual seu nickname: ", texto);
        scanf("%10s", nome);
        printf("\nQual sua senha: ");
        scanf("%8s", senha);

        BuscarUsuario(nome, senha, jogo, pontuacao);
        printf("\n%sPontuação atualizada com sucesso!\n", texto);
        Sleep(2000);
    }

    else if (resposta == 4) // Não registrar
    {
        printf("\n%sPontuação não registrada.\n", texto);
        Sleep(2000);
    }
}

void Config_RegistrarInformacoesJV(char nome[11], int pontuacao, char jogo[15]) {
    FILE *arquivo = fopen("./ranking/rankingJV.txt", "r");

    if (arquivo == NULL) {
        arquivo = fopen("./ranking/rankingJV.txt", "w");
        fclose(arquivo);
        arquivo = fopen("./ranking/rankingJV.txt", "r");
    }

    Registro registros[100];
    int totalRegistros = 0;
    char linha[50];

    while (fgets(linha, sizeof(linha), arquivo) != NULL && totalRegistros < 100) {
        sscanf(linha, "%14s %d %[^\n]", registros[totalRegistros].jogador, &registros[totalRegistros].pontuacao, registros[totalRegistros].jogo);
        totalRegistros++;
    }
    fclose(arquivo);

    Registro novoRegistro;
    strncpy(novoRegistro.jogador, nome, 14);
    novoRegistro.pontuacao = pontuacao;
    strncpy(novoRegistro.jogo, jogo, 14);

    int posicaoInserir = totalRegistros;
    for (int i = 0; i < totalRegistros; i++) {
        if (registros[i].pontuacao < pontuacao) {
            posicaoInserir = i;
            break;
        }
    }

    arquivo = fopen("./ranking/rankingJV.txt", "w");

    for (int i = 0; i < totalRegistros + 1; i++) {
        if (i == posicaoInserir) {
            fprintf(arquivo, "%-15s %-10d %s\n", novoRegistro.jogador, novoRegistro.pontuacao, novoRegistro.jogo);
        }
        if (i < totalRegistros) {
            fprintf(arquivo, "%-15s %-10d %s\n", registros[i].jogador, registros[i].pontuacao, registros[i].jogo);
        }
    }

    fclose(arquivo);
}

void Config_RegistrarInformacoesJD(char nome[11], int pontuacao, char jogo[15]) {
    FILE *arquivo = fopen("./ranking/rankingJD.txt", "r");

    if (arquivo == NULL) {
        arquivo = fopen("./ranking/rankingJD.txt", "w");
        fclose(arquivo);
        arquivo = fopen("./ranking/rankingJD.txt", "r");
    }

    Registro registros[100];
    int totalRegistros = 0;
    char linha[50];

    while (fgets(linha, sizeof(linha), arquivo) != NULL && totalRegistros < 100) {
        if (strncmp(linha, "JOGADOR", 7) == 0 || linha[0] == '-') {
            continue;
        }
        sscanf(linha, "%14s %d %[^\n]", registros[totalRegistros].jogador, &registros[totalRegistros].pontuacao, registros[totalRegistros].jogo);
        totalRegistros++;
    }
    fclose(arquivo);

    Registro novoRegistro;
    strncpy(novoRegistro.jogador, nome, 14);
    novoRegistro.pontuacao = pontuacao;
    strncpy(novoRegistro.jogo, jogo, 49); 

    // Encontrar a posição correta para inserir a nova linha
    int posicaoInserir = totalRegistros; // Se não encontrar posição, será inserido no final
    for (int i = 0; i < totalRegistros; i++) {
        if (registros[i].pontuacao < pontuacao) {
            posicaoInserir = i;
            break;
        }
    }

    arquivo = fopen("./ranking/rankingJD.txt", "w");

    for (int i = 0; i < totalRegistros + 1; i++) {
        if (i == posicaoInserir) {
            fprintf(arquivo, "%-15s %-10d %s\n", novoRegistro.jogador, novoRegistro.pontuacao, novoRegistro.jogo);
        }
        if (i < totalRegistros) {
            fprintf(arquivo, "%-15s %-10d %s\n", registros[i].jogador, registros[i].pontuacao, registros[i].jogo);
        }
    }

    fclose(arquivo);
}

void Config_UsuarioSenha(char nome[11], char senha[9])
{
    FILE *arquivo = fopen("ranking/usuario_senha.txt", "a");
    fprintf(arquivo, "%s,%s\n", nome, senha);
    fclose(arquivo);
}