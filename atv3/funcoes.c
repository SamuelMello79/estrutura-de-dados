// realizar calculos com funções que possuem retorno
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// soma com 25
int soma(int *n) {
    *n = *n + 25;
    return *n;
}

// subtrai por 10
int subtrai(int *n) {
    *n = *n - 10;
    return *n;
}

// multiplica por 3
int multiplica(int *n) {
    *n = *n * 3;
    return *n;
}

// divide por 2
float divide(int *n) {
    *n = *n / 2;
    return *n;
}

// eleva ao cubo
float aoCubo(int *n) {
    *n = *n * *n * *n;
    return *n;
}

int main() {
    // define o padrão de caracteres no terminal
    setlocale(LC_ALL, "Portuguese");
    int num;

    // recebe o numero
    printf("Informe um número: ");
    scanf("%i", &num);

    // passa para cada operação a referencia de num
    printf("Soma: %i\n", soma(&num));
    printf("Subtrai: %i\n", subtrai(&num));
    printf("Multiplica: %i\n", multiplica(&num));
    printf("Dividido: %.2f\n", divide(&num));
    printf("Ao cubo: %.2f\n", aoCubo(&num));

    return 0;
}