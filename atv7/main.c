// Cifre uma frase utilizando um metodo simples

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void cifraFrase(char frase[]) {
    // remove \n do fgets
    int tamanho = strlen(frase);
    if (tamanho > 0 && frase[tamanho-1] == '\n') {
        frase[tamanho-1] = '\0';
    }

    // desloca todos os caracteres 3 posicoes na tabela ASCII até o ultimo caractere valido
    for (int i = 0; frase[i] != '\0'; i++) 
    {
        char letra = frase[i]; // transforma em char
        letra = letra + 3; // desloca 3 posições
        frase[i] = letra; // faz a troca
    }
}

int main() {
    char frase[50];

    // definição da frase
    printf("Informe uma frase: ");
    fgets(frase, sizeof(frase), stdin); 

    // exibe a frase antes de cifrar
    printf("%s", frase);

    // deixa a frase cifrada
    cifraFrase(frase);

    // exibe a frase cifrada
    printf("%s\n", frase);
}