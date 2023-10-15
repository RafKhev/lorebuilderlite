#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include "funcoes.h"
#define MAX_PROJ 1

typedef struct _proj{
	int nome;
	char data_criacao[10];
}projeto;

int menu(){
	int rodando = 1, opcao;

	system("cls");
	printf("Escolha uma opção: \n"
		   "1 - Novo projeto\n"
		   "2 - Editar projeto\n"
		   "3 - Ver projetos\n"
		   "Outro - Sair\n->");

		scanf("%d", &opcao);
		printf("\n-------------------------\n");
		
		switch (opcao){
		case 1:
			printf("Criar");
			break;
		case 2:
			printf("Editar");
			break;
		case 3:
			printf("Visualizar\n\n");
			break;
		case 0:default:
			printf("Saindo...");
		}

}

int main(){
	setlocale(LC_ALL, "");

	// Ints funcionais
	int rodando = 1;
	int quant_projetos = 0;

	// Defini��o de quantides por projetos
	char projetos[30] = {0};
	// Vari�veis de personagens [No do projeto][No. do personagem][Tamanho]
	char nome_personagem[30];
	char descricao_personagem[300];

	// Vari�veis de mundo
	char nome_mundo[30];
	char descricao_mundo[300];

	// Variáveis de local
	int quant_locais = {0};
	char nome_local[30];
	char descricao_local[300];

	// Variáveis de objetos importantes
	int quant_objetos = {0};
	char nome_objeto[30];
	char descricao_objeto[300];


	projeto proj_atual;

	carregar_projeto(proj_atual);
	getch();
	menu();
	return 0;
}

