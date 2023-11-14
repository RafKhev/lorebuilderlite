#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <conio.h>
#include "struct.h"

#define MAX_NOME_PASTA 256


//----------------------------
//     PROJETO
//----------------------------

void listar_projetos(char projetos[][MAX_NOME_PASTA], int *quant_projetos){
    DIR *dir;
    struct dirent *entrada;
    struct stat statbuf;

    *quant_projetos = 0;

    dir = opendir("projetos");
    if(dir == NULL){
        printf("Não foi possível abrir a pasta de projetos...\nPressione qualquer tecla.");
        exit(EXIT_FAILURE);
    }

    while((entrada = readdir(dir)) != NULL){
        char caminho[MAX_NOME_PASTA+8];
        snprintf(caminho, sizeof(caminho), "projetos/%s", entrada->d_name);

        if(stat(caminho, &statbuf) == 0){
            if(S_ISDIR(statbuf.st_mode) && strcmp(entrada->d_name, ".") !=0 && strcmp(entrada->d_name, "..") != 0){
                strcpy(projetos[*quant_projetos], entrada->d_name);
                (*quant_projetos)++;
            }
        }
    }

    closedir(dir);

    printf("Projetos disponíveis: \n");
    for(int i = 0;i< *quant_projetos; i++){
        printf("%d - %s\n", i+1, projetos[i]);
    }

    printf("Digite qualquer tecla para continuar...");
    getch();
    system("cls");

}

Projeto carregar_projeto(char projetos[][MAX_NOME_PASTA], int quant_projetos){
    int escolha;
    Projeto projetoSelecionado;

    printf("Digite o número do projeto escolhido: ");
    scanf("%d", &escolha);
    escolha--;

    strcpy(projetoSelecionado.nome_projeto, projetos[escolha]);

    //Funções de carregar projeto vai aqui

    return projetoSelecionado;

}

//----------------------------
//     MENUS
//----------------------------

void menu_projeto(Projeto *proj){
    printf("Menu de projetos...");
    getch();
    sys("cls");
    //Ir para menu de personagem/menu de mundo/retornar
}  

void char_menu(){
    //Criar um personagem/Visualizar personagem
    //caminho: projetos/???/Personagens
}

void wld_menu(){
    //caminho: projetos/???/Mundos
    //Criar mundo/Visualizar mundo
        //Criar objeto/Visualizar objeto
        //Criar local/Visualizar local
}

#endif 