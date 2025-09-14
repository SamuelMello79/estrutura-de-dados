float calculaDescontoPix(float valorCompra) {
    return valorCompra * 0.10;
}

float calculaDescontoDebito(float valorCompra) {
    return valorCompra * 0.03; 
}

float calculaAdicionalRetirada(float valorCompra) {
    return valorCompra * 0.05;
}

float calculaTotal(float valorCompra, float desconto, float adicional) {
    return valorCompra - desconto + adicional;
}