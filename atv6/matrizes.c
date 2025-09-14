// Matriz multidimensionais
// 1. crie uma matriz com 7 dimensões, preencha essa matriz e faça a exibição dela;
// 2. depois prencha um vetor com os valores da matriz e exiba o vetor;
#include <stdlib.h>
#include <stdio.h>

int main() {
    int matriz[2][2][2][2][2][2][2];
    int vetor[128];
    int a, b, c, d, e, f, g;
    int i = 0;

    for(a = 0;  a  < 2; a++) {
        for(b = 0;  b  < 2; b++) {
            for(c = 0;  c  < 2; c++) {
                for(d = 0;  d  < 2; d++) {
                    for(e = 0;  e  < 2; e++) {
                        for(f = 0;  f  < 2; f++) {
                            for (g = 0; g < 2; g++) {
                                matriz[a][b][c][d][e][f][g] = i;
                                vetor[i] = matriz[a][b][c][d][e][f][g];
                                i++;
                            }
                        }
                    }
                }
            }
        }   
    }

    printf("\nExibindo matriz\n");
    for(a = 0;  a  < 2; a++) {
        for(b = 0;  b  < 2; b++) {
            for(c = 0;  c  < 2; c++) {
                for(d = 0;  d  < 2; d++) {
                    for(e = 0;  e  < 2; e++) {
                        for(f = 0;  f  < 2; f++) {
                            for (g = 0; g < 2; g++) {
                                printf("%i ", matriz[a][b][c][d][e][f][g]);
                            }
                        }
                    }
                }
            }
        }
        printf("\n");
    }

    printf("\nExibindo vetor\n");
    for (int i = 0; i < 128; i++)
    {
        printf("%i ", vetor[i]);
    }
    printf("\n");
    
}
