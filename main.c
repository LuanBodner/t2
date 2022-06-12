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

    for (int i = 0; i < tamanho; i++) {
        TipoElemento *r = (TipoElemento *)malloc(sizeof(TipoElemento));
        r->chave = randomInteger(0, tamanho);
        hash_inserir(h, r);
    }

    hash_imprimir(h);
    TipoElemento *r1 = NULL;
    while (!hash_vazio(h)) {
        int position = randomInteger(0, tamanho);
        TipoElemento *r = NULL;

        if (hash_remover(h, position, &r)) {
            free(r);
            r = NULL;
        }
    }
    hash_destruir(&h);
}

int main(int argc, char *argv[]) {
    int tamanho = atoi(argv[1]);
    teste1(argc, argv);

    return 0;
}
