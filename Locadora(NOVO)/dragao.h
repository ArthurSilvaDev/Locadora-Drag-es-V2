struct st_dragao{
	int cod;
	char nome[20];
	int idade;
	float valorDiario;
	int unidadesEmEstoque;
	int idElemento;
	
};
typedef struct st_dragao Dragao;

int inicializarDragao();
int encerraDragao();
int salvarDragao(Dragao c, int encontrado);
int QuantidadeDragoes();
Dragao obterDragaoPeloIndice(int indice);
Dragao obterDragaoPeloCodigo(int codigo);
int ApagarDragaoPeloCodigo(int codigo);
