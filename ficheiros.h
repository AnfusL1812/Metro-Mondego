/// Afonso Henrique Janeiro Lemos 2022148128

#ifndef FICHEIROS_H_INCLUDED
#define FICHEIROS_H_INCLUDED

#include "linhas.h"

void GuardarParagens(Paragem *P, int nP);

Paragem *ObterParagens(int *nP);

void GuardarLinhas(LinhaLista *L, char *NomeF);

LinhaLista *ObterLinhas(char *NomeF);

#endif // FICHEIROS_H_INCLUDED
