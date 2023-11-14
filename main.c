#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

#include "func.h"
#include "struct.h"

#define MAX_PROJETOS 50
#define MAX_NOME_PASTA 256

void listar_projetos(char projetos[][MAX_NOME_PASTA], int *quant_projetos);

int main()
{
	setlocale(LC_ALL, "Portuguese");

	// Ints funcionais
	int rodando = 1, opcao;

	// Defini��o de quantides por projetos
	char nome_projeto[30];
	char projetos[MAX_PROJETOS][MAX_NOME_PASTA];
	int quant_projetos = 0;

	Projeto projeto_aberto;
	

	do{
		printf(" _     ___  ____  _____ ____  _   _ ___ _     ____  _____ ____\n| |   / _ \\|  _ \\| ____| __ )| | | |_ _| |   |  _ \\| ____|  _ \\\n| |  | | | | |_) |  _| |  _ \\| | | || || |   | | | |  _| | |_) |\n| |__| |_| |  _ <| |___| |_) | |_| || || |___| |_| | |___|  _ <\n|_____\\___/|_| \\_\\_____|____/ \\___/|___|_____|____/|_____|_| \\_\\|");
                                                              
		int op = 0;
		printf("\n----------------------------------------\n");
		printf("\n\nEscolha uma opção: \n"
			"1 - Listar projetos\n"
			"2 - Abrir projetos\n"
			"Outro - Sair\n->");

        scanf("%d", &op);
        printf("\n-------------------------\n");
        
        switch (op){
            case 1:
                listar_projetos(projetos, &quant_projetos);
                break;
            case 2:
                projeto_aberto = carregar_projeto(projetos, quant_projetos);
                break;
            default: 
			rodando = 0;
			break;
        }
	}while(rodando==1);
	return 0; 
	
}


