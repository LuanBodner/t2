#ifndef _HASH_H_
#define _HASH_H_

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct TipoElemento {
    int chave;
    int dado;
} TipoElemento;

typedef struct hash {
    int qtde, tamanho;
    TipoElemento **itens;
} Hash;

Hash *hash_criar(int tamanho);
int hash_tamanho(Hash *ha);
void hash_destruir(Hash **enderecoHash);
bool hash_inserir(Hash *ha, TipoElemento *elemento, int *collision_counter);
bool hash_remover(Hash *h, int chave, TipoElemento **elemento);
bool hash_cheio(Hash *ha);
bool hash_vazio(Hash *ha);
void hash_imprimir(Hash *ha);

int linear_probe(Hash *h, int sp);
int double_hash(Hash *h, int sp);
int quad_probe(Hash *h, int sp);
#endif