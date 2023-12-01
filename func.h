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
#define AUMENTA 1

//----------------------------
//     PROJETO
//----------------------------

/*
void *listar_arquivos(char **path, int *quant, size_t tam, char tipo){
    DIR *dir;
    struct dirent *entrada;
    struct stat statbuf;
    void **vetor; //Armazena um vetor de structs
    Mundo *mnd;
    int index = 0; //Indice do vetor

    //Abre diretorio
    dir = opendir(*path);
    if(dir == NULL){
        printf("Caminho inválido... \nPressione qualquer tecla.");
        exit(EXIT_FAILURE);
    }

    vetor = malloc(AUMENTA * sizeof(void*));
    *quant = 0;

    while((entrada = readdir(dir)) != NULL){
        char caminho[MAX_NOME_PASTA+8];
        snprintf(caminho, sizeof(caminho), *path, "%s/%s", *path,entrada->d_name);

        if(stat(caminho, &statbuf) == 0){
            if(tipo == 'p' || tipo == 'o' || tipo == 'l'){
                if(S_ISREG(statbuf.st_mode)){
                    if(index >= AUMENTA){
                        vetor = realloc(vetor, (index+AUMENTA) * sizeof(void*));
                    }

                    memcpy((char*)vetor+index*tam, entrada->d_name, 40);
                    memcpy((char*)vetor+index*tam+40, caminho, 40);
                    index++;
                    (*quant)++;
                }else if(tipo == 'm'){
                    if(S_ISDIR(statbuf.st_mode) && strcmp(entrada->d_name, ".") !=0 && strcmp(entrada->d_name, "..") != 0){
                        if(index >= AUMENTA){
                            vetor = realloc(vetor, (index+AUMENTA) * sizeof(void*));
                        }

                        mnd = malloc(sizeof(Mundo));
            
                        strcpy(mnd->nome, entrada->d_name);
                        strcpy(mnd->desc, caminho);

                        char caminho_objetos[MAX_NOME_PASTA+8];
                        sprintf(caminho_objetos, "%s/Objetos", caminho);

                        mnd->objetos_importantes = (Objeto *)listar_arquivos(&caminho_objetos, &mnd->quant_objetos, sizeof(Objeto), 'o');

                        char caminho_locais[MAX_NOME_PASTA+8];
                        sprintf(caminho_locais, "%s/Locais", caminho);

                        mnd->locais_importantes = (Local *)listar_arquivos(&caminho_locais, &mnd->quant_locais, sizeof(Local), 'o');
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

função não funciona direito
*/


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
/*
Projeto carregar_projeto(char projetos[][MAX_NOME_PASTA], int quant_projetos){
    int escolha;
    Projeto projetoSelecionado;

    printf("Digite o número do projeto escolhido: ");
    scanf("%d", &escolha);
    escolha--;

    strcpy(projetoSelecionado.nome_projeto, projetos[escolha]);
    char caminho[50];

    sprintf(caminho, "%s/Personagens", projetoSelecionado.nome_projeto);
    projetoSelecionado.mundos = listar_arquivos(&caminho, &projetoSelecionado.quant_mundos, sizeof(Mundo), 'm');

    sprintf(caminho, "%s/Personagens", projetoSelecionado.nome_projeto);
    projetoSelecionado.personagens = listar_arquivos(&caminho, &projetoSelecionado.quant_personagens, sizeof(Personagem), 'p');

    return projetoSelecionado;

}
*/

void ler_entre(char *nome_arquivo, char *inicio, char *fim){
    FILE *arquivo;
    
    arquivo = fopen(nome_arquivo, "r");
    if(arquivo == NULL){
        printf("Não foi possível abrir o arquivo");
        exit(EXIT_FAILURE);
    }
    

    char linha[100];
    int encontrado = 0;
    while(fgets(linha, 100, arquivo) != NULL){
        if(encontrado == 0){
            if(strstr(linha, inicio) != NULL){
                encontrado = 1;
            }
        }
        else{
            if(strstr(linha, fim) != NULL || feof(arquivo)){
                break;
            }
            else {
                printf("%s", linha);
            }
        }
    }

    fclose(arquivo);

}

Projeto criar_projeto(){

    printf("CRIANDO NOVO PROJETO");

    Projeto proj;
    char nome[40], nome_completo[45], select; 
    printf("Digite o nome do projeto: ");
    scanf("%s", &nome);
    strcpy(proj.nome_projeto, nome);
    /*
    printf("Deseja criar agora? S/N\n");
    while(select != "S" || select != "s" || select != "N" || select != "n"){
        scanf(" %c", &select);
    }
    */

    FILE *arquivo;

    char texto[] = "PROJETO\n\n"
                    "ENDPROJ\n\n"
                    "PERSONAGEM\n\n"
                    "ENDPERSONAGEM\n\n"
                    "MUNDO\n\n"
                    "ENDMUNDO\n\n"
                    "LOCAL\n\n"
                    "ENDLOCAL\n\n"
                    "OBJETO\n\n"
                    "ENDOBJETO\n\n";

    strcpy(nome_completo, nome);
    strcat(nome_completo, ".lbp");

    arquivo = fopen(nome_completo, "w");
    if(arquivo == NULL){
        printf("Não foi possível abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    fwrite(texto,1,sizeof(texto),arquivo);
    fclose(arquivo);
    printf("Projeto criado e carregado com sucesso!");
    return proj;
}


//----------------------------
//     PERSONAGEM
//----------------------------


void criar_personagem(){
    printf("Digite o nome do personagem: ");
    char nome[40];
    scanf("%s", &nome);

    printf("Insira a informação do personagem:");

    Personagem *novo = (Personagem*)malloc(sizeof(Personagem));

    if(novo == NULL){
        printf("Erro na alocação de memória");
        exit(1);
    }

    strcpy(novo->nome, nome);
    strcpy(novo->desc, '\0');
    novo->proximo_personagem = NULL;
}

void adicionar_personagem(Personagem **lista, Personagem *novo){
    Personagem *aux = *lista;

    if(aux == NULL){
        aux = aux->proximo_personagem;
        aux->proximo_personagem = novo;
    }
}

void concat_personagem(){

}


//----------------------------
//     MENUS
//----------------------------

void menu_projeto(Projeto *proj){
    printf("Menu de projetos...");
    getch();
    //sys("cls");
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