#include "TabelaSim.h"

/* Parte específica de Objeto */
typedef struct {
  short int ativo;
  short int visivel;
} Objeto;


/* Parte específica de lugar */
typedef struct lugar {
  struct elemento  *Saidas[6];		/* N,S,L,O,C,B */
} Lugar;

/* Estrutura geral para Elementos */
typedef struct elemento {
  char *nome;
  char *curta;
  char *longa;
  symrec *cont;
  symrec *acoes; // Tabela de simbolos de acoes que o objeto possui
  symrec *rel; // Tabela de simbolos de elementos relacionados
  int tipo; // 0 - Objeto, 1 - Lugar e 2 - Verbo
  int acessivel;
  union {
	Objeto obj;
	Lugar lug;
  } Det;						/* detalhe */
} Elemento;


/* Ponteiro para função */
typedef void (*Fptr)(Elemento *, Elemento *);

void Pegar(Elemento *o1, Elemento *o2);
void Largar(Elemento *o1, Elemento *o2);
void Examinar(Elemento *, Elemento *);
void Olhar(Elemento *o1, Elemento *o2);
int Ir(Elemento * local);
void DestroiTudo();


extern Elemento * Posic;			/* Posição atual */

extern Lista inventario;		/* O que está com o aventureiro */