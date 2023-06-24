/// Afonso Henrique Janeiro Lemos 2022148128

#include <stdio.h>
#include "ficheiros.h"

void main() {
    // Variáveis
    Paragem *P = NULL;
    int nP = 0;

    LinhaLista *L = NULL;

    // Obter Variáveis
    P = ObterParagens(&nP);
    L = ObterLinhas("linhas.dat");

    // Menu
    int Op;

    printf("\n");
    do {
        printf("M E T R O   M O N D E G O\n");
        printf("-------------------------\n");
        printf(" 1 - Registar Paragem    \n");
        printf(" 2 - Eliminar Paragem    \n");
        printf(" 3 - Visualizar Paragens \n\n");
        printf(" 4 - Adicionar Linha     \n");
        printf(" 5 - Atualizar Linha     \n");
        printf(" 6 - Visualizar Linhas   \n\n");
        printf(" 7 - Escolher Caminho    \n\n");
        printf(" 0 - Sair                \n");
        printf("-------------------------\n\n");

        do {
            printf("Opcao: ");
            scanf("%d", &Op);

            while (getchar() != '\n');
        } while (Op < 0 || Op > 7);

        switch (Op) {
        case 1:
            system("cls");
            P = RegistarParagem(P, &nP); break;
        case 2:
            system("cls");
            P = EliminarParagem(P, &nP); break;
        case 3:
            system("cls");
            VisualizarParagens(P, nP); break;
        case 4:
            system("cls");
            L = AdicionarLinha(L, P, nP); break;
        case 5:
            system("cls");
            L = AtualizarLinha(L, P, nP); break;
        case 6:
            system("cls");
            VisualizarLinhas(L, P, nP); break;
        case 7:
            system("cls");
            EscolherCaminho(L);
        }
    } while (Op != 0);

    // Guardar Variáveis
    GuardarParagens(P, nP);
    GuardarLinhas(L, "linhas.dat");

    // Dealocar Memória
    free(P);
    free(L);
}
