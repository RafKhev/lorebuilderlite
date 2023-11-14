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
    Local locais_importantes;
    Objeto objetos_importantes;
}Mundo;

typedef struct _personagem {
    char nome[30];
    char desc[400];
    Mundo mundo_origem;
}Personagem;

typedef struct _projeto {
    char nome_projeto[30];
    Personagem personagens;
    Mundo mundos;
}Projeto;

#endif