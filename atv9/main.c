// Crie um pequeno sistema de vendas utilizando Structs
// Crie três structs:
// 1. TbCliente (cod, nome, cpf)
// 2. TbProduto (cod, desc, qntde, valor)
// 3. TbVenda (cod, cod.cliente, cod.produto, totalVenda, qntdeItens);

// Observações
// 1. Realiza uma venda:
// * Pergunte ao usuário um código de cliente, se existir, insira na venda
// * Pergunte um códugo de produto, se existir, pergunte a qntde de itens que o usuário deseja comprar, se existir, multiplique pelo valor
// * Pergunte ao usuário se ele deseja comprar outro produto novamente
// 2. Exiba a venda:
// * No final pergunte ao usuário o código de uma venda, e se existir exiba os valores:
// - codigo da venda
// - nome do cliente
// - cpf do cliente
// - total da venda
// - total de itens

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int posicaoCliente = 0, posicaoProduto = 0, posicaoVenda = 0, opcao = 0;

struct Cliente
{
    int cod;
    char nome[50];
    char cpf[11];
};

struct Produto
{
    int cod;
    char descricao[10];
    int qntde;
    float valor;
};

struct Venda
{
    int cod;
    int codCliente;
    int codProduto;
    float totalVenda;
    int qntdeItens;
};

struct Cliente clientes[10];
struct Produto produtos[10];
struct Venda vendas[10];

void inserirCliente() {
    if (posicaoCliente < 10)
    {
        printf("Informe o código do cliente: ");
        scanf("%d", &clientes[posicaoCliente].cod);

        printf("Informe o nome completo do cliente: ");
        scanf("%s", clientes[posicaoCliente].nome);

        printf("Informe o cpf do cliente: ");
        scanf("%s", clientes[posicaoCliente].cpf);
        posicaoCliente++;
    } else {
        printf("\nNão é possivel criar mais clientes\n");
    }
}

void listarCliente() {
    printf("\n\n==== LISTA CLIENTES ===\n");
    int n_clientes = sizeof(clientes) / sizeof(clientes[0]);
    for (int i = 0; i < n_clientes; i++) {
        if (clientes[i].cod != 0)
        {
            printf("\n==== %d ====\n", clientes[i].cod);
            printf("Nome: %s\n", clientes[i].nome);
            printf("Bairro: %s\n", clientes[i].cpf);
        }
    }
}

void inserirProduto() {
    if (posicaoProduto < 10)
    {
        printf("Informe o código do produto: ");
        scanf("%d", &produtos[posicaoProduto].cod);

        printf("Informe a descrição do produto: ");
        scanf("%s", produtos[posicaoProduto].descricao);

        printf("Informe a quantidade do produto: ");
        scanf("%i", &produtos[posicaoProduto].qntde);

        printf("Informe o valor do produto: ");
        scanf("%f", &produtos[posicaoProduto].valor);
        posicaoProduto++;
    } else {
        printf("\nNão é possivel criar mais produtos\n");
    }
}

void listarProdutos() {
    int n_produtos = sizeof(produtos) / sizeof(produtos[0]);
    printf("\n==== LISTA PRODUTOS ===\n");
    for (int i = 0; i < n_produtos; i++) {
        if (produtos[i].cod != 0)
        {
            printf("\n==== %d ====\n", produtos[i].cod);
            printf("Descrição: %s\n", produtos[i].descricao);
            printf("Qntde: %d\n", produtos[i].qntde);
            printf("Valor: R$%.2f\n", produtos[i].valor);  
        }
    }
}

int buscarClientePeloCodigoDoCliente(int codCliente) {
    int n_clientes = sizeof(clientes) / sizeof(clientes[0]);
    for (int i = 0; i < n_clientes; i++) {
        if(clientes[i].cod == codCliente) {
            return i; // retornando a posicao que o cliente esta na lista
        }
    }
    return -1;
} 

int buscarProdutoPeloCodigoDoProduto(int codProduto) {
    int n_produtos = sizeof(produtos) / sizeof(produtos[0]);
    for (int i = 0; i < n_produtos; i++)
    {
        if (produtos[i].cod == codProduto) {
            return i;
        }
    }
    return -1;
}

int buscarVendaPeloCodigoDaVenda(int codVenda) {
    int n_vendas = sizeof(vendas) / sizeof(vendas[0]);
    for (int i = 0; i < n_vendas; i++)
    {
        if (vendas[i].cod == codVenda) {
            return i;
        }
    }
    return -1;
}

double calculaTotalVenda(int posProduto, int qntde) {
    if (produtos[posProduto].qntde >= qntde) {
        return produtos[posProduto].valor * qntde;
    } else {
        printf("\nO saldo do produto %s é menor que o solicitado\n", produtos[posProduto].descricao);
        printf("\nPRODUTO\tQNTDE\n");
        printf("\n%s\t%d\n", produtos[posProduto].descricao, produtos[posProduto].qntde);
    }
    return -1;
}

void buscarVenda() {
    int codVenda;
    printf("\nInforme o código da venda: ");
    scanf("%d", &codVenda);

    int posVenda = buscarVendaPeloCodigoDaVenda(codVenda);
    if (posVenda != -1)
    {
        int posCliente = buscarClientePeloCodigoDoCliente(vendas[posVenda].codCliente);
        int posProduto = buscarProdutoPeloCodigoDoProduto(vendas[posicaoVenda].codProduto);    

        printf("\n====== VENDA Nº%d ======\n", vendas[posVenda].cod);
        printf("------ dados cliente -------\n");
        printf("Cliente: %s\n", clientes[posCliente].nome);
        printf("CPF: %s\n", clientes[posCliente].cpf);
        printf("------ produtos da venda -------\n");
        printf("Produto: %s\n", produtos[posProduto].descricao);
        printf("Qntde: %d\n", vendas[posVenda].qntdeItens);
        printf("====== TOTAL VENDA ======\n");
        printf("Total venda: R$%2.f\n\n", vendas[posVenda].totalVenda);
    } else {
        printf("Código da venda inválido!\n");
    }
}

void cadastrarVenda() {
    int posCliente = -1, posProduto = -1;
    int codCliente = 0, codProduto = 0, qntde = 0;
    double totalVenda = -1; 

    do {
        printf("Informe o código de um cliente: ");
        scanf("%d", &codCliente);
        posCliente = buscarClientePeloCodigoDoCliente(codCliente);
        if (posCliente == -1) printf("Código inválido! Por favor tente novamente");
    } while (codCliente == -1);

    do {
        printf("Informe o código de um produto: ");
        scanf("%d", &codProduto);
        posProduto = buscarClientePeloCodigoDoCliente(codProduto);
        if (posProduto == -1) printf("Código inválido! Por favor tente novamente");
    } while (codProduto == -1);

    do {
        printf("Informe a quantidade de itens do produto: ");
        scanf("%d", &qntde);
        totalVenda = calculaTotalVenda(posProduto, qntde);
    } while (totalVenda == -1);

    vendas[posicaoVenda].cod = posicaoVenda + 1;
    vendas[posicaoVenda].codCliente = codCliente;
    vendas[posicaoVenda].codProduto = codProduto;
    vendas[posicaoVenda].qntdeItens = qntde;
    vendas[posicaoVenda].totalVenda = totalVenda;
    posicaoVenda++;
}

int main() {
    while (opcao != 7)
    {
        printf("\n==== MENU INICIAL ====\n");
        printf("Selecione uma das opções:\n");
        printf("1. Cadastra um cliente\n");
        printf("2. Exibir a lista de clientes\n");
        printf("3. Cadastra um produto\n");
        printf("4. Exibir a lista de produtos\n");
        printf("5. Cadastrar uma nova venda\n");
        printf("6. Buscar uma venda\n");
        printf("7. Finalizar o sistema\n");
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
            cadastrarVenda();
            break;
        case 6:
            buscarVenda();
            break;
        case 7:
            printf("\nEncerrando o programa..\n");
            break;
        default:
            printf("\nOpção inválida!\n");
            break;
        }
    }
    return 0;
}