#include "Lista.h"

Lista CriaLista()
{
    Lista l;
    l = NULL;
    return l;
}

void DestroiLista(Lista l)
{
    //Destroi toda a lista.
    Lista atual, anterior;
    atual = l;
    anterior = NULL;

	while (atual != NULL) {
        anterior = atual;
        atual = atual -> prox;
        free(anterior -> nome);
        free(anterior);
    }
    
}

Lista InsereLista (Lista l, char * nome_val, int tipo, void * novo_val) 
{
    // Insere no inicio da lista
    Lista nova = malloc(sizeof(Elo));
    nova->nome = malloc(strlen(nome_val));
    strcpy(nova->nome, nome_val);
    nova->tipo = tipo;
    nova->val = novo_val;
    nova->prox = l;
    return nova;
}

Lista BuscaNaLista (Lista l, char *nome_buscado)
{
    //Busca na lista usando uma funcao de comparacao
    Lista p = l;

    while(p != NULL)
    {

        if(strcmp(nome_buscado, p->nome) == 0)
            return p;

        p = p->prox;
    }

    return NULL;
}

Lista RetiraDaLista(Lista l, char *nome)
{
    //Retira da lista usando uma funcao de comparacao na busca
    Lista p = l, ant = NULL, retirada = NULL;

    while (p != NULL && strcmp(p->nome, nome) != 0) {
        ant = p;
        p = p->prox;
    }

    if (ant != NULL) {

        if (p != NULL) {
            retirada = p;
            ant -> prox = p -> prox;
        }

    }

    else {

        if (p != NULL) {
            retirada = p;
            l = p -> prox;
        }

    }

    free(retirada->nome);
    free(retirada);

    return l;
}

void ImprimeLista (Lista l) {
    Lista p = l;

    while (p != NULL) {
        printf("\t%s\n", p->nome);
        p = p->prox;
    }

}