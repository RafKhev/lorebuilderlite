#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

#include "func.h"
#include "struct.h"

int main()
{
	setlocale(LC_ALL, "Portuguese");

	// Ints funcionais
	int rodando = 1, opcao;

	// Defini��o de quantides por projetos
	char nome_projeto[30];

	

	/*****************************************/
	//			ESTRUTURA PRINCIPAL
	/*****************************************/
	//printf("Digite o nome do projeto: ");
	//scanf("%s", &nome_projeto);
	do{

		/*
		printf("▄█        ▄██████▄     ▄████████    ▄████████ ▀█████████▄  ███    █▄   ▄█   ▄█       ████████▄     ▄████████    ▄████████  "
			   "███       ███    ███   ███    ███   ███    ███   ███    ███ ███    ███ ███  ███       ███   ▀███   ███    ███   ███    ███ "
			   "███       ███    ███   ███    ███   ███    █▀    ███    ███ ███    ███ ███▌ ███       ███    ███   ███    █▀    ███    ███ "
			   "███       ███    ███  ▄███▄▄▄▄██▀  ▄███▄▄▄      ▄███▄▄▄██▀  ███    ███ ███▌ ███       ███    ███  ▄███▄▄▄      ▄███▄▄▄▄██▀ "
			   "███       ███    ███ ▀▀███▀▀▀▀▀   ▀▀███▀▀▀     ▀▀███▀▀▀██▄  ███    ███ ███▌ ███       ███    ███ ▀▀███▀▀▀     ▀▀███▀▀▀▀▀   "
			   "███       ███    ███ ▀███████████   ███    █▄    ███    ██▄ ███    ███ ███  ███       ███    ███   ███    █▄  ▀███████████ "
			   "███▌    ▄ ███    ███   ███    ███   ███    ███   ███    ███ ███    ███ ███  ███▌    ▄ ███   ▄███   ███    ███   ███    ███ "
			   "█████▄▄██  ▀██████▀    ███    ███   ██████████ ▄█████████▀  ████████▀  █▀   █████▄▄██ ████████▀    ██████████   ███    ███ "
			   "▀                      ███    ███                                           ▀                                   ███    ███ ");
		*/

		int op = 0;

    	system("cls");

		printf("Escolha uma opção: \n"
			"1 - Personagens\n"
			"2 - Mundos\n"
			"Outro - Sair\n->");

        scanf("%d", &op);
        printf("\n-------------------------\n");
        
        switch (op){
            case 1:
                //char_menu();
                break;
            case 2:
                //wld_menu();
                break;
            default: 
			rodando = 0;
			break;
        }
	}while(rodando==1);


	/*****************************************/
	//			PERSONAGENS
	/*****************************************/

	int func_char = 1;

	do
	{
		/*
		if (op_char == 1)
		{
			fflush(stdin);
			int index_edit;

			for (int i = 0; i < quant_personagens; i++)
			{
				if (nome_personagem[i][0] == NULL)
				{
					index_edit = i;
				}
				else
				{
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
		else if (op_char == 2)
		{
			if (quant_personagens_usados == 0)
			{
				printf("Não há personagens cadastrados!");
				getch();
				system("cls");
				continue;
			}

			for (int i = 0; i < quant_personagens; i++)
			{
				if (nome_personagem[i][0] != NULL)
				{
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
		else if (op_char == 3)
		{
			// editar
		}
		else
		{
			continue;
		}
		*/
	} while (func_char == 1);
	return 0;
}


