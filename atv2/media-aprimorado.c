// calculo da media de um aluno, requisitos:
// 1. o programa deve tentar incorporar o padrão MVC;
// 2. os métodos não podem ter retorno;
// 3. não é permitido o uso de ponteiros;
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

// declara todos os métodos para facilitar na hora de fazer a chamada das funções
void service_cadastra_notas(char nome[40], float media, float notas[3]);
void service_cadastra_aluno(char nome[40], float media, float notas[3]);
void service_calcula_media(char nome[40], float media, float notas[3]);
void service_verifica_se_precisa_sub(char nome[40], float media, float notas[3]);

// interface do usuario
void controller_init() {
    setlocale(LC_ALL, "Portuguese");
    char nome[40];
    float media, notas[3];

    printf("Inicializando o sistema..\n\n");

    service_cadastra_usuario(nome, media, notas);
    service_cadastra_notas(nome, media, notas);
    service_calcula_media(nome, media, notas);

    printf("\n======= FIM DO PROGRAMA ======\n");
}

// lógica do sistema

// service para cadastrar aluno
void service_cadastra_aluno(char nome[40], float media, float notas[3]) {
    printf("Informe seu nome: ");
    scanf("%s", nome);
}

// service para cadastrar notas
void service_cadastra_notas(char nome[40], float media, float notas[3]) {
    for(int i = 0; i <= 2; i++) {
        if (i < 2) {
			printf("Informe nota da p%i: ", (i + 1));
			scanf("%f", &notas[i]);	
		} else {
			printf("Informe a nota da lista (0-2.5): ");
			scanf("%f", &notas[i]);
		}
    }
}

// service para calcular a media do aluno
void service_calcula_media(char nome[40], float media, float notas[3]) {
    // p1 * 0,35 + p2 * 0,4 + lista
	media = notas[0] * 0.35 + notas[1] * 0.4 + notas[2];
    service_verifica_se_precisa_sub(nome, media, notas);
}

// service para verificar se o aluno foi aprovado ou não
void service_verifica_se_precisa_sub(char nome[40], float media, float notas[3]) {
    if (media >= 6) {
		printf("O aluno %s foi aprovado com média %.2f\n", nome, media);
	} else {
		int pos = (notas[0] < notas[1]) ? 0 : 1;
		
		printf("Insira novamente  nota da prova SUB: ");
		scanf("%f", &notas[pos]);
		
		service_calcula_media(nome, media, notas);
		if (media >= 6) {
			printf("Aluno %s aprovado com sub e media %.2f\n", nome, media);
		} else {
			printf("Aluno %s reprovado com sub e média %.2f\n", nome, media);
		}
	}
}

int main() {
    controller_init(); // inicializa a interface de usuario
    return 0;
}