/// Afonso Henrique Janeiro Lemos 2022148128

#include <stdio.h>
#include "ficheiros.h"

void GuardarParagens(Paragem *P, int nP) {
    // Abrir Ficheiro
    FILE *F;

    F = fopen("paragens.dat", "wb");

    if (F == NULL)
        return;

    // Escrever Dados
    fwrite(&nP, sizeof(int), 1, F);

    for(int i = 0; i < nP; i++)
        fwrite((P + i), sizeof(Paragem), 1, F);

    // Fechar Ficheiro
    fclose(F);
    return;
}

Paragem *ObterParagens(int *nP) {
    // Abrir Ficheiro
    FILE *F;

    Paragem *P = NULL;

    F = fopen("paragens.dat", "rb");

    if (F == NULL)
        return NULL;

    // Ler Dados
    fread(nP, sizeof(int), 1, F);

    P = malloc(sizeof(Paragem) * (*nP));

    if (P == NULL) {
        *nP = 0;

        fclose(F);
        return NULL;
    }

    fread(P, sizeof(Paragem), *nP, F);

    // Fechar Ficheiro
    fclose(F);
    return P;
}

void GuardarLinhas(LinhaLista *L, char *NomeF) {
    // Abrir Ficheiro
    FILE *F;

    F = fopen(NomeF, "wb");

    if (F == NULL)
        return;

    // Escrever Dados
    while (L != NULL) {
        fwrite(&(L->L), sizeof(Linha), 1, F);

        L = L->Prox;
    }

    // Fechar Ficheiro
    fclose(F);
    return;
}

LinhaLista *ObterLinhas(char *NomeF) {
    // Abrir Ficheiro
    FILE *F;

    LinhaLista *L = NULL;
    LinhaLista *NovaL, *AuxL;
    Linha Lin;

    // Ler Dados
    F = fopen(NomeF, "rb");

    if (F == NULL)
        return NULL;

    while (fread(&Lin, sizeof(Linha), 1, F) == 1) {
        NovaL = malloc(sizeof(LinhaLista));

        if (NovaL == NULL) {
            fclose(F);
            return L;
        }

        NovaL->L = Lin;
        NovaL->Prox = NULL;

        if (L == NULL)
            L = NovaL;
        else {
            AuxL = L;

            while (AuxL->Prox != NULL)
                AuxL = AuxL->Prox;

            AuxL->Prox = NovaL;
        }
    }

    // Fechar Ficheiro
    fclose(F);
    return L;
}
