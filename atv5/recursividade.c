// o programa deve retornar o fatorial de um numero utilizando dois métodos
// 1. While
// 2. Recursividade
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int fatorialWhile(int n) {
    int total = n;
    while (n > 1)
    {
        total = total * (n - 1);
        n--;    
    }
    return total;
}

int fatorialRecursividade(int n) {
    if (n == 0)
    {
        return 1;
    }
    return n * fatorialRecursividade(n - 1);
}

int main() {
    int num;
    setlocale(LC_ALL, "Portuguese");
    printf("Digite um numero: ");
    scanf("%i", &num);

    printf("Fatorial (While): %i\n", fatorialWhile(num));
    printf("Fatorial (Recursivdade): %i\n", fatorialRecursividade(num));
}