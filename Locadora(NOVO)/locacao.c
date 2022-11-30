#include "locacao.h"
#include <string.h>
#define MAX_LOCACAO 5

int qtdLocacao = 0;
int codigoAtualL = 1;

Locacao listaDeLocacao [MAX_LOCACAO];

int inicializarLocacao(){
	int i;
	for (i = 0; i < MAX_LOCACAO; i++){
		listaDeLocacao[i].cod = 0;
		listaDeLocacao[i].pago[0] = '\0';
		listaDeLocacao[i].fimLoc[0] = '\0';
		listaDeLocacao[i].inicioLoc[0] = '\0';
		listaDeLocacao[i].codGuerreiro = '\0';
		listaDeLocacao[i].codDragao = '\0';
	}
		listaDeLocacao[0].cod = codigoAtualL;
		strcpy(listaDeLocacao[0].pago, "S");
		strcpy(listaDeLocacao[0].fimLoc, "20/10");
		strcpy(listaDeLocacao[0].inicioLoc, "10/10");
		listaDeLocacao[0].codGuerreiro = 1;
		listaDeLocacao[0].codDragao = 1;
		qtdLocacao++;
		codigoAtualL++;
}
int encerraLocacao(){
	
	
}
int salvarLocacao(Locacao c){
	
		if (qtdLocacao < MAX_LOCACAO){
		c.cod = codigoAtualL++;
		listaDeLocacao[qtdLocacao] = c;
		qtdLocacao++;
		
		return 1; // funcionou
	}
	
	else
		return 0; //falhou
	
	
}
int QuantidadeLocacao(){
	return qtdLocacao;
}
Locacao obterLocacaoPeloIndice(int indice){
	return listaDeLocacao[indice];
	
}
Locacao obterLocacaoPeloCodigo(int codigo){
	
	int encontrado = 0;
	int i;
	for (i=0; i <qtdLocacao; i++){
		Locacao g = listaDeLocacao[i];
		if (g.cod == codigo){
			return listaDeLocacao[i];
			encontrado++;
		}
		
	}
	if (encontrado == 0){
		Locacao d;
		d.cod = -1;
		return d ;
	}
	
	
	
}
int ApagarLocacaoPeloCodigo(int codigo){
	int i;
	for(i=0; i <qtdLocacao; i++){
		if (listaDeLocacao[i].cod == codigo){
			listaDeLocacao[i] = listaDeLocacao[qtdLocacao-1];
			listaDeLocacao[qtdLocacao - 1].cod = 0;
			qtdLocacao--;
			return 1; //funcionou
		}
	}
}
