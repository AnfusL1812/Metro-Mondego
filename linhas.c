/// Afonso Henrique Janeiro Lemos 2022148128

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linhas.h"

LinhaLista *AdicionarLinha(LinhaLista *L, Paragem *P, int nP) {
    // Nova Linha
    LinhaLista *NovaL, *AuxL;

    // Alocar Memória
    NovaL = malloc(sizeof(LinhaLista));

    if (NovaL == NULL) {
        system("cls");
        printf("Erro Ao Alocar Memoria\n\n");
        return L;
    }

    NovaL->L.Paragens = NULL;

    // Obter Nome
    LinhaLista *TempL;
    int Unico;

    do {
        printf("Nome: ");
        scanf(" %[^\n]", NovaL->L.Nome);

        TempL = L;
        Unico = 1;

        while (TempL != NULL) {
            if (strcmp(NovaL->L.Nome, TempL->L.Nome) == 0) {
                Unico = 0;
                break;
            }

            TempL = TempL->Prox;
        }
    } while (Unico == 0);

    // Mostrar Paragens
    system("cls");

    for (int i = 0; i < nP; i++)
        printf("Paragem: %s\nCodigo: %s\n\n", P[i].Nome, P[i].Codigo);
    printf("0 - Sair\n\n");

    // Obter Código
    char TempCodigo[C];

    do {
        printf("Codigo: ");
        scanf("%s", TempCodigo);

        for (int i = 0; i < nP; i++)
            if (strcmp(TempCodigo, P[i].Codigo) == 0) {
                // Nova Paragem
                ParagemLista *NovaP, *AuxP;

                // Alocar Memória
                NovaP = malloc(sizeof(ParagemLista));

                if (NovaP == NULL) {
                    system("cls");
                    printf("Erro Ao Alocar Memoria\n\n");
                    return L;
                }

                // Criar Paragem
                NovaP->P = P[i];

                // Criar Final
                NovaP->Prox = NULL;

                // Adicionar Paragem Na Lista
                if (NovaL->L.Paragens == NULL)
                    NovaL->L.Paragens = NovaP;
                else {
                    AuxP = NovaL->L.Paragens;

                    while (AuxP->Prox != NULL)
                        AuxP = AuxP->Prox;

                    AuxP->Prox = NovaP;
                }

                // Aumentar Número De Linhas Pertencentes
                P[i].LP++;
                break;
            }
    } while (TempCodigo[0] != '0');

    // Criar Final
    NovaL->Prox = NULL;

    // Adicionar Linha Na Lista
    if (L == NULL)
        L = NovaL;
    else {
        AuxL = L;

        while (AuxL->Prox != NULL)
            AuxL = AuxL->Prox;

        AuxL->Prox = NovaL;
    }

    system("cls");
    printf("Adicao Da Linha Bem Sucedida\n\n");
    return L;
}

LinhaLista *AtualizarLinha(LinhaLista *L, Paragem *P, int nP) {
    // Retornar Se Não Existir Linhas
    if (L == NULL) {
        system("cls");
        printf("Nao Existe Linhas\n\n");
        return L;
    }

    // Obter Nome
    char TempNome[N];

    printf("Nome: ");
    scanf(" %[^\n]", TempNome);

    // Verificar Linhas Compatíveis
    LinhaLista *TempL = L;

    while (TempL != NULL) {
        if (strcmp(TempNome, TempL->L.Nome) == 0) {
            system("cls");

            printf("1 - Adicionar Paragem\n");
            printf("2 - Eliminar Paragem\n");
            printf("3 - Eliminar Linha\n\n");
            printf("0 - Sair\n\n");

            // Obter Opção
            int Op;

            do {
                printf("Opcao: ");
                scanf("%d", &Op);

                while (getchar() != '\n');

                switch (Op) {
                case 1:

                    break;
                case 2:

                    break;
                case 3:

                    break;
                }
            } while (Op != 0);
            break;
        }

        TempL = TempL->Prox;
    }

    system("cls");
    printf("Nao Existe Linhas Compativeis\n\n");
    return L;
}

void VisualizarLinhas(LinhaLista *L, Paragem *P, int nP) {
    // Retornar Se Não Existir Linhas
    if (L == NULL) {
        system("cls");
        printf("Nao Existe Linhas\n\n");
        return;
    }

    // Mostrar Linhas
    LinhaLista *TempL;
    ParagemLista *TempP;

    TempL = L;

    while (TempL != NULL) {
        printf("Linha: %s\n\n", TempL->L.Nome);

        // Mostrar Paragens
        TempP = TempL->L.Paragens;

        if (TempP == NULL)
            printf("Nao Tem Paragens\n\n");
        else {
            while (TempP != NULL) {
                printf("Paragem: %s\nCodigo: %s\n\n", TempP->P.Nome, TempP->P.Codigo);

                TempP = TempP->Prox;
            }
        }

        TempL = TempL->Prox;
    }
    printf("1 - Visualizar Linhas Pertencentes\n\n");
    printf("0 - Sair\n\n");

    // Obter Opção
    int Op;

    do {
        printf("Opcao: ");
        scanf("%d", &Op);

        while (getchar() != '\n');

        if (Op == 1) {
            // Obter Código
            char TempCodigo[C];

            printf("Codigo: ");
            scanf("%s", TempCodigo);

            system("cls");

            // Verificar Paragens Compatíveis
            int Compativel = 0;

            for (int i = 0; i < nP; i++)
                if (strcmp(TempCodigo, P[i].Codigo) == 0) {
                    // Mostrar Paragem
                    printf("Paragem: %s\nCodigo: %s\n\n", P[i].Nome, P[i].Codigo);

                    // Mostrar Linhas
                    if (P[i].LP == 0) {
                        printf("Nao Tem Linhas Pertencentes\n\n");
                    }
                    else {
                        TempL = L;

                        while (TempL != NULL) {
                            TempP = TempL->L.Paragens;

                            while (TempP != NULL) {
                                if (strcmp(P[i].Codigo, TempP->P.Codigo) == 0) {
                                    printf("Linha: %s\n\n", TempL->L.Nome);
                                    break;
                                }

                                TempP = TempP->Prox;
                            }

                            TempL = TempL->Prox;
                        }
                    }

                    Compativel = 1;
                    break;
                }

            if (Compativel == 0) {
                system("cls");
                printf("Nao Existe Paragens Compativeis\n\n");
                return;
            }

            printf("0 - Sair\n\n");

            // Obter Opção
            do {
                printf("Opcao: ");
                scanf("%d", &Op);

                while (getchar() != '\n');
            } while (Op != 0);
        }
    } while (Op != 0);

    system("cls");
    printf("Visualizacao Das Linhas Bem Sucedida\n\n");
    return;
}

void EscolherCaminho(LinhaLista *L) {
    // Retornar Se Não Existir Linhas
    if (L == NULL) {
        system("cls");
        printf("Nao Existe Linhas\n\n");
        return;
    }

    // Variáveis
    Paragem Partida, Destino;

    int Valido = 0;

    // Obter Códigos
    char TempCodigo[C];

    printf("Partida\nCodigo: ");
    scanf("%s", TempCodigo);
    printf("\n");

    LinhaLista *TempL = L;

    while (TempL != NULL) {
        ParagemLista *TempP = TempL->L.Paragens;

        while (TempP != NULL) {
            if (strcmp(TempCodigo, TempP->P.Codigo) == 0) {
                Partida = TempP->P;

                printf("Destino\nCodigo: ");
                scanf("%s", TempCodigo);

                TempL = L;

                while (TempL != NULL) {
                    TempP = TempL->L.Paragens;

                    while (TempP != NULL) {
                        if (strcmp(TempCodigo, TempP->P.Codigo) == 0) {
                            Destino = TempP->P;

                            Valido = 1;
                            break;
                        }

                        TempP = TempP->Prox;
                    }

                    TempL = TempL->Prox;
                }
            }

            TempP = TempP->Prox;
        }

        TempL = TempL->Prox;
    }

    if (Valido == 1) {

    }

    system("cls");
    printf("Nao Existe Paragens Compativeis\n\n");
    return;
}
