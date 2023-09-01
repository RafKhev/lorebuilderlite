#include <stdio.h>
#include <locale.h>
int main(){
	setlocale(LC_ALL, "");
	
	int numPersonagens;
	
	//Ints funcionais
	int rodando = 1, opcao; 
	
	//Variáveis de personagens
	char personagem_1_nome[20],
		personagem_1_apelido[20];
		
	do{
		printf( "Escolha uma opção: \n"
				"1 - Criar personagem\n"
				"2 - Ver personagens\n"
				"3 - Editar personagens\n"
				"Outro - Sair\n->");
		
		scanf("%d", &opcao);
		printf("\n-------------------------\n");
		
		
		switch(opcao){
			case 1:
				printf("Digite o nome do personagem 1: ");
				scanf("%s", &personagem_1_nome);
				printf("Digite o apelido do personagem 1: ");
				scanf("%s", &personagem_1_apelido);
				break;
			case 2:
				printf("%s, %s\n", personagem_1_nome, personagem_1_apelido);
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

