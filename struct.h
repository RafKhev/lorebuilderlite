#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

typedef struct _obj {
    char nome[30];
    char desc[40];
}Objeto;

typedef struct _local {
    char nome[30];
    char desc[40];
}Local;

typedef struct _mundo {
    char nome[30];
    char desc[40];
    Local *locais_importantes;
    int quant_locais;
    Objeto *objetos_importantes;
    int quant_objetos;
}Mundo;

typedef struct _personagem {
    char nome[30];
    char desc[40];
}Personagem;

typedef struct _projeto {
    char nome_projeto[30];
    int quant_personagens;
    int quant_mundos;
    Personagem *personagens;
    Mundo *mundos;
}Projeto;

#endif