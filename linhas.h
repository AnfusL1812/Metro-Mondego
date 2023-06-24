/// Afonso Henrique Janeiro Lemos 2022148128

#ifndef LINHAS_H_INCLUDED
#define LINHAS_H_INCLUDED

#include "paragens.h"

// Lista Das Paragens
typedef struct {
    Paragem P;
    struct ParagemLista *Prox;
} ParagemLista;

// Estrutura Da Linha
typedef struct {
    char Nome[N];
    ParagemLista *Paragens;
} Linha;

// Lista Das Linhas
typedef struct {
    Linha L;
    struct LinhaLista *Prox;
} LinhaLista;

LinhaLista *AdicionarLinha(LinhaLista *L, Paragem *P, int nP);

LinhaLista *AtualizarLinha(LinhaLista *L, Paragem *P, int nP);

void VisualizarLinhas(LinhaLista *L, Paragem *P, int nP);

void EscolherCaminho(LinhaLista *L);

#endif // LINHAS_H_INCLUDED
