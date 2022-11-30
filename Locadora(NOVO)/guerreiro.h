struct st_guerreiro{
	int cod;
	char nome [20];
	char reino [20];
	char titulo [20];
	
};
typedef struct st_guerreiro Guerreiro;

int inicializarGuerreiros();
int encerraGuerreiros();
int salvarGuerreiro(Guerreiro c);
int QuantidadeGuerreiros();
Guerreiro obterGuerreiroPeloIndice(int indice);
Guerreiro obterGuerreiroPeloCodigo(int codigo);
int ApagarGuerreiroPeloCodigo(int codigo);
