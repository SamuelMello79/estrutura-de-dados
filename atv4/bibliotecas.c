#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "operacoes.h"

float calculaAdicional(char tipoRet, float valorCompra) {
    switch (tipoRet){
    case 'R':
        return calculaAdicionalRetirada(valorCompra);
    case 'L':
        return 0;
    default:
        printf("O método de retirada é inválido!");
        return 0;
    }
}

float calculaDesconto(char tipoPagto[4], float valorCompra) {
    if (strcmp(tipoPagto, "D") == 0) {
        return calculaDescontoDebito(valorCompra);
    } else if (strcmp(tipoPagto, "PIX") == 0) {
        return calculaDescontoPix(valorCompra);
    } else if (strcmp(tipoPagto, "C") == 0) {
        return 0;
    } else {
        printf("O método de pagamento é inválido");
        return 0;
    }
}

void gerarComanda(char nome[40], char tipoPagto[4], char tipoRet, float valorCompra) {
    float descontoPagto, frete;

    descontoPagto = calculaDesconto(tipoPagto, valorCompra);
    frete = calculaAdicional(tipoRet, valorCompra);

    printf("\n===== COMANDA =====\n");
    printf("Nome do cliente: %s\n", nome);
    printf("Forma de pagamento: %s\n", tipoPagto);
    printf("Forma de retirada: %c\n", tipoRet);
    printf("Valor de compra: %.2f\n", valorCompra);
    if (frete > 0) {
        printf("\n===== ADICIONAIS =====\n");
        printf("Valor do frete: %.2f\n", frete);
    }
    if (descontoPagto > 0) {
        printf("\n====== DESCONTOS =====\n");
        printf("Valor de desconto: %.2f\n", descontoPagto);
    }
    printf("\n====== TOTAL =====\n");
    printf("Total: %.2f\n", calculaTotal(valorCompra, descontoPagto, frete));
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    char tipoPagto[4], tipoRet, nome[40];
    float valorCompra;

    printf("Digite o nome do cliente: ");
    scanf("%s", nome);

    printf("Digite o valor da compra: ");
    scanf("%f", &valorCompra);

    while (getchar() != '\n');

    printf("Digite a forma de retirada (L - R): ");
    scanf("%c", &tipoRet);

    printf("Digite a forma de pagamento (PIX - D - C): ");
    scanf("%s", tipoPagto);

    gerarComanda(nome, tipoPagto, tipoRet, valorCompra);
    return 0;
}