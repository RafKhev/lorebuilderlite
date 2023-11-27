#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

#include "struct.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <conio.h>

#define MAX_NOME_PASTA 256
#define AUMENTA 1

//----------------------------
//     PROJETO
//----------------------------
void *listar_arquivos(char **path, int *quant, size_t tam, char tipo) {
  DIR *dir;
  struct dirent *entrada;
  struct stat statbuf;
  void **vetor; // Armazena um vetor de structs
  Mundo *mnd;
  int index = 0; // Indice do vetor

  // Abre diretorio
  dir = opendir(*path);
  printf("|%s|", *path);
  getch();
  if (dir == NULL) {
    printf("Caminho inválido... \nPressione qualquer tecla.");
    exit(EXIT_FAILURE);
  }

  vetor = (void **)malloc(1 * sizeof(void *));
  *quant = 0;

  while ((entrada = readdir(dir)) != NULL) {
    char caminho[MAX_NOME_PASTA + 8];
    snprintf(caminho, sizeof(caminho), *path, "%s/%s", *path, entrada->d_name);

    if (stat(caminho, &statbuf) == 0) {
        if (tipo == 'p' || tipo == 'o' || tipo == 'l') {
        if (S_ISREG(statbuf.st_mode)) {
            if (index >= AUMENTA) {
            vetor = (void **)realloc(vetor, (index + AUMENTA) * sizeof(void *));
            }

            memcpy((char *)vetor + index * tam, entrada->d_name, 40);
            memcpy((char *)vetor + index * tam + 40, caminho, 40);
            index++;
            (*quant)++;
        } else if (tipo == 'm') {
            if (S_ISDIR(statbuf.st_mode) && strcmp(entrada->d_name, ".") != 0 &&
                strcmp(entrada->d_name, "..") != 0) {
            if (index >= AUMENTA) {
                vetor =
                    (void **)realloc(vetor, (index + AUMENTA) * sizeof(void *));
            }

            mnd = (Mundo *)malloc(sizeof(Mundo));

            strcpy(mnd->nome, entrada->d_name);
            strcpy(mnd->desc, caminho);

            char caminho_objetos[MAX_NOME_PASTA + 8];

            sprintf(caminho_objetos, "%s/Objetos", caminho);

            mnd->objetos_importantes = (Objeto *)listar_arquivos(
                &caminho_objetos, &mnd->quant_objetos, sizeof(Objeto), 'o');

            char caminho_locais[MAX_NOME_PASTA + 8];
            sprintf(caminho_locais, "%s/Locais", caminho);

            mnd->locais_importantes = (Local *)listar_arquivos(
                &caminho_locais, &mnd->quant_locais, sizeof(Local), 'o');
            vetor[index] = mnd;
            index++;
            (*quant)++;
            }
        }
        }
    }
    }

    closedir(dir);
    return vetor;
}

void listar_projetos(char projetos[][MAX_NOME_PASTA], int *quant_projetos) {
    DIR *dir;
    struct dirent *entrada;
    struct stat statbuf;

    *quant_projetos = 0;

    dir = opendir("projetos");
    if (dir == NULL) {
        printf("Não foi possível abrir a pasta de projetos...\nPressione qualquer "
                "tecla.");
        exit(EXIT_FAILURE);
    }

    while ((entrada = readdir(dir)) != NULL) {
        char caminho[MAX_NOME_PASTA + 8];
        snprintf(caminho, sizeof(caminho), "projetos/%s", entrada->d_name);

        if (stat(caminho, &statbuf) == 0) {
            if (S_ISDIR(statbuf.st_mode) && strcmp(entrada->d_name, ".") != 0 &&
                strcmp(entrada->d_name, "..") != 0) {
            strcpy(projetos[*quant_projetos], entrada->d_name);
                (*quant_projetos)++;
            }
        }
    }

    closedir(dir);

    printf("Projetos disponíveis: \n");
    for (int i = 0; i < *quant_projetos; i++) {
        printf("%d - %s\n", i + 1, projetos[i]);
    }

    printf("Digite qualquer tecla para continuar...");
    getch();
    system("cls");
}

Projeto carregar_projeto(char projetos[][MAX_NOME_PASTA]) {
    int escolha;
    Projeto projetoSelecionado;
    int teste = 0;

    if (teste == 1){
        escolha == 0;
    }else{    
        printf("Digite o número do projeto escolhido: ");
        scanf("%d", &escolha);
        escolha--;
    }

    strcpy(projetoSelecionado.nome_projeto, projetos[escolha]);
    printf("|%d|%s|",&caminho, projetoSelecionado.nome_projeto);
    char caminho[50];

    sprintf(caminho, "%s/Personagens", projetoSelecionado.nome_projeto);
    projetoSelecionado.mundos = (Mundo *)listar_arquivos(
    &caminho, &projetoSelecionado.quant_mundos, sizeof(Mundo), 'm');

    printf("\n|%s|\n", *caminho);
    sprintf(caminho, "%s/Personagens", projetoSelecionado.nome_projeto);
    projetoSelecionado.personagens = (Personagem *)listar_arquivos(
    &caminho, &projetoSelecionado.quant_personagens, sizeof(Personagem), 'p');

    return projetoSelecionado;
}

//----------------------------
//     MENUS
//----------------------------

void menu_projeto(Projeto *proj) {
    printf("Menu de projetos...");
    //getch();
    // sys("cls");
    // Ir para menu de personagem/menu de mundo/retornar
}

void char_menu() {
    // Criar um personagem/Visualizar personagem
    // caminho: projetos/???/Personagens
}

void wld_menu() {
    // caminho: projetos/???/Mundos
    // Criar mundo/Visualizar mundo
    // Criar objeto/Visualizar objeto
    // Criar local/Visualizar local
}

#endif