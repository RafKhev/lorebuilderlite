#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

typedef struct _obj {
    char nome[30];
    char desc[400];
}Objeto;

typedef struct _local {
    char nome[30];
    char desc[400];
}Local;

typedef struct _mundo {
    char nome[30];
    char desc[400];
    Local *locais_importantes;
    int quant_locais;
    Objeto *objetos_importantes;
    int quant_objetos;

    Mundo *proximo_mundo;
}Mundo;

typedef struct _personagem {
    char nome[30];
    char desc[400];

    Personagem *proximo_personagem;
}Personagem;

typedef struct _projeto {
    char nome_projeto[30];
    int quant_personagens;
    int quant_mundos;
    Personagem *personagens;
    Mundo *mundos;
}Projeto;

#endif