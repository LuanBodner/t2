#include <stdio.h>
#include <string.h>
#include <time.h>

#include "hash.h"

int randomInteger(int low, int high) {
    double d;
    d = (double)rand() / ((double)RAND_MAX + 1);
    int k = d * (high - low + 1);

    return low + k;
}

int teste1(int argc, char *argv[]) {
    int tamanho = atoi(argv[1]);
    Hash *h = hash_criar(tamanho);
    int i = 0, collision_counter = 0;
    for (; i < tamanho / 2; i++) {
        TipoElemento *r = (TipoElemento *)malloc(sizeof(TipoElemento));
        r->chave = randomInteger(0, tamanho);
        hash_inserir(h, r, &collision_counter);
    }

    hash_destruir(&h);
}

int main(int argc, char *argv[]) {
    int tamanho = atoi(argv[1]);
    teste1(argc, argv);

    return 0;
}
