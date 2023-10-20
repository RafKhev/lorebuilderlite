#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

int main(){
	setlocale(LC_ALL, "");

	// Ints funcionais
	int rodando = 1, opcao;

	// Defini��o de quantides por projetos
	char nome_projeto[30];
	// Vari�veis de personagens [No. do personagem][Tamanho]
	int quant_personagens = 10;
	int quant_personagens_usados = 0;
	char nome_personagem[quant_personagens][30];
	char descricao_personagem[quant_personagens][300];
	memset(nome_personagem, 0, quant_personagens*30*sizeof(char));
	memset(descricao_personagem, 0, quant_personagens*300*sizeof(char));
	
	// Vari�veis de mundo
	int quant_mundo = 3;
	char nome_mundo[quant_mundo][30];
	char descricao_mundo[quant_mundo][300];

	// Variáveis de local
	int quant_locais = 10;
	char nome_local[quant_locais][30];
	char descricao_local[quant_locais][300];

	// Variáveis de objetos importantes
	int quant_objetos = 25;
	char nome_objeto[quant_objetos][30];
	char descricao_objeto[quant_objetos][300];

	/*****************************************/
	//			ESTRUTURA PRINCIPAL
	/*****************************************/
	printf("Digite o nome do projeto: ");
	scanf("%s", &nome_projeto);

	do{
		system("cls");

		printf("Escolha uma opção: \n"
			"1 - Personagens\n"
			"2 - Mundos\n"
			"Outro - Sair\n->");

			scanf("%d", &opcao);
			printf("\n-------------------------\n");
			
			switch (opcao){
			case 1:
				printf("Char");
				system("cls");
				/*****************************************/
				//			PERSONAGENS
				/*****************************************/

				int func_char = 1;

				do{
					printf("<<<< PERSONAGENS >>>>\n");
						   
					printf("Escolha uma opção\n1 - Criar novo\n2 - Visualizar\n3 - Editar\n->");

					int op_char;
					scanf("%d", &op_char);
					/*
					*	Iterar através da lista de personagens, e se 
					*	o indice estiver vazio, definir o mesmo como o atual;
					*	se todos estiverem preenchidos, o último será sobscrito
					*/

					if(op_char == 1){
						fflush(stdin);
						int index_edit;

						for(int i = 0;i < quant_personagens;i++){
							if(nome_personagem[i][0] == NULL){
								index_edit = i;
							}else{
								index_edit = quant_personagens;
							}
						}
						printf("Criando personagem #%d\nInsira um nome:", index_edit);
						gets(nome_personagem[index_edit]);
						fflush(stdin);
						printf("Insira a descrição: \n");
						gets(descricao_personagem[index_edit]);
						fflush(stdin);

						printf("--------------------------\n");
						printf("%s\n", nome_personagem[index_edit]);
						printf("--------------------------\n");
						printf("%s\n", descricao_personagem[index_edit]);
						printf("Digite qualquer tecla para continuar...");
						quant_personagens_usados++;
						getch();
						system("cls");
						continue;
					}
					else if(op_char == 2){
						if (quant_personagens_usados == 0)
						{
							printf("Não há personagens cadastrados!");
							getch();
							system("cls");
							continue;
						}
						
						for(int i=0;i<quant_personagens;i++){
							if(nome_personagem[i][0] != NULL){
								printf("-------------------------\n"
									   "\t%s\t\t\n"
									   "-------------------------\n"
									   "%s\n",
									   nome_personagem[i], descricao_personagem[i]);
							}
						}
						printf("Digite qualquer tecla para continuar...\n");
						getch();
						system("cls");
					}
					else if(op_char == 3){
						//editar
					}else{continue;}
						   

				}while(func_char == 1);

				break;
			case 2:
				printf("Wld");
				break;
			case 0:default:
				printf("Saindo...");
				rodando = 0;
				return 0;
		}
	}while(rodando == 1);

	return 0;
}

