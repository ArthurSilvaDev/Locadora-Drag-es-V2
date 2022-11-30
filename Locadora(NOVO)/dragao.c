#include "dragao.h"
#include <string.h>
#define MAX_DRAGAO 5

int qtdDragoes = 0;
int codigoAtualD = 1;

Dragao listaDeDragoes [MAX_DRAGAO];

int inicializarDragao(){
	int i;
	for (i=0; i<MAX_DRAGAO;i++){
	listaDeDragoes[i].cod = 0;
	listaDeDragoes[i].idade = 0;
	listaDeDragoes[i].nome[0] = '\0';
	listaDeDragoes[i].unidadesEmEstoque = 0;
	listaDeDragoes[i].valorDiario = 0;
	listaDeDragoes[i].idElemento =0;
	}
	
	listaDeDragoes[0].cod = codigoAtualD;
	listaDeDragoes[0].idade = 120;
	strcpy(listaDeDragoes[0].nome,"Brutos");
	listaDeDragoes[0].unidadesEmEstoque = 5;
	listaDeDragoes[0].valorDiario = 250;
	listaDeDragoes[0].idElemento = 1;
	qtdDragoes++;
	codigoAtualD++;
	
	listaDeDragoes[1].cod = codigoAtualD;
	listaDeDragoes[1].idade = 50;
	strcpy(listaDeDragoes[1].nome,"Tomenta");
	listaDeDragoes[1].unidadesEmEstoque = 8;
	listaDeDragoes[1].valorDiario = 300;
	listaDeDragoes[1].idElemento = 2;
	qtdDragoes++;
	codigoAtualD++;
	
}
int encerraDragao(){
}
int salvarDragao(Dragao c, int encontrado){
	
	if (qtdDragoes<MAX_DRAGAO && encontrado != 0){
		c.cod = codigoAtualD++;
		listaDeDragoes[qtdDragoes] = c;
		qtdDragoes++;
		
		return 1; // funcionou
	}
	
	else
		return 0; //falhou
}

int QuantidadeDragoes(){
	return qtdDragoes;
}
Dragao obterDragaoPeloIndice(int indice){
	return listaDeDragoes[indice];
}
Dragao obterDragaoPeloCodigo(int codigo){
	
	int encontrado = 0;
	int i;
	for (i=0; i <qtdDragoes; i++){
		Dragao d = listaDeDragoes[i];
		if (d.cod == codigo){
			return listaDeDragoes[i];
			encontrado ++;
		}
		
	}
	if (encontrado == 0){
		Dragao d;
		d.cod = -1;
		return d;
	}
	
	
}
int ApagarDragaoPeloCodigo(int codigo){
		int i;
	for(i=0; i <qtdDragoes; i++){
		if (listaDeDragoes[i].cod == codigo){
			listaDeDragoes[i] = listaDeDragoes[qtdDragoes-1];
			listaDeDragoes[qtdDragoes - 1].cod = 0;
			qtdDragoes--;
			return 1; //funcionou
		}
	}
	return 0; //falhou
}
