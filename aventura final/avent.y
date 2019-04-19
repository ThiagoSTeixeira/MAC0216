/* Calculadora infixa */

%{
#include <stdio.h>
#include "coisas.h"
  
int yylex();
int yyerror(char *);

/* Macro para simplificar a escrita das chamadas de função */
#define F(x) (*(Fptr)(x->val))

/* Identifica qual a versão correta do verbo chamado */
Lista AcertaF(Lista f, Lista o1) {
  Lista s;

  /* Verifica se existe uma versão especial no local atual (Posic) */
  if (Posic->cont) {
    s = Buscasymrec(Posic->cont, f->nome);
    if (s)
    	return s;
  }

  /* Verifica se o primeiro objeto tem uma versão especial */
  if (o1) {
    Elemento *o = o1->val;
    if (o->cont) {
      s = Buscasymrec(o->cont, f->nome);
      if (s) 
        return s;
    }
  }
  return f;	

}
%}

/* Declaracoes */
%union {
  Lista tptr;
  char *str;
  int  direc;
}

%token <tptr> VERBO OBJ LUGAR

/* DESC representa uma palavra desconhecida */
%token <str> DESC
%token  NORTE SUL LESTE OESTE CIMA BAIXO VAPARA EOL FIM INVENT

%type <direc> dir
%type <tptr> obj

%defines

%%
/* Gramatica */
input: EOL		{ printf("Zzzz...\n"); }
    | cmd
	| VAPARA  {
	  		   /* movimentação */
	  		   printf("Seguindo para ");
	  		  }
			  dir {
                    // Verifica se eh uma direcao mesmo e se tem uma sala nessa direcao.
					if ($3 >= 0 && Posic->Det.lug.Saidas[$3]) {
                          if (Ir(Posic->Det.lug.Saidas[$3])) {
					          Posic = Posic->Det.lug.Saidas[$3];
                              Posic->acessivel = 1;
					          Examinar(NULL, NULL); // Examina a sala automaticamente quando entrar nela
                              // Caso a sala nova seja o lado de fora da casa, o jogo esta acabado.  
                              if (strcmp(Posic->nome, "fora") == 0) {
                                  printf("Parabens, voce venceu o jogo!!!\n");
                                  DestroiTudo();
                                  return 0;
                              }
                          }
					}
					else puts("Não há passagem....");
			      } eol
	 | dir {
			 /* movimentação  */
             // Verifica se eh uma direcao mesmo e se tem uma sala nessa direcao.
             if ($1 >= 0 && Posic->Det.lug.Saidas[$1]) {
               if (Ir(Posic->Det.lug.Saidas[$1])) {
                 Posic = Posic->Det.lug.Saidas[$1];
                 Posic->acessivel = 1;
                 Examinar(NULL, NULL); // Examina a sala automaticamente quando entra nela
                 // Caso a sala nova seja o lado de fora da casa, o jogo esta acabado.
                 if (strcmp(Posic->nome, "fora") == 0) {
                    printf("Parabens, voce venceu o jogo!!!\n");
                    DestroiTudo();
                    return 0;
                 }
               }
			 }
			 else puts("Não há passagem....");
											} eol

	| INVENT {
			 /* listagem do inventário */
			 if (inventario) {
			   puts("Você tem:");
			   ImprimeLista(inventario);
			 }
			 else puts("Você está sem nada no momento...");
												
		 } eol
	| FIM  { 
            DestroiTudo(); // Libera todas as memorias alocadas.
            return 0;
           }
	| DESC { puts("Não tem registro, Will Robinson.");}
	| error eol;
;

cmd: VERBO {
			 /* Intransitivo */
  	 	     F(AcertaF($1,NULL))(NULL,NULL);
		   } eol
   | VERBO obj {
			   /* Transitivo direto */
			   F(AcertaF($1,$2))($2->val,NULL);
			 } eol 
   | VERBO obj obj {
                 /* Bitransitivo */
			     F(AcertaF($1,$2))($2->val,$3->val);
			   } eol
   | VERBO DESC {
			     printf("%s??\n", $2);
			 } eol 
   | VERBO obj DESC {
			   printf("não sei o que é isso: %s\n",  $3);
			   } eol 
   | VERBO DESC DESC {
			     printf("Pare de jogar e vá descansar um pouco\n"
						"Fazer isso com %s e %s, que coisa\n", $2,$3);
			   } eol 
;

obj: OBJ    { $$ = $1;}
   | LUGAR  { $$ = $1;}

dir: NORTE	  { puts("norte"); $$=0;}
	 | SUL	  { puts("sul");   $$=1;}
	 | LESTE  { puts("leste"); $$=2;}
	 | OESTE  { puts("oeste"); $$=3;}
	 | CIMA	  { puts("cima");  $$=4;}
	 | BAIXO  { puts("baixo"); $$=5;}
	 | DESC   { puts("... (onde é isso?)"); $$=-1;}
;

eol: EOL {return 1;}
%%

int yyerror(char *s) {
  puts("Não entendi...");
  return 0;
}
