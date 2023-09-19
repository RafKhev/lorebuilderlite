#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define MAX_PROJ 2
int main(){
	setlocale(LC_ALL, "");
	
	
	//Ints funcionais
	int rodando = 1, opcao; 
	int quant_projetos = 0;
	
	
	//Definição de quantides por projetos
	char projetos[MAX_PROJ][30] = {0};
	int max_personagens = 10,
		max_locais = 3,
		max_objetos = 3;
	
	//Variáveis de personagens [No do projeto][No. do personagem][Tamanho]
	int quant_personagens[MAX_PROJ] = {0};
	char nome_personagem[MAX_PROJ][max_personagens][30];
	char descricao_personagem[MAX_PROJ][max_personagens][300];
	
	//Variáveis de mundo
	char nome_mundo[MAX_PROJ][max_personagens][30];
	char descricao_mundo[MAX_PROJ][max_personagens][300];
	
	//Variáveis de local
	int quant_locais[MAX_PROJ] = {0};
	char nome_local[MAX_PROJ][max_personagens][30];
	char descricao_local[MAX_PROJ][max_personagens][300];
	
	//Variáveis de objetos importantes
	int quant_objetos[MAX_PROJ] = {0};
	char nome_objeto[MAX_PROJ][max_personagens][30];
	char descricao_objeto[MAX_PROJ][max_personagens][300];
	
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
				system("cls");
				quant_projetos++;
				printf("*****CRIANDO PROJETO %d******\n"
					   "Insira o nome: ", quant_projetos);
				gets(projetos[quant_projetos]);
				
				int criando = 1;
				do{
					
					printf("Escolha uma opção:\n"
						   "1 - Criar personagem\n"
						   "2 - Criar local\n"
						   "3 - Criar objeto importante\n"
						   "Outro - Retornar\n ->");
						   
					int op;
					scanf("%d", &op);
					switch(op){
						case 1:
							quant_personagens[quant_projetos]++;
							if(quant_personagens[quant_projetos] > max_personagens){
								printf("MÁXIMO DE PERSONAGENS EXCEDIDO");
								break;
							}
							
							printf("<>CRIANDO PERSONAGEM %d<>\nInsira o nome do personagem: ", quant_personagens);
							gets(nome_personagem[quant_projetos][quant_personagens]);
							printf("\nInsira a descrição do personagem: \n");
							gets(descricao_personagem[quant_projetos][quant_personagens]);
							break;
						case 2:
							quant_locais[quant_projetos]++
							if(quant_locais[quant_projetos] > max_locais){
								printf("MÁXIMO DE PERSONAGENS EXCEDIDO");
								break;
							}
							
							printf("<>CRIANDO LOCAL %d<>\nInsira o nome do local: ", quant_locais);
							gets(nome_personagem[quant_projetos][quant_locais]);
							printf("\nInsira a descrição do local: \n");
							gets(descricao_personagem[quant_projetos][quant_locais])
							break;
						case 3:
							quant_objetos[quant_projetos]++
							if(quant_personagens[quant_projetos] > max_objetos){
								printf("MÁXIMO DE objeto EXCEDIDO");
								break;
							}
							
							printf("<>CRIANDO OBJETO %d<>\nInsira o nome do objeto: ", quant_objetos);
							gets(nome_personagem[quant_projetos][quant_objetos]);
							printf("\nInsira a descrição do personagem: \n");
							gets(descricao_personagem[quant_projetos][quant_objetos])
							break;
						default: 
							criando = 0;
							break;
					}
				}//Fim criação 	
				//-------------------------------------------//
				break;
			case 2:
				//printf("%s, %s\n", personagem_1_nome, personagem_1_apelido);
				break;
			case 3: 
				printf("****Em construção****\n\n");
				break;
			case 0:
			default:
				printf("Saindo...");
				rodando = 0;
		}
		
	}while(rodando==1);
	
}

