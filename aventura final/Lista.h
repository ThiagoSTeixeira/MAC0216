#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Definição de uma lista de 
//dados Genéricos

typedef struct elo{
	char * nome;
    void * val;
    int tipo; 
    struct elo * prox;
} Elo;

typedef Elo* Lista;

// Cria e retorna uma lista vazia

Lista CriaLista ();

// Destroi a lista l liberando todos os seus elos

void DestroiLista (Lista l);

// Imprime a lista

void ImprimeLista(Lista l);

// Insere no Inicio da Lista l o elemento novo_val

Lista InsereLista (Lista l, char * nome_val, int tipo, void * novo_val);

// Devolve um ponteiro para o Elo onde o val_buscado se encontra
// ou NULL se o val_buscado não estiver na lista

Lista BuscaNaLista (Lista l, char *nome_buscado);

// Retira da lista l o elo que contém o valor val, devolvendo o elo
// ou NULL se ele não for encontrado

Lista RetiraDaLista (Lista l, char *val);