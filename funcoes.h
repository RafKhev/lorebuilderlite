#include <dirent.h>
#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED


//Funções de load

int carregar_projeto(projeto p){
    DIR* pasta = opendir(".");
    if (pasta == NULL){
        return 1;
    }

    struct dirent* entidade;

    entidade = readdir(pasta); //Lê a pasta
    while (entidade != NULL){
        printf("%s\n", entidade->d_name);
        entidade = readdir(pasta);
    }

    closedir(pasta);
}

//Funções de criação

void criar(){
    return;
}

void criar_personagem(){
    return;
}

void criar_mundo(){
    return;
}

//Funções de edição




#endif