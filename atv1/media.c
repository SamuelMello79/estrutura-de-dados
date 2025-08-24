// calculo da media de um aluno
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

float calculaMedia(float notas[3]) {
	// p1 * 0,35 + p2 * 0,4 + lista
	return notas[0] * 0.35 + notas[1] * 0.4 + notas[2];
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	float notas[3];
	float media;
	char nome[40];
	
	printf("Informe seu nome: ");
	scanf("%s", nome);
	
	for (int i = 0; i <= 2; i++) {
		if (i < 2) {
			printf("Informe nota da p%i: ", (i + 1));
			scanf("%f", &notas[i]);	
		} else {
			printf("Informe a nota da lista (0-2.5): ");
			scanf("%f", &notas[i]);
		}
	}


	media = calculaMedia(notas);
	
	if (media >= 6) {
		printf("O aluno %s foi aprovado com média %.2f\n", nome, media);
	} else {
		int pos = (notas[0] < notas[1]) ? 0 : 1;
		
		printf("Insira novamente  nota da prova SUB: ");
		scanf("%f", &notas[pos]);
		
		media = calculaMedia(notas);
		if (media >= 6) {
			printf("Aluno %s aprovado com sub e media %.2f\n", nome, media);
		} else {
			printf("Aluno %s reprovado com sub e média %.2f\n", nome, media);
		}
	}
}

