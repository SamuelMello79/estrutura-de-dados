// Crie um programa que deve ordenar:
// 1. Uma lista de numeros
// 2. Uma lista de letras
// 3. Uma lista de caracteres

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void bubbleSortNum(int numeros[], int n_numeros) {
    // ordena numeros
    for (int i = 0; i < n_numeros - 1; i++)
    {
        for (int j = 0; j < n_numeros - i - 1; j++)
        {
            // se o numero na posição atual for maior que a o numero na proxima posicao
            if (numeros[j] > numeros[j + 1]) 
            {
                // armazeno temporariamente em um variavel o valor atual na posicao atual
                int temp = numeros[j];
                // na posicao atual vou colocar o numero que estava na proxima posicao
                numeros[j] = numeros[j + 1];
                // na proxima posicao vou colocar o antigo numero da posicao atual armazenado na variavel temp
                numeros[j + 1] = temp;
            }            
        }
    }
}

void bubbleSortChar(char letras[], int n_letras) {
    // ordena letras
    for (int i = 0; i < n_letras - 1; i++)
    {
        for (int j = 0; j < n_letras - i - 1; j++)
        {
            if (letras[j] > letras[j + 1])
            {
                char temp = letras[j];
                letras[j] = letras[j + 1];
                letras[j + 1] = temp;
            }
        }
    }
}

void bubbleSortStr(char palavras[][50], int n_palavras) {
    // ordena palavas
    for (int i = 0; i < n_palavras - 1; i++)
    {
        for (int j = 0; j < n_palavras - i - 1; j++)
        {
            // a função strcmp compara duas string caractere a caractere e retorna:
            // < 0 : se str1 for menor que str2 (vem antes no dicionario)
            // = 0 : se str1 e str2 forem iguais
            // > 0 : se str1 for maior que str2 (vem depois no dicionario)
            if (strcmp(palavras[j], palavras[j + 1]) > 0)
            {
                char temp[50];
                // copia o valor da posição atual para temp
                strcpy(temp, palavras[j]); 
                // copia o valor da proxima palavra para o valor da posição atual
                strcpy(palavras[j], palavras[j + 1]); 
                // copia o antigo valor da posição atual para a proxima posicao
                strcpy(palavras[j + 1], temp); 
            }
        }
    }
}

void printArrNum(int numeros[], int n_numeros) {
    // exibe array de numeros
    for (int i = 0; i < n_numeros; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");
}

void printArrChar(char letras[], int n_letras) {
    // exibe array de letras
    for (int i = 0; i < n_letras; i++) {
        printf("%c ", letras[i]);
    }
    printf("\n");
}

void printArrStr(char palavras[][50], int n_palavras) {
    // exibe array de palavras
    for (int i = 0; i < n_palavras; i++) {
        printf("%s ", palavras[i]);
    }
    printf("\n");
}

int main() {
    // definicao dos arrays
    int numeros[] = {1, 5, 6, 9, 10, 7, 8, 4, 2, 3};
    char letras[] = {'A', 'C', 'D', 'F', 'E', 'B'};
    char palavras[][50] = {"carro", "banana", "abacaxi"};

    // definicao dos tamanhos
    
    // o sizeof retorna o tamanho em bytes de um tipo de dado ou de uma variavel
    // sizeof(numeros) -> 10 (elementos) * sizeof(int) = 40 bytes (supondo int como 4 bytes)
    // sizeof(numeros[0]) -> sizeof(int) = 4 bytes
    // n_numeros -> 40 / 4 = 10 elementos 
    int n_numeros = sizeof(numeros) / sizeof(numeros[0]);
    int n_letras = sizeof(letras) / sizeof(letras[0]);
    int n_palavras = sizeof(palavras) / sizeof(palavras[0]);
    
    // ordenando arrays
    bubbleSortNum(numeros, n_numeros);
    bubbleSortChar(letras, n_letras);
    bubbleSortStr(palavras, n_palavras);

    // exibindo arrays ordenados
    printArrNum(numeros, n_numeros);
    printArrChar(letras, n_letras);
    printArrStr(palavras, n_palavras);

    return 0;
}