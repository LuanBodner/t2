#include "hash.h"

#define TAM_INICIAL 100000

/**************************************
 * FUNÇÕES AUXILIARES
 **************************************/

bool hash_ehValida(Hash *h) { return (h != NULL ? true : false); }

int hash_funcao2(Hash *h, int chave) {
    return (int)(50000 * ((chave * 0.61235) - (int)(chave * 0.61235)));
}

int hash_funcao1(Hash *h, int chave) { return chave % h->tamanho; }

/**************************************
 * IMPLEMENTAÇÃO
 **************************************/

Hash *hash_criar(int tamanho) {
    Hash *h = (Hash *)malloc(sizeof(Hash));
    h->itens = (TipoElemento **)malloc(sizeof(TipoElemento) * tamanho);

    for (int i = 0; i < tamanho; i++) {
        h->itens[i] = NULL;
    }

    h->qtde = 0;
    h->tamanho = tamanho;

    return h;
}

void hash_destruir(Hash **enderecoHash) {
    if (enderecoHash == NULL) return;
    if (!hash_ehValida(*enderecoHash)) return;

    Hash *h = *enderecoHash;
    free(h->itens);
    free(h);
    *enderecoHash = NULL;
}

int double_hash(Hash *h, int sp) {
    int fp = sp, i = 0;
    while (h->itens[fp] != NULL)
        fp = linear_probe(h, fp) + (i++ * quad_probe(h, fp));
    return fp;
}

int quad_probe(Hash *h, int sp) {
    int fp = sp, c1 = 1, c2 = 1, i = 1, start = 1;

    while (h->itens[fp] != NULL) {
        fp = fp + c1 * i + c2 * pow(i, 2);
        i++;
        if (h->tamanho <= fp) fp = start++;
    }
    return fp;
}

int linear_probe(Hash *h, int sp) {
    int fp = sp;
    while (h->itens[fp] != NULL) {
        if (h->tamanho <= fp)
            fp = 0;
        else
            fp++;
    }
    return fp;
}

bool hash_inserir(Hash *h, TipoElemento *elemento, int *counter) {
    int pos = hash_funcao1(h, elemento->chave);
    if (h->itens[pos] != NULL) {
        pos = double_hash(h, pos);
        if (pos >= h->tamanho) pos = pos - h->tamanho;
    }
    h->itens[pos] = elemento;
    h->qtde++;
    return true;
}

bool hash_remover(Hash *h, int chave, TipoElemento **elemento) {
    int pos = hash_funcao1(h, chave);
    if (h->itens[pos] != NULL) pos = linear_probe(h, pos);

    *elemento = h->itens[pos];
    h->itens[pos] = NULL;
    h->qtde--;

    return true;
}

int hash_tamanho(Hash *ha) { return ha->qtde; }

bool hash_cheio(Hash *ha) { return (ha->qtde == ha->tamanho); }

bool hash_vazio(Hash *ha) {
    if (ha->qtde == 0) return true;
    return false;
}

void hash_imprimir(Hash *h) {
    printf("[");
    for (int i = 0; i < h->tamanho - 1; i++) {
        if (h->itens[i] != NULL)
            printf("X");
        else
            printf(" ");
    }
    if (h->itens[h->tamanho - 1] != NULL)
        printf("X");
    else
        printf(" ");

    printf("]\n");
}