struct st_elemento{
	int cod;
	char nome [20];
	char vulnerabilidade [20];
	
};
typedef struct st_elemento Elemento;


int inicializarElementos();
int encerraElementos();
int salvarElemento(Elemento c);
int QuantidadeElementos();
Elemento obterElementoPeloIndice(int indice);
Elemento obterElementoPeloCodigo(int codigo);
int ApagarElementoPeloCodigo(int codigo);
void listarElementos();


