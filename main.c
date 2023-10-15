#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define MAX_PROJ 1
int main(){
	setlocale(LC_ALL, "");
	
	
	//Ints funcionais
	int rodando = 1, opcao; 
	int quant_projetos = 0;
	
	
	//Defini��o de quantides por projetos
	char projetos[30] = {0};
	//Vari�veis de personagens [No do projeto][No. do personagem][Tamanho]
	char nome_personagem[30];
	char descricao_personagem[300];
	
	//Vari�veis de mundo
	char nome_mundo[30];
	char descricao_mundo[300];
	
	//Variáveis de local
	int quant_locais = {0};
	char nome_local[30];
	char descricao_local[300];
	
	//Variáveis de objetos importantes
	int quant_objetos = {0};
	char nome_objeto[30];
	char descricao_objeto[300];
	
	do{
		system("cls");
		printf( "Escolha uma opção: \n"
				"1 - Criar projeto\n"
				"2 - Editar projeto\n"
				"3 - Ver projeto\n"
				"Outro - Sair\n->");
		
		scanf("%d", &opcao);
		printf("\n-------------------------\n");
		
		
		switch(opcao){
			case 1:
				break;
			case 2:
				//printf("%s, %s\n", personagem_1_nome, personagem_1_apelido);
				break;
			case 3: 
				printf("****Em constru��o****\n\n");
				break;
			case 0:
			default:
				printf("Saindo...");
				rodando = 0;
		}
		
	}while(rodando==1);
	
}

