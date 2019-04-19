#include "Lista.h"

typedef struct tabela{
    Lista indices[26];
} symrec;


symrec * CriaTabela();  //Cria a tabela de simbolos

symrec * Inseresymrec(symrec * t, char *n, int tipo, void *val);    //Insere elemento na tabela de simbolos

Lista Buscasymrec(symrec *t, char *nome);   //Busca um elemento na tabela de simbolos

symrec * Retirasymrec(symrec *t, char *nome);   //Retira elemento da tabela de simbolos

void printsym(symrec *sym_table);   //Imprime a tabela de simbolos

void Destroisymrec(symrec *t);  //Libera a memoria

extern Lista sym_table;