// Gere uma lista de clientes utilizando Structs

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int posicao = 0, posicaoProd = 0, opcao = 0;

// define um tipo de estrutura chamada TbFicha
struct Cliente
{
    int codigo;
    char nome[40];
    char bairro[40];
    char cidade[60];
    char telefone[10];
    char rg[11];
    char cpf[11];
    char pais[50];
};

struct Produto
{
    int codigo;
    char descricao[50];
    int qntde;
    float valor;
};

// define uma matriz de estrutura, assim em cada posição alimentos a 4 atributos
struct Cliente clientes[10];
struct Produto produtos[10];

void inserirCliente() {
    if (posicao < 10)
    {
        printf("Informe o código do cliente: ");
        scanf("%d", &clientes[posicao].codigo);

        printf("Informe o nome completo do cliente: ");
        scanf("%s", clientes[posicao].nome);

        printf("Informe o bairro do cliente: ");
        scanf("%s", clientes[posicao].bairro);

        printf("Informe o cidade do cliente: ");
        scanf("%s", clientes[posicao].cidade);

        printf("Informe o telefone do cliente: ");
        scanf("%s", clientes[posicao].telefone);

        printf("Informe o rg do cliente: ");
        scanf("%s", clientes[posicao].rg);

        printf("Informe o cpf do cliente: ");
        scanf("%s", clientes[posicao].cpf);

        printf("Informe o pais do cliente: ");
        scanf("%s", clientes[posicao].pais);
        posicao++;
    } else {
        printf("Não é possivel criar mais clientes");
    }
}

void listarCliente() {
    printf("\n==== LISTA PRODUTOS ===\n");
    int n_clientes = sizeof(clientes) / sizeof(clientes[0]);
    for (int i = 0; i < n_clientes; i++) {
        if (clientes[i].codigo != 0)
        {
            printf("\n==== %d ====\n", clientes[i].codigo);
            printf("Nome: %s\n", clientes[i].nome);
            printf("Bairro: %s\n", clientes[i].bairro);
            printf("Cidade: %s\n", clientes[i].cidade);
            printf("Telefone: %s\n", clientes[i].telefone);
            printf("RG: %s\n", clientes[i].rg);
            printf("CPF: %s\n", clientes[i].cpf);
            printf("Pais: %s\n", clientes[i].pais);   
        }
    }
}

void inserirProduto() {
    if (posicaoProd < 10)
    {
        printf("Informe o código do produto: ");
        scanf("%d", &produtos[posicaoProd].codigo);

        printf("Informe a descrição do produto: ");
        scanf("%s", produtos[posicaoProd].descricao);

        printf("Informe a quantidade do produto: ");
        scanf("%d", &produtos[posicaoProd].qntde);

        printf("Informe o valor do produto: ");
        scanf("%f", &produtos[posicaoProd].valor);
        posicaoProd++;
    } else {
        printf("Não é possivel criar mais produtos");
    }
}

void listarProdutos() {
    int n_produtos = sizeof(produtos) / sizeof(produtos[0]);
    printf("\n==== LISTA PRODUTOS ===\n");
    for (int i = 0; i < n_produtos; i++) {
        if (produtos[i].codigo != 0)
        {
            printf("\n==== %d ====\n", produtos[i].codigo);
            printf("Descrição: %s\n", produtos[i].descricao);
            printf("Qntde: %d\n", produtos[i].qntde);
            printf("Valor: R$%.2f\n", produtos[i].valor);  
        }
    }
}

int main () {
    while (opcao != 5)
    {
        printf("==== MENU INICIAL ====\n");
        printf("Selecione uma das opções:\n");
        printf("1. Cadastra um cliente\n");
        printf("2. Exibir a lista de clientes\n");
        printf("3. Cadastra um produto\n");
        printf("4. Exibir a lista de produtos\n");
        printf("5. Finalizar o sistema\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            inserirCliente();
            break;
        case 2: 
            listarCliente();
            break;
        case 3:
            inserirProduto();
            break;
        case 4:
            listarProdutos();
            break;
        case 5:
            printf("\nEncerrando o programa..\n");
            break;
        default:
            printf("\nOpção inválida!\n");
            break;
        }
    }
    
    return 0;
}