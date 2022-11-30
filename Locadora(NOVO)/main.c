#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "dragao.h"
#include "elemento.h"
#include "guerreiro.h"
#include "locacao.h"

void mostraMenu(){
	 printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		printf(":::::::::::::  LOCADORA  KALEESI  ::::::::::::::::::\n");
		printf(":::::::::::::::::MENU PRINCIPAL:::::::::::::::::::::\n\n");
		printf("0  - SAIR \n");
		printf("1  - GUERREIROS\n");
		printf("2  - DRAGÕES\n");
		printf("3  - ELEMENTOS DE DRAGÕES\n");
		printf("4  - LOCAÇÕES\n");
		printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		printf("\n Digite a opção desejada: ");
	
}

void subMenu(){
		printf(":::::::::::::  LOCADORA  KALEESI  ::::::::::::::::::\n");
		printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
		printf("0  - SAIR \n");
		printf("1  - CADASTRAR\n");
		printf("2  - LISTAR\n");
		printf("3  - PESQUISAR\n");
		printf("4  - EXCLUIR\n");
		printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		printf("\n Digite a opção desejada: ");
	
	
}
// FUNCÕES PARA GUERREIRO --- INICIO
void cadastrarGuerreiro(){
	
	Guerreiro g;
	printf("\n CADASTRAR GUERREIRO \n\n");
	
	printf("Digite o NOME do guerreiro: ");
	fflush(stdin);
	scanf("%[^\n]s", g.nome);
	
	printf("Digite o REINO do guerreiro: ");
	fflush(stdin);
	scanf("%[^\n]s", g.reino);
	
	printf("Digite o TITULO do guerreiro: ");
	fflush(stdin);
	scanf("%[^\n]s", g.titulo);
	
	if(salvarGuerreiro(g) == 1){
		printf("\nO Gurreiro \"%s\" foi cadastrado com sucesso!\n", g.nome);
		system("pause");
	}
	else{
		printf("O cadastro falhou!");
		system("pause");
	}
	system ("cls");
}


void listarGuerreiros(){
	 printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	 printf(":::::::::::  GUERREIROS CADASTRADOS  :::::::::::::::\n");
	 printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	 
	 int i;
	 for (i =0; i<QuantidadeGuerreiros(); i++){
	 	Guerreiro g = obterGuerreiroPeloIndice(i);
	 	if (g.cod > 0){
	 		printf("\nCódigo:%i | Nome: %s | Reino: %s | Titulo: %s |\n",
			 g.cod, 
			 g.nome,
			 g.reino,
			 g.titulo);
		 }
	 }
	 printf("\n\n::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
}

void pesquisarGuerreiro(){
	int resposta;
	printf("\n PESQUISAR GUERREIRO \n\n");
	printf("Digite o código do guerreiro que procura: ");
	scanf("%d", &resposta);
	
	Guerreiro g = obterGuerreiroPeloCodigo(resposta);
	
	if (g.cod > 0){
		printf("Código:%i Nome: %s  Reino: %s  Titulo: %s \n",
			 g.cod, 
			 g.nome,
			 g.reino,
			 g.titulo);
	}
	 if (g.cod < 0){
	 	printf("Código não encontrado!\n");
	 }
	system("pause");
	system("cls");
  }

void apagarGuerreiro(){
	listarGuerreiros();
	int codigo;
	printf("Digite o codigo do Guerreiro a ser apagado: ");
	scanf ("%d", &codigo);
	
	int ok = 0;
	int i;
	for (i = 0; i <= QuantidadeLocacao(); i++){
		Locacao y = obterLocacaoPeloCodigo(i);
		if (codigo == y.codGuerreiro){
			printf("Este guerreiro possui locação ativa!\n");
			ok++;
			break;
		}
		
	}
	if(ok == 0){
		if (ApagarGuerreiroPeloCodigo(codigo)==1 ){
		printf("\nGuerreiro apagado com sucesso!\n");
		}
	}	
	else {
		printf("\nFalha ao apagar o Guerreiro!\n");
	}
	system("pause");
	system("cls");
	
}

// FUNCÕES PARA GUERREIRO --- FIM

// FUNCÕES PARA DRAGAO --- INICIO

void cadastrarDragao(){
	Dragao g;
	
	printf("\n CADASTRAR DRAGAO \n\n");
	
	printf("Digite o NOME do dragão: ");
	fflush(stdin);
	scanf("%[^\n]s", g.nome);
	
	printf("Digite a IDADE do dragão: ");
	scanf("%d", &g.idade);
	
	printf("Digite o VALOR DA DIÁRIA do dragão: R$ ");
	scanf("%f", &g.valorDiario);
	
	printf("Digite as UNIDADES EM ESTOQUE deste dragão: ");
	scanf("%d", &g.unidadesEmEstoque);
	
	
	// CADASTRAR ELEMENTO
	
	listarElementos();
	
	int resposta;
	printf("Digite o código do elemento do dragão: ");
	scanf("%d", &resposta);
	
	Elemento e = obterElementoPeloCodigo(resposta);
	int encontrado = 0;
	
	if (e.cod != 0){
		
		g.idElemento = resposta;
		 encontrado ++;
	}
	 if (e.cod == 0){
	 	printf("Código não encontrado!\n");
	 }
	
	if(salvarDragao(g, encontrado)==1){
		printf("\nO Dragão \"%s\" foi cadastrado com sucesso!\n", g.nome);
		system("pause");
	}
	else{
		printf("O cadastro falhou!");
		system("pause");
	}
	system ("cls");
	
	
}

void listarDragoes(){
	
 	 printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	 printf("::::::::::::  DRAGÕES CADASTRADOS  :::::::::::::::::\n");
	 printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	
		 int i;
	 for (i =0; i<QuantidadeDragoes(); i++){
	 	Dragao g = obterDragaoPeloIndice(i);
	 	Elemento e = obterElementoPeloCodigo(g.idElemento);
	 	if (g.cod > 0){
	 		printf("\nCódigo:%i | Nome: %s | Idade: %i | Diária: R$ %.2f | Estoque: %i | Elemento: %s | Vulnerabilidade: %s \n",
			 g.cod, 
			 g.nome,
			 g.idade,
			 g.valorDiario,
			 g.unidadesEmEstoque,
			 e.nome,
			 e.vulnerabilidade);
		 }
	 }
	 printf("\n\n::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	
}

void pesquisarDragoes(){
	 
	int resposta;
	printf("\n PESQUISAR DRAGÃO \n\n");
	printf("Digite o código do Dragão que procura: ");
	scanf("%d", &resposta);
	
	
	Dragao d = obterDragaoPeloCodigo(resposta);
	
	if (d.cod > 0){
	
	  	printf("\nCódigo:%i Nome: %s  Idade: %i  Diária: R$ %.2f  Estoque: %i \n",
			 d.cod, 
			 d.nome,
			 d.idade,
			 d.valorDiario,
			 d.unidadesEmEstoque);
	}
	 if (d.cod < 0){
	 	printf("Código não encontrado!\n");
	 }
	system("pause");
	system("cls");
	 
	
}

void apagarDragao(){
	listarDragoes();
	int codigo;
	printf("Digite o codigo do Dragão a ser apagado: ");
	scanf ("%d", &codigo);
	
	int ok = 0;
	int i;
	for (i = 0; i <= QuantidadeLocacao(); i++){
		Locacao y = obterLocacaoPeloCodigo(i);
		if (codigo == y.codDragao){
			printf("Este Dragão possui locação ativa!\n");
			ok++;
			break;
		}
	}
	if(ok == 0){
		if(ApagarDragaoPeloCodigo(codigo)==1){
			printf("\nDragão apagado com sucesso!\n");
		}
	}
	else {
		printf("\nFalha ao apagar o Dragão!\n");
	}
	system("pause");
	system("cls");
	
}

// FUNCÕES PARA DRAGAO --- FIM
// FUNÇÕES PARA ELEMENTO --- INICIO

void cadastrarElemento(){
		
	Elemento g;
	printf("\n CADASTRAR ELEMENTO \n\n");
	
	printf("Digite o NOME do elemento: ");
	fflush(stdin);
	scanf("%[^\n]s", g.nome);
	
	printf("Digite o VULNERABILIDADE do elemento: ");
	fflush(stdin);
	scanf("%[^\n]s", g.vulnerabilidade);
	
	
	if(salvarElemento(g) == 1){
		printf("\nO Elemento \"%s\" foi cadastrado com sucesso!\n", g.nome);
		system("pause");
	}
	else{
		printf("O cadastro falhou!");
		system("pause");
	}
	system ("cls");
}

void listarElementos(){
	
 	 printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	 printf("::::::::::::  ELEMENTOS CADASTRADOS  :::::::::::::::\n");
	 printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	 
	  int i;
	 for (i =0; i<QuantidadeElementos(); i++){
	 	Elemento g = obterElementoPeloIndice(i);
	 	if (g.cod > 0){
	 		printf("\nCódigo:%i | Nome: %s | Vulnerabilidade: %s \n",
			 g.cod, 
			 g.nome,
			 g.vulnerabilidade);
		 }
	 }
	 printf("\n\n::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	 
}

void pesquisarElementos(){
		 
	int resposta;
	printf("\n PESQUISAR ELEMENTO \n\n");
	printf("Digite o código do Elemento que procura: ");
	scanf("%d", &resposta);
	
	
	Elemento e = obterElementoPeloCodigo(resposta);
	
	if (e.cod > 0){
	
  		printf("\nCódigo:%i Nome: %s  Vulnerabilidade: %s \n",
			 e.cod, 
			 e.nome,
			 e.vulnerabilidade);
	}
	 if (e.cod < 0){
	 	printf("Código não encontrado!\n");
	 }
	system("pause");
	system("cls");	
}

void apagarElemento(){

	listarElementos();
	int codigo;
	printf("Digite o codigo do Elemento a ser apagado: ");
	scanf ("%d", &codigo);
	
	int ok = 0;
	int i;
	for (i = 0; i <= QuantidadeDragoes(); i++){
		Dragao y = obterDragaoPeloCodigo(i);
		if (codigo == y.idElemento){
			printf("Existem dragões deste elemento com cadastro ativo!\nFavor apagar os dragões primeiro!\n");
			ok++;
			break;
		}
	}
	
	if(ok == 0){
		if(ApagarElementoPeloCodigo(codigo)==1){
			printf("\nElemento apagado com sucesso!\n");
		}
	}
	else {
		printf("\nFalha ao apagar o Elemento!\n");
	}

	system("pause");
	system("cls");
	
}

//FUNCÕES PARA ELEMENTO -- FIM

//FUNÇÕES PARA LOCAÇÃO -- INICIO
void realizarLocacao(){
	
	printf("\n CADASTRAR LOCAÇÃO \n");
	
	listarGuerreiros();
	
	Locacao l;
	
	printf("Digite o CÓDIGO DO GUERREIRO: ");
	scanf("%d", &l.codGuerreiro);
	
	system("cls");
	
	printf("\n CADASTRAR LOCAÇÃO \n");
	
	listarDragoes();
	
	printf("Digite o CODIGO DO DRAGAO: ");
	scanf("%d", &l.codDragao);
	
	system("cls");
	
	printf("\n CADASTRAR LOCAÇÃO \n");
	
	printf("Digite a DATA DE RETIRADA do dragão: ");
	fflush(stdin);
	scanf("%[^\n]s", l.inicioLoc);
	
	printf("Digite a DATA DE ENTREGA do dragão: ");
	fflush(stdin);
	scanf("%[^\n]s", l.fimLoc);
	
	printf("Pagamento realizado? (S/N): ");
	fflush(stdin);
	scanf("%[^\n]s", l.pago);
	
	
	if(salvarLocacao(l) == 1){
		printf("\nA Locação foi salva com sucesso ");
		system("pause");
	}
	else{
		printf("O cadastro falhou!");
		system("pause");
	}
	system ("cls");

}

void listarLocacoes(){
	 
	 
	 printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	 printf("::::::::::::  LOCAÇÕES CADASTRADSS  :::::::::::::::\n");
	 printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	 
	int i;
	for (i =0; i<QuantidadeLocacao(); i++){
	 	Locacao l = obterLocacaoPeloIndice(i);
	 	Guerreiro g = obterGuerreiroPeloCodigo(l.codGuerreiro);
	 	Dragao d = obterDragaoPeloCodigo(l.codDragao);
	 	if (l.cod > 0){
	 		printf("\nCódigo:%i | Guerreiro: %s | Dragão: %s | Inicio: %s | Fim: %s | Pago: %s \n",
			 l.cod, 
			 g.nome,
			 d.nome,
			 l.inicioLoc,
			 l.fimLoc,
			 l.pago);
		 }
	 }
	 printf("\n\n::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	 
}

void pesquisarLocacao(){
			 
	int resposta;
	printf("\n PESQUISAR Locação \n\n");
	printf("Digite o código da Locação que procura: ");
	scanf("%d", &resposta);
	
	
	Locacao e = obterLocacaoPeloCodigo(resposta);
	Guerreiro g = obterGuerreiroPeloCodigo(e.codGuerreiro);
	Dragao d = obterDragaoPeloCodigo(e.codDragao);
	//
	if (e.cod > 0){
			printf("\nCódigo:%i | Guerreiro: %s | Dragão: %s | Inicio: %s | Fim: %s | Pago: %s \n",
			 e.cod, 
			 g.nome,
			 d.nome,
			 e.inicioLoc,
			 e.fimLoc,
			 e.pago);
  		
	}
	 if (e.cod < 0){
	 	printf("Código não encontrado!\n");
	 }
	system("pause");
	system("cls");	
	
}

void apagarLocacao(){
	
	listarLocacoes();
	int codigo;
	printf("Digite o codigo da Locação a ser apagado: ");
	scanf ("%d", &codigo);
	
	if(ApagarLocacaoPeloCodigo(codigo)==1){
		printf("\nLocação apagada com sucesso!\n");
	}
	else {
		printf("\nFalha ao apagar a Locação!\n");
	}
	system("pause");
	system("cls");
	
	
}

// FUNÇÕES PARA LOCAÇÃO -- FIM

int main(int argc, char *argv[]) {
	
	// COLOCAR EM PORTUGUÊS
	setlocale(LC_ALL, "Portuguese");
	
	inicializarGuerreiros();
	inicializarDragao();
	inicializarElementos();
	inicializarLocacao();
	
	int menu = 0;
	system("cls");
	do{
		mostraMenu();
		scanf("%i", &menu);
		system ("cls");
		switch(menu){
			
			case 1:; //ESCOLHA GUERREIRO
				int menu1 = 0;
				system("cls");
				do{ // SUBMENU GUERREIRO
				   printf(":::::::::::::  SUB MENU GUERREIROS  ::::::::::::::::\n");
				   printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
			       subMenu();
				   scanf("%i", &menu1);
				   system ("cls");
				   
				   switch(menu1){ 
				   	
				   	case 1:
				   		cadastrarGuerreiro();
				   		break;
			   		case 2:
			   			listarGuerreiros();
		   				system("pause");
			   			break;
		   			case 3:
		   				pesquisarGuerreiro();
		   				break;
	   				case 4:
	   					apagarGuerreiro();
	   					break;
				   }
				   system("cls");
				}while(menu1 != 0);
				break;
				
			case 2:; // ESCOLHA DRAGÃO
				int menu2 = 0;
				system("cls");
				do{ // SUBMENU DRAGÃO
				   printf("::::::::::::::  SUB MENU DRAGÕES  ::::::::::::::::::\n");
				   printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
			       subMenu();
				   scanf("%i", &menu2);
				   system ("cls");
				   
				   switch(menu2){
				   	
				   	case 1:
				   		cadastrarDragao();
				   		break;
				   	;
				   	case 2:
				   		listarDragoes();
				   		system("pause");
				   		break;
			   		case 3:
			   			pesquisarDragoes();
			   			break;
		   			case 4:
		   				apagarDragao();
		   				break;
				   		
					
					} system("cls");
				}while(menu2 != 0);
				break;
				
				case 3:; // ESCOLHA ELEMENTO
				int menu3 = 0;
				system("cls");	
				
				do{//SUB MENUELEMENTOS
	   			printf("::::::::::::::  SUB MENU ELEMENTOS  ::::::::::::::::\n");
	   			printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
       			subMenu();
	   			scanf("%i", &menu3);
 			   	system ("cls");
				
				switch(menu3){
					case 1:
						 cadastrarElemento();
						 break;
					
					case 2:
						listarElementos();
						system("pause");
						break;
					case 3:
						pesquisarElementos();
						break;
					case 4:
						apagarElemento();
						break;
					
				}
				system("cls");
				}while(menu3 != 0);
				break;
				
				case 4:;//ESCOLHA LOCAÇÕES
				int menu4 = 0;
				system("cls");
				do{ // SUB MENU LOCAÇÕES
 				printf("::::::::::::::  SUB MENU LOCAÇÕES  ::::::::::::::::\n");
	   			printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
       			subMenu();
	   			scanf("%i", &menu4);
 			   	system ("cls");
 			   	
 			   	switch(menu4){
 			   		case 1:
 			   			realizarLocacao();	
 			   			break;
 			   		
 			   		case 2:
 			   			listarLocacoes();
 			   			system("pause");
						break;
					case 3:
						pesquisarLocacao();
						break;
					case 4:
						apagarLocacao();
						break;
					}
 			   	system("cls");
				}while(menu4 !=0);
				break;
				
					
			}
				
		
}while(menu != 0);

printf("Obrigado por utilziar nossos serviços!");
	
	return 0;
}
