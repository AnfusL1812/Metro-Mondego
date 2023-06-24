/// Afonso Henrique Janeiro Lemos 2022148128

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paragens.h"

Paragem *RegistarParagem(Paragem *P, int *nP) {
    // Nova Paragem
    Paragem *NovaP = P;

    // Realocar Memória
    NovaP = realloc(P, sizeof(Paragem) * (*nP + 1));

    if (NovaP == NULL) {
        system("cls");
        printf("Erro Ao Realocar Memoria\n\n");
        return P;
    }

    // Obter Nome
    int Unico;

    do {
        printf("Nome: ");
        scanf(" %[^\n]", NovaP[*nP].Nome);

        Unico = 1;

        for (int i = 0; i < *nP; i++)
            if (strcmp(NovaP[*nP].Nome, P[i].Nome) == 0) {
                Unico = 0;
                break;
            }
    } while (Unico == 0);

    // Criar Código
    int Digito = *nP + 1;

    NovaP[*nP].Codigo[0] = 'A' + rand() % 26;
    for (int i = C - 2; i > 0; i--) {
        NovaP[*nP].Codigo[i] = Digito % 10 + '0';
        Digito /= 10;
    }
    NovaP[*nP].Codigo[C - 1] = '\0';

    // Criar Número De Linhas Pertencentes
    NovaP[*nP].LP = 0;

    // Aumentar Número De Paragens
    (*nP)++;

    system("cls");
    printf("Registo Da Paragem Bem Sucedido\n\n");
    return NovaP;
}

Paragem *EliminarParagem(Paragem *P, int *nP) {
    // Retornar Se Não Existir Paragens
    if (P == NULL) {
        system("cls");
        printf("Nao Existe Paragens\n\n");
        return P;
    }

    // Nova Paragem
    Paragem *NovaP = P;

    // Obter Código
    char TempCodigo[C];

    printf("Codigo: ");
    scanf("%s", TempCodigo);

    // Verificar Paragens Compatíveis
    for (int i = 0; i < *nP; i++)
        if (strcmp(TempCodigo, P[i].Codigo) == 0) {
            if (P[i].LP != 0) {
                system("cls");
                printf("Paragem Tem Linhas Pertencentes\n\n");
                return P;
            }

            // Translocar Elementos Para A Posição Anterior
            for (int j = i; j < *nP - 1; j++) {
                strcpy(NovaP[j].Nome, NovaP[j + 1].Nome);
                strcpy(NovaP[j].Codigo, NovaP[j + 1].Codigo);
                NovaP[j].LP = NovaP[j + 1].LP;
            }

            // Realocar Memória
            NovaP = realloc(P, sizeof(Paragem) * (*nP - 1));

            if (NovaP == NULL & *nP != 1) {
                system("cls");
                printf("Erro Ao Realocar Memoria\n\n");
                return P;
            }

            // Diminuir Número De Paragens
            (*nP)--;

            system("cls");
            printf("Eliminacao Da Paragem Bem Sucedida\n\n");
            return NovaP;
        }

    system("cls");
    printf("Nao Existe Paragens Compativeis\n\n");
    return P;
}

void VisualizarParagens(Paragem *P, int nP) {
    // Retornar Se Não Existir Paragens
    if (P == NULL) {
        system("cls");
        printf("Nao Existe Paragens\n\n");
        return;
    }

    // Mostrar Paragens
    for (int i = 0; i < nP; i++)
        printf("Paragem: %s\nCodigo: %s\nNumero De Linhas Pertencentes: %d\n\n", P[i].Nome, P[i].Codigo, P[i].LP);
    printf("0 - Sair\n\n");

    // Obter Opção
    int Op;

    do {
        printf("Opcao: ");
        scanf("%d", &Op);

        while (getchar() != '\n');
    } while (Op != 0);

    system("cls");
    printf("Visualizacao Das Paragens Bem Sucedida\n\n");
    return;
}
