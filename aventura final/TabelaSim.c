#include "TabelaSim.h"

//Identifica a primeira letra da palavra e retorna um índice correspondente com a ordem dessa letra no alfabeto
int hash (char * nome) {

    int h = nome[0];

    if (h >= 97)
        return h - 97;

    return h - 65;
}

//Cria a tabela de simbolos
symrec * CriaTabela(){
    int i;
    symrec * Tabela = malloc(sizeof(symrec));

    for(i = 0; i < 26; i++)
        Tabela->indices[i] = CriaLista();

    return Tabela;
}
// Insere um elemento na tabela de simbolo
symrec * Inseresymrec(symrec * t, char *nome, int tipo, void *val)
{
    int ind = hash(nome);

    if (!BuscaNaLista(t->indices[ind], nome)) {
        t->indices[ind] = InsereLista(t->indices[ind], nome, tipo, val);
    }

    return t;
}
//Busca na tabela de simbolos
Lista Buscasymrec(symrec * t, char* nome)
{
    int ind = hash(nome);

    return BuscaNaLista(t->indices[ind], nome);
}
//Retira elemento da tabela
symrec * Retirasymrec(symrec * t, char *nome)
{
    int ind = hash(nome);
       
    t->indices[ind] = RetiraDaLista(t->indices[ind], nome);

    return t;
}
//Imprime a tabela de simbolos
void printsym(symrec *sym_table)
{
  int i;

  for (i = 0; i < 26; i++) {
    ImprimeLista(sym_table->indices[i]);
  }

}

//Libera a memoria 
void Destroisymrec(symrec *t)
{
    for(int i = 0;i<26;i++)
        DestroiLista(t->indices[i]);
    free(t);
}