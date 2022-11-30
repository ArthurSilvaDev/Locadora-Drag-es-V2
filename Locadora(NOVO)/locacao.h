struct st_locacao{
	int cod;
	char pago[10];
	char inicioLoc[20];
	char fimLoc [20];
	int codGuerreiro;
	int codDragao;
	
};
typedef struct st_locacao Locacao;
int inicializarLocacao();
int encerraLocacao();
int salvarLocacao(Locacao c);
int QuantidadeLocacao();
Locacao obterLocacaoPeloIndice(int indice);
Locacao obterLocacaoPeloCodigo(int codigo);
int ApagarLocacaoPeloCodigo(int codigo);
