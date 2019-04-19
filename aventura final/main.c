#include <stdio.h>
#include "TabelaSim.h"

int yyparse();
Lista init_table();

int main()
{
  /* Monta o mundo */
	sym_table = init_table(sym_table);

	/* Descrição inicial */
	printf("Seu nome é Luke e você acaba de acordar numa cama em um quarto estranho."
		   " Você não sabe como chegou ali e sua memória mais recente se resume a seu"
		   " último dia de trabalho, que a  essa altura já não tem tanta certeza de a"
		   " quanto tempo foi. Você está no quarto que parece ha tempos desabitado,"
		   " ha tracas na parede e muito po espalhado. Procure examinar os lugares e objetos\n");
	puts("Aqui tem:");
	puts("\tcama");
	puts("\tportaCorredor");
	puts("\tparedeRachada");

	 // Que comece o jogo 
	while (yyparse());

	return 0; 
}






