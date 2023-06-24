/// Afonso Henrique Janeiro Lemos 2022148128

#ifndef PARAGENS_H_INCLUDED
#define PARAGENS_H_INCLUDED

#define N 50
#define C 5

// Estrutura Da Paragem
typedef struct {
    char Nome[N], Codigo[C];
    int LP; // Linhas Pertencentes
} Paragem;

Paragem *RegistarParagem(Paragem *P, int *nP);

Paragem *EliminarParagem(Paragem *P, int *nP);

void VisualizarParagens(Paragem *P, int nP);

#endif // PARAGENS_H_INCLUDED
