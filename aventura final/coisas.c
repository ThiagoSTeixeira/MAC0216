#include "coisas.h"
#include "avent.tab.h"

/* Variáveis globais */
Lista sym_table = NULL; /* Tabela de símbolos global */
Lista inventario = NULL; /* material com o aventureiro */
Elemento *Posic; /* Posição atual */

//Declarando os elementos
Elemento PortaCorredor = {
    "portaCorredor", 
    "Porta de madeira", 
    "Porta de madeira levemente avermelhada. Será que está aberta?", 
    (symrec *) 0,
    (symrec *) 0,
    (symrec *) 0,
    OBJ,
    0,
    .Det.obj = {1, 1} };

Elemento PortaBanheiro = {
    "portaBanheiro", 
    "Porta do banheiro", 
    "Uma porta de madeira simples com uma tranca, leva ao banheiro",
    (symrec *) 0,
    (symrec *) 0,
    (symrec *) 0,
    OBJ,
    0,
    .Det.obj = {1, 1} };

Elemento PortaSalao = {
    "portaSalao",  
    "Porta do salao", 
    "Uma porta de madeira simples com uma tranca, leva ao salao",
    (symrec *) 0,
    (symrec *) 0,
    (symrec *) 0,
    OBJ,
    0,
    .Det.obj = {1, 1} };

Elemento PortaDaSalaDeEstar = {
    "portaSala", 
    "Porta de madeira escura", 
    "Essa porta pode me levar a algum lugar interessante."
    " Parece que preciso de uma senha pra destrancar o cadeado dela.", 
    (symrec *) 0,
    (symrec *) 0,
    (symrec *) 0,
    OBJ,
    0, 
    .Det.obj = {1, 1} };

Elemento PortaDaCozinha = {
    "portaCozinha", 
    "Porta de aluminio", 
    "Essa porta me leva à cozinha. Posso achar coizas muito úteis lá", 
    (symrec *) 0,
    (symrec *) 0,
    (symrec *) 0,
    OBJ,
    0, 
    .Det.obj = {1, 1} };

Elemento PortaPrincipal = {
    "portaPrincipal", 
    "Porta de madeira clara", 
    "Essa é a porta principal. Se conseguir abri-la estarei livre", 
    (symrec *) 0,
    (symrec *) 0,
    (symrec *) 0,
    OBJ,
    0,
    .Det.obj = {1, 1} };

Elemento ChaveDaPortaInicial = {
    "chavePortaInicial", 
    "Chave", 
    "Uma chave de bronze comum. Acho que consigo"
    " usa-la pra Destrancar a porta.", 
    (symrec *) 0,
    (symrec *) 0,
    (symrec *) 0,
    OBJ,
    1, 
    .Det.obj = {1, 0} };

Elemento Marreta = {
    "marreta", 
    "Grande marreta, acho que consigo usa-la pra algo.", 
    "Grande marreta e pesada, com cabo de madeira e"
    " levemente enferrujada, talvez consiga usa-la", 
    (symrec *) 0,
    (symrec *) 0,
    (symrec *) 0,
    OBJ,
    1, 
    .Det.obj = {1, 1} };

Elemento ChaveDaCozinha = {
    "chaveCozinha", 
    "Chave", 
    "Uma chave de bronze comum, parece"
    " que ela abre a porta da cozinha.", 
    (symrec *) 0,
    (symrec *) 0,
    (symrec *) 0,
    OBJ,
    1, 
    .Det.obj = {1, 1} };

Elemento ChaveDoSalao = {
    "chaveSalao", 
    "Chave",
    "Parece que esta chave abre a porta para o salao principal.", 
    (symrec *) 0,
    (symrec *) 0,
    (symrec *) 0,
    OBJ,
    1, 
    .Det.obj = {1, 0} };

Elemento Estilete = {
    "estilete", 
    "Um estilete, e bem afiado", 
    "Um estilete vermelho, levemente enferrujado,"
    " mas ainda sim bem afiado. Poderia cortar minha pele com facilidade", 
    (symrec *) 0,
    (symrec *) 0,
    (symrec *) 0,
    OBJ,
    1, 
    .Det.obj = {1, 1} };

Elemento ChaveBanheiro = {
    "chaveBanheiro", 
    "Chave", 
    "Uma chave, parece servir para Destrancar o banheiro?", 
    (symrec *) 0,
    (symrec *) 0,
    (symrec *) 0,
    OBJ,
    1, 
    .Det.obj = {1, 1} };

Elemento Senha = {
    "senha", 
    "Um papel com uma senha anotada", 
    "Um papel com uma senha anotada, sera que"
    " consigo Destrancar alguma porta com ela?", 
    (symrec *) 0,
    (symrec *) 0,
    (symrec *) 0,
    OBJ,
    1, 
    .Det.obj = {1, 1} };

Elemento Machado = {
    "machado", 
    "Um machado comum", 
    "Um machado, posso tentar destruir coisas com ele!", 
    (symrec *) 0,
    (symrec *) 0,
    (symrec *) 0,
    OBJ,
    1, 
    .Det.obj = {1, 1} };

Elemento ChavePortaPrincipal = {
    "chavePrincipal", 
    "Chave", 
    "Uma chave, parece servir para destrancar a porta principal!", 
    (symrec *) 0,
    (symrec *) 0,
    (symrec *) 0,
    OBJ,
    1,
    .Det.obj = {1, 0} };

Elemento Cama = {
    "cama", 
    "Cama velha. talvez esconda algo.", 
    "Cama de solteiro com madeira envelhecida pelos"
    " cupins. Parece haver algo embaixo dela", 
    (symrec *) 0,
    (symrec *) 0,
    (symrec *) 0,
    OBJ,
    0, 
    .Det.obj = {1, 1} };

Elemento JanelaGradeada = {
    "janelaGradeada", 
    "Uma janela com uma grade", 
    "Uma janela com uma grade de metal, talvez eu"
    " deveria inspecionar o que tem do lado de fora?", 
    (symrec *) 0,
    (symrec *) 0,
    (symrec *) 0,
    OBJ,
    0,
    .Det.obj = {1, 1} };

Elemento Abajur = {
    "abajur", 
    "Abajur sujo. Tem algo brilhante ao lado.", 
    "Um abajur branco e um pouco sujo. Parece bem velho."
    " Espera, tem algo brilhante dentro dele...", 
    (symrec *) 0,
    (symrec *) 0,
    (symrec *) 0,
    OBJ,
    0,
    .Det.obj = {1, 1} };

Elemento ArmarioCozinha = {
    "armarioCozinha", 
    "Um armario qualquer", 
    "Um armario, talvez devesse inspeciona-lo", 
    (symrec *) 0,
    (symrec *) 0,
    (symrec *) 0,
    OBJ,
    0,
    .Det.obj = {1, 1} };

Elemento ParedeRachada = {
    "paredeRachada", 
    "Se eu tivesse algo para quebrar essa parede...", 
    "Essa parede parece frágil e envelhecida, há"
    " uma grande rachadura. Se eu tivesse algo para"
    " quebra-la e ver o que tem atrás....", 
    (symrec *) 0,
    (symrec *) 0,
    (symrec *) 0,
    OBJ,
    0,
    .Det.obj = {1, 1} };

Elemento ArmarioSala = {
    "armarioSala", 
    "Um armario velho", 
    "Um armario velho trancado, se eu tivesse algo"
    " para destrui-lo talvez eu consiguisse ver o que"
    " tem dentro dele", 
    (symrec *) 0,
    (symrec *) 0,
    (symrec *) 0,
    OBJ, 
    0,
    .Det.obj = {1, 1} };

Elemento Corpo = {
    "corpo", 
    "Ha um corpo na banheira, morreu não faz muito tempo.", 
    "Oh meu Deus, corpo!! Tem uma estranha cicatriz na sua barriga"
    " talvez deve ter algo dentro, que nojo!!!", 
    (symrec *) 0,
    (symrec *) 0,
    (symrec *) 0,
    OBJ,
    0, 
    .Det.obj = {1, 1} };

Elemento Fora = {
    "fora",
    "Lado de fora da casa",
    "Parabens voce finalmente voce esta livre desta casa horrenda!"
    " Agora fuja para e peca ajuda para alguem!", 
    (symrec *) 0,
    (symrec *) 0,
    (symrec *) 0,
    LUGAR,
    0, 
    .Det.lug.Saidas = {NULL, NULL, NULL, NULL, NULL, NULL} };

Elemento Sala = {
    "sala",
    "Voce esta na sala",
    "Ha um machado exposto na parede e um"
    " armario fragil de madeira trancado.", 
    (symrec *) 0,
    (symrec *) 0,
    (symrec *) 0,
    LUGAR,
    0, 
    .Det.lug.Saidas = {NULL, NULL, NULL, NULL, NULL, NULL} };

Elemento Cozinha = {
    "cozinha", 
    "Voce esta na cozinha", 
    "Esta toda destruida, de intacto temos apenas um armario.", 
    (symrec *) 0,
    (symrec *) 0,
    (symrec *) 0,
    LUGAR,
    0, 
    .Det.lug.Saidas = {NULL, NULL, NULL, NULL, NULL, NULL} };

Elemento Salao = {
    "salao", 
    "Voce esta no salao", 
    "O salao eh muito vazio, ha apenas um abajur, voce"
    " se pergunta como que alguem conseguiria morar ali.", 
    (symrec *) 0,
    (symrec *) 0,
    (symrec *) 0,
    LUGAR,
    0,
    .Det.lug.Saidas = {NULL, NULL, NULL, NULL, NULL, NULL} };

Elemento Corredor = {
    "corredor",
    "Voce esta no corredor", 
    "No corredor ha alguns pedacos de carpete faltando"
    " e baratas perambulando, voce acha estranho tudo isso.", 
    (symrec *) 0,
    (symrec *) 0,
    (symrec *) 0,
    LUGAR, 
    0,
    .Det.lug.Saidas = {NULL, NULL, NULL, NULL, NULL, NULL} };

Elemento Banheiro = {
    "banheiro", 
    "Voce esta no banheiro", 
    "Voce avista um corpo morto dentro da banheira com"
    " pontos recem costurados na barriga e fica com vontade de vomitar.",
    (symrec *) 0,
    (symrec *) 0,
    (symrec *) 0,
    LUGAR, 
    0,
    .Det.lug.Saidas = {NULL, NULL, NULL, NULL, NULL, NULL} };

Elemento Quarto = {
    "quarto", 
    "Voce esta no quarto", 
    "Um quarto que parece ha tempos desabitado,"
    " ha tracas na parede e muito po espalhado.", 
    (symrec *) 0,
    (symrec *) 0,
    (symrec *) 0,
    LUGAR, 
    1,
    .Det.lug.Saidas = {NULL, NULL, NULL, NULL, NULL, NULL} };

//
// Funções auxiliares
//

/* verifica se um objeto está presente e visível */
/* retorna 1 se no local, 2 se no inventário, 0 se não existir*/
int presente(char *nome) {
  /* inventário? */
    if (BuscaNaLista(inventario, nome))
        return 2;

    if (Buscasymrec(Posic->cont, nome))
        return 1;

    return 0;
}
//verifica se o verbo eh pertinente ao elemento
int temAcao (Elemento * o1, char * nome) {

  if (o1->acoes && Buscasymrec(o1->acoes, nome))
    return 1;

  return 0;
}

/* Implementações dos 2s */

/* Macros para testar propriedades comuns */
#define Ativo(x) (x)->Det.obj.ativo
#define Visivel(x) (x)->Det.obj.visivel

/* Transfere um elemento para o inventário */
void Pegar(Elemento *o1, Elemento *o2) 
{
    if (o1 == NULL) {
      printf("Pegar o que????\n");
      return;
    }

    if (o1->tipo == LUGAR) {
        puts("Não dá para pegar um lugar!");
	    return;
    }

    if (o1->acessivel == 0) {
        printf("Não é possível pegar %s, é muito pesado andar com isso por ai!\n", o1->nome);
        return;
    }

    if (Ativo(o1)) {

	    if (Visivel(o1)) {
	        int r = presente(o1->nome);

	        switch (r) {

	            case 2:
		            printf("Você já está com %s!\n", o1->nome);
		            return;

	            case 1:
		            /* retira do local */
                    Posic->cont = Retirasymrec(Posic->cont, o1->nome);

                    /* insere no inventário */
                    inventario = InsereLista(inventario, o1->nome, OBJ, o1);
                    printf("Peguei %s\n", o1->nome);
                    return;

	            default:
	    	        printf("Não há %s aqui!\n", o1->nome);
		            return;
	        }
	    }

	    printf("Não consigo ver nenhum %s!\n", o1->nome);
    }
    else
	    printf("Não existe %s!!!!\n", o1->nome);
}

/* Transfere do inventário para o local atual */
void Largar(Elemento *o1, Elemento *o2) {
    Lista c;

  if (o1->tipo == LUGAR) {
	puts("Largue a mão de ser besta!");
	return;
  }

  if (!inventario)
    printf("Voce nao tem nada para largar...\n");

  if (BuscaNaLista(inventario, o1->nome)) {


	/* retira do inventario */
	c = RetiraDaLista(inventario, o1->nome);

	/* insere no local */
	Posic->cont = Inseresymrec(Posic->cont, c->nome, OBJ, c->val);
	return;
  }
  else {
	/* Em inglês for fun */
	puts("You don't have it");
  }
}
//transfere um elemento contido em algum outro para o local atual do jogador
symrec * ColocaNoLocal (Elemento *o1) {
    Elemento *o;
    Lista p;

    if (o1->cont != NULL && o1 != Posic) {

        for (int i = 0; i < 26; i++) {
            p = o1->cont->indices[i];

            while (p != NULL) {
                o = p->val;

                if (o->tipo == OBJ && Ativo(o) && Visivel(o)) {
                    o1->cont = Retirasymrec(o1->cont, o->nome);
                    printf("Voce pegou %s e deixou no chao do local em que esta"
                   " para poder lembrar de pegar depois, que esperto!!!\n", o->nome);
                    Posic->cont = Inseresymrec(Posic->cont, o->nome, o->tipo, o);
                }

                p = p->prox;
            }

        }

    }

    return o1->cont;
}

/* Descreve um Elemento em detalhes */
void Examinar(Elemento *o1, Elemento *o2) {
    symrec *ptr = NULL;

    /* o default é descrever o local atual */
    if (o1 == NULL || o1 == Posic) {
        o1 = Posic;
    	puts(Posic->longa);
    } 

    else if (o1->tipo == OBJ && Ativo(o1) && Visivel(o1)) {
        puts(o1->longa);
    }

    else if (o1->tipo == OBJ && (!Ativo(o1) || !Visivel(o1))) {
        puts("Oi?");
        return;
    }

    else {
        puts("Não tenho como responder neste momento");
        return;
    }

    if (o1)
        ptr = o1->cont;

    if (ptr) {
        puts("Aqui tem:");
        printsym(ptr);
        o1->cont = ColocaNoLocal(o1);
    }

}

/* descrição curta de um elemento */

//Declaracao das acoes
void Olhar(Elemento *o1, Elemento *o2) {

  if (o1 != NULL && Visivel(o1))
    puts(o1->curta);

  else
    puts(Posic->curta);

}

void Gritar(Elemento *o1, Elemento *o2){
  puts("YEEAAAAAOOOOOWWWGRRUWL");
}

void Estripar (Elemento *o1, Elemento *o2) {

  if (o1->tipo == LUGAR) {
    printf("Nao tem como vc estripar um lugar, seu louco!\n");
    return;
  }

  if (o1 == &Corpo && Ativo(o1) && Visivel(o1)) {

    if (presente("estilete") == 2) {
      Corpo.cont = Retirasymrec(Corpo.cont, "chaveSalao");
      Posic->cont = Retirasymrec(Posic->cont, "corpo");
      Posic->cont = Inseresymrec(Posic->cont, "chaveSalao", OBJ, &ChaveDoSalao);
      inventario = RetiraDaLista(inventario, "estilete");
      ChaveDoSalao.Det.obj.visivel = 1;
      printf("Voce estripou o corpo e o seguinte item caiu no chao: chaveSalao\n");
      printf("Seu estilete infelizmente quebrou\n");
    }

    else
      printf("Voce precisa de algo para corta-lo\n");
  }

  else {
    printf("Nao eh possivel fazer isso!\n");
  }

}

void Destruir (Elemento *o1, Elemento *o2) {

  if (o1->tipo != OBJ) {
    printf("Nao eh possivel fazer isso\n");
    return;
  }

  if (Ativo(o1) && Visivel(o1)) {

    if (o1 == &ParedeRachada) {

      if (presente("marreta") == 2) {
        ParedeRachada.cont = Retirasymrec(ParedeRachada.cont, "chavePortaInicial");
        Posic->cont = Retirasymrec(Posic->cont, "paredeRachada");
        Posic->cont = Inseresymrec(Posic->cont, "chavePortaInicial", OBJ, &ChaveDaPortaInicial);
        inventario = RetiraDaLista(inventario, "marreta");
        ChaveDaPortaInicial.Det.obj.visivel = 1;
        printf("Voce destruiu a parede rachada.\n");
        printf("O seguinte item caiu de la: chavePortaInicial\n");
        printf("E sua marreta infelizmente quebrou...\n");
      }

      else
        printf("Voce precisa de algo para fazer isso!\n");

    } 

    else if (o1 == &ArmarioSala) {

      if (presente("machado") == 2) {
        ArmarioSala.cont = Retirasymrec(ArmarioSala.cont, "chavePrincipal");
        Posic->cont = Retirasymrec(Posic->cont, "armarioSala");
        Posic->cont = Inseresymrec(Posic->cont, "chavePrincipal", OBJ, &ChavePortaPrincipal);
        inventario = RetiraDaLista(inventario, "machado");
        ChavePortaPrincipal.Det.obj.visivel = 1;
        printf("Voce destruiu o armario da sala.\n");
        printf("O seguinte item caiu de la: chavePrincipal\n");
        printf("E seu machado infelizmente quebrou...\n");
      }

      else
        printf("Voce precisa de algo para fazer isso!\n");
    }
  }

  else
    printf("Voce nao pode fazer isso!\n");
}

void AbreAsSalas (Elemento * porta) {
    int i;
    Lista p;
    Elemento * o;

    for (i = 0; i < 26; i++) {
        p = porta->cont->indices[i];

        while (p != NULL) {
            o = p->val;
            o->acessivel = 1;
            p = p->prox;
        }

    }

}

void Destrancar (Elemento * o1, Elemento * o2) {

    if (o1 == NULL)
        printf("Destrancar o que????\n");

  if (o1->tipo != OBJ) {
    printf("Voce nao pode destrancar isso!\n");
    return;
  }

  if (temAcao(o1, "destranque") && o1->acessivel == 1) {
    printf("Esta porta ja esta destrancada.\n");
    return;
  }

  else if (o1 == &PortaCorredor && presente("chavePortaInicial") == 2) {
    printf("Voce destrancou a porta para o corredor!\n");
    o1->acessivel = 1;
    printf("Sua chave ja nao serve pra mais nada...\n");
    inventario = RetiraDaLista(inventario, "chavePortaInicial");
    AbreAsSalas(o1);
  }

  else if (o1 == &PortaBanheiro && presente("chaveBanheiro") == 2) {
    printf("Voce destrancou a porta para o banheiro!\n");
    o1->acessivel = 1;
    printf("Sua chave ja nao serve pra mais nada...\n");
    inventario = RetiraDaLista(inventario, "chaveBanheiro");
    AbreAsSalas(o1);
  }

  else if (o1 == &PortaSalao && presente("chaveSalao") == 2) {
    printf("Voce destrancou a porta para o salao!\n");
    o1->acessivel = 1;
    printf("Sua chave ja nao serve pra mais nada...\n");
    inventario = RetiraDaLista(inventario, "chaveSalao");
    AbreAsSalas(o1);
  }

  else if (o1 == &PortaDaCozinha && presente("chaveCozinha") == 2) {
    printf("Voce destrancou a porta para a cozinha!\n");
    o1->acessivel = 1;
    printf("Sua chave ja nao serve pra mais nada...\n");
    inventario = RetiraDaLista(inventario, "chaveCozinha");
    AbreAsSalas(o1);
  }

  else if (o1 == &PortaDaSalaDeEstar && presente("senha") == 2) {
    printf("Voce destrancou a porta para a sala de estar!\n");
    o1->acessivel = 1;
    printf("Sua senha ja nao serve pra mais nada...\n");
    inventario = RetiraDaLista(inventario, "senha");
    AbreAsSalas(o1);
  }

  else if (o1 == &PortaPrincipal && presente("chavePrincipal") == 2) {
    printf("Voce destrancou a porta para fora da casa!\n");
    o1->acessivel = 1;
    printf("Sua chave ja nao serve pra mais nada...\n");
    inventario = RetiraDaLista(inventario, "chavePrincipal");
    AbreAsSalas(o1);
  }

  else
    printf("Nao eh possivel abrir %s\n", o1->nome);
}

int Ir(Elemento * local) {
  
  if (local->tipo != LUGAR) {
    printf("Nao tem como ir para alguma coisa que nao seja um local!\n");
    return 0;
  }

  if (local->acessivel == 1)
    return 1;

  printf("Este local ainda nao esta acessivel!\n");
  return 0;
}


/* Para inicializar as funções */
struct initfunc {
  char *fname;
  Fptr fnct;
};

/* Lista de verbos */
struct initfunc lfunc[] = {
  {"pegue", Pegar},
  {"cate", Pegar},
  {"largue", Largar },
  {"solte", Largar },
  {"jogue", Largar },
  {"examine", Examinar},
  {"inspecione", Examinar},
  {"olhe", Olhar },
  {"veja", Olhar },
  {"grite", Gritar },
  {"berre", Gritar },
  {"estripe", Estripar},
  {"rasge", Estripar},
  {"corte", Estripar},
  {"destrua", Destruir},
  {"quebre", Destruir},
  {"destranque", Destrancar},
  {"abra", Destrancar},
  {0, 0}
};

/* Para objetos */
struct initobj {
  char *name;
  Elemento *obj;
};

/* Lista de objetos */
struct initobj lobjs[] = {
  {"portaCorredor", &PortaCorredor},
  {"portaBanheiro", &PortaBanheiro},
  {"portaSalao", &PortaSalao},
  {"portaCozinha", &PortaDaCozinha},
  {"portaSala", &PortaDaSalaDeEstar},
  {"portaPrincipal", &PortaPrincipal},
  {"chavePortaInicial", &ChaveDaPortaInicial},
  {"chaveCozinha", &ChaveDaCozinha},
  {"marreta", &Marreta},
  {"chaveSalao", &ChaveDoSalao},
  {"estilete", &Estilete},
  {"chaveBanheiro", &ChaveBanheiro},
  {"chavePrincipal", &ChavePortaPrincipal},
  {"senha", &Senha},
  {"machado", &Machado},
  {"chavePorta",},
  {"cama", &Cama},
  {"janelaGradeada", &JanelaGradeada},
  {"abajur", &Abajur},
  {"armarioCozinha", &ArmarioCozinha},
  {"paredeRachada", &ParedeRachada},
  {"armarioSala", &ArmarioSala},
  {"corpo", &Corpo},
  { 0, 0}
};

/* Para lugares */
struct initlug {
  char *name;
  Elemento *lug;
};

/* Lista de lugares */
struct initlug llugs[] = {
  {"quarto", &Quarto},
  {"banheiro", &Banheiro},
  {"corredor", &Corredor},
  {"salao", &Salao},
  {"cozinha", &Cozinha},
  {"sala", &Sala},
  {"fora", &Fora},
  {0, 0}
};

/* Inicializa a tabela de símbolos passada como argumento */
Lista init_table (Lista sym_table)
{
  // printf("Cria tabela universal\n");
  int i;
  Lista ptr = sym_table;		/* cabeça da lista */
  /* Lista de verbos */
  for (i = 0; lfunc[i].fname != 0; i++) {
	/* insere */
    ptr = InsereLista(ptr, lfunc[i].fname, VERBO, lfunc[i].fnct);
  }
  /* Lista de objetos */
  for (i = 0; lobjs[i].name != 0; i++) {
	Elemento * oo = lobjs[i].obj;
	/* insere */
    ptr = InsereLista(ptr, lobjs[i].name, OBJ, oo);
  }
  /* Lista de lugares */
  for (i = 0; llugs[i].name != 0; i++) 
	/* insere */
    ptr = InsereLista(ptr, llugs[i].name, LUGAR, llugs[i].lug);

  /* Coloca os objetos nos lugares */
  Quarto.cont = CriaTabela();
  Quarto.cont = Inseresymrec(Quarto.cont, "cama", OBJ, &Cama);
  Quarto.cont = Inseresymrec(Quarto.cont, "paredeRachada", OBJ, &ParedeRachada);
  Quarto.cont = Inseresymrec(Quarto.cont, "portaCorredor", OBJ, &PortaCorredor);

  Cama.cont = CriaTabela();
  Cama.cont = Inseresymrec(Cama.cont, "marreta", OBJ, &Marreta);

  ParedeRachada.cont = CriaTabela();
  ParedeRachada.cont = Inseresymrec(ParedeRachada.cont, "chavePortaInicial", OBJ, &ChaveDaPortaInicial);

  Corredor.cont = CriaTabela();
  Corredor.cont = Inseresymrec(Corredor.cont, "janelaGradeada", OBJ, &JanelaGradeada);
  Corredor.cont = Inseresymrec(Corredor.cont, "portaBanheiro", OBJ, &PortaBanheiro);
  Corredor.cont = Inseresymrec(Corredor.cont, "portaSalao", OBJ, &PortaSalao);
  
  Sala.cont = CriaTabela();
  Sala.cont = Inseresymrec(Sala.cont, "armarioSala", OBJ, &ArmarioSala);
  Sala.cont = Inseresymrec(Sala.cont, "machado", OBJ, &Machado);

  JanelaGradeada.cont = CriaTabela();
  JanelaGradeada.cont = Inseresymrec(JanelaGradeada.cont, "chaveBanheiro", OBJ, &ChaveBanheiro);
  
  Banheiro.cont = CriaTabela();
  Banheiro.cont = Inseresymrec(Banheiro.cont, "corpo", OBJ, &Corpo);
  Banheiro.cont = Inseresymrec(Banheiro.cont, "estilete", OBJ, &Estilete);

  Corpo.cont = CriaTabela();
  Corpo.cont = Inseresymrec(Corpo.cont, "chaveSalao", OBJ, &ChaveDoSalao);

  Abajur.cont = CriaTabela();
  Abajur.cont = Inseresymrec(Abajur.cont, "chaveCozinha", OBJ, &ChaveDaCozinha);

  Salao.cont = CriaTabela();
  Salao.cont = Inseresymrec(Salao.cont, "abajur", OBJ, &Abajur);
  Salao.cont = Inseresymrec(Salao.cont, "portaCozinha", OBJ, &PortaDaCozinha);
  Salao.cont = Inseresymrec(Salao.cont, "portaSala", OBJ, &PortaDaSalaDeEstar);
  Salao.cont = Inseresymrec(Salao.cont, "portaPrincipal", OBJ, &PortaPrincipal);

  Cozinha.cont = CriaTabela();
  Cozinha.cont = Inseresymrec(Cozinha.cont, "armarioCozinha", OBJ, &ArmarioCozinha);

  ArmarioCozinha.cont = CriaTabela();
  ArmarioCozinha.cont = Inseresymrec(ArmarioCozinha.cont, "senha", OBJ, &Senha);
  
  ArmarioSala.cont = CriaTabela();
  ArmarioSala.cont = Inseresymrec(ArmarioSala.cont, "chavePrincipal", OBJ, &ChavePortaPrincipal);

  PortaCorredor.cont = CriaTabela();
  PortaCorredor.cont = Inseresymrec(PortaCorredor.cont, "corredor", LUGAR, &Corredor);

  PortaBanheiro.cont = CriaTabela();
  PortaBanheiro.cont = Inseresymrec(PortaBanheiro.cont, "banheiro", LUGAR, &Banheiro);

  PortaSalao.cont = CriaTabela();
  PortaSalao.cont = Inseresymrec(PortaSalao.cont, "salao", LUGAR, &Salao);

  PortaDaCozinha.cont = CriaTabela();
  PortaDaCozinha.cont = Inseresymrec(PortaDaCozinha.cont, "cozinha", LUGAR, &Cozinha);

  PortaDaSalaDeEstar.cont = CriaTabela();
  PortaDaSalaDeEstar.cont = Inseresymrec(PortaDaSalaDeEstar.cont, "sala", LUGAR, &Sala);

  PortaPrincipal.cont = CriaTabela();
  PortaPrincipal.cont = Inseresymrec(PortaPrincipal.cont, "fora", LUGAR, &Fora);

  /* Coloca as saídas das salas */
  Quarto.Det.lug.Saidas[2] = &Corredor;

  Corredor.Det.lug.Saidas[0] = &Banheiro;
  Corredor.Det.lug.Saidas[3] = &Quarto;
  Corredor.Det.lug.Saidas[5] = &Salao;

  Banheiro.Det.lug.Saidas[1] = &Corredor;

  Salao.Det.lug.Saidas[0] = &Fora;
  Salao.Det.lug.Saidas[2] = &Cozinha;
  Salao.Det.lug.Saidas[3] = &Sala;
  Salao.Det.lug.Saidas[4] = &Corredor;

  Cozinha.Det.lug.Saidas[3] = &Salao;

  Sala.Det.lug.Saidas[2] = &Salao;  

  /* Ajustes finais */
  Corpo.acoes = CriaTabela();
  Corpo.acoes = Inseresymrec(Corpo.acoes, "estripe", VERBO, Estripar);
  Corpo.acoes = Inseresymrec(Corpo.acoes, "corte", VERBO, Estripar);

  ArmarioSala.acoes = CriaTabela();
  ArmarioSala.acoes = Inseresymrec(ArmarioSala.acoes, "destrua", VERBO, Destruir);
  ArmarioSala.acoes = Inseresymrec(ArmarioSala.acoes, "quebre", VERBO, Destruir);

  ParedeRachada.acoes = CriaTabela();
  ParedeRachada.acoes = Inseresymrec(ParedeRachada.acoes, "destrua", VERBO, Destruir);
  ParedeRachada.acoes = Inseresymrec(ParedeRachada.acoes, "quebre", VERBO, Destruir);

  PortaCorredor.acoes = CriaTabela();
  PortaCorredor.acoes = Inseresymrec(PortaCorredor.acoes, "destranque", VERBO, Destrancar);
  PortaCorredor.acoes = Inseresymrec(PortaCorredor.acoes, "abra", VERBO, Destrancar);

  PortaBanheiro.acoes = CriaTabela();
  PortaBanheiro.acoes = Inseresymrec(PortaBanheiro.acoes, "destranque", VERBO, Destrancar);
  PortaBanheiro.acoes = Inseresymrec(PortaBanheiro.acoes, "abra", VERBO, Destrancar);

  PortaSalao.acoes = CriaTabela();
  PortaSalao.acoes = Inseresymrec(PortaSalao.acoes, "destranque", VERBO, Destrancar);
  PortaSalao.acoes = Inseresymrec(PortaSalao.acoes, "abra", VERBO, Destrancar);

  PortaDaCozinha.acoes = CriaTabela();
  PortaDaCozinha.acoes = Inseresymrec(PortaDaCozinha.acoes, "destranque", VERBO, Destrancar);
  PortaDaCozinha.acoes = Inseresymrec(PortaDaCozinha.acoes, "abra", VERBO, Destrancar);

  PortaDaSalaDeEstar.acoes = CriaTabela();
  PortaDaSalaDeEstar.acoes = Inseresymrec(PortaDaSalaDeEstar.acoes, "destranque", VERBO, Destrancar);
  PortaDaSalaDeEstar.acoes = Inseresymrec(PortaDaSalaDeEstar.acoes, "abra", VERBO, Destrancar);

  PortaPrincipal.acoes = CriaTabela();
  PortaPrincipal.acoes = Inseresymrec(PortaPrincipal.acoes, "destranque", VERBO, Destrancar);
  PortaPrincipal.acoes = Inseresymrec(PortaPrincipal.acoes, "abra", VERBO, Destrancar);

  Posic = &Quarto;

  return ptr;
}

//Libera a memoria
void DestroiTudo () {
    DestroiLista(sym_table);
    DestroiLista(inventario);
    Destroisymrec(Quarto.cont);
    Destroisymrec(Cama.cont);
    Destroisymrec(ParedeRachada.cont);
    Destroisymrec(Corredor.cont);
    Destroisymrec(Sala.cont);
    Destroisymrec(JanelaGradeada.cont);
    Destroisymrec(Banheiro.cont);
    Destroisymrec(Corpo.cont);
    Destroisymrec(Abajur.cont);
    Destroisymrec(Salao.cont);
    Destroisymrec(Cozinha.cont);
    Destroisymrec(ArmarioCozinha.cont);
    Destroisymrec(ArmarioSala.cont);
    Destroisymrec(PortaCorredor.cont);
    Destroisymrec(PortaBanheiro.cont);
    Destroisymrec(PortaSalao.cont);
    Destroisymrec(PortaDaCozinha.cont);
    Destroisymrec(PortaDaSalaDeEstar.cont);
    Destroisymrec(PortaPrincipal.cont);
    Destroisymrec(Corpo.acoes);
    Destroisymrec(ArmarioSala.acoes);
    Destroisymrec(ParedeRachada.acoes);
    Destroisymrec(PortaCorredor.acoes);
    Destroisymrec(PortaSalao.acoes);
    Destroisymrec(PortaDaCozinha.acoes);
    Destroisymrec(PortaDaSalaDeEstar.acoes);
    Destroisymrec(PortaPrincipal.acoes);
}