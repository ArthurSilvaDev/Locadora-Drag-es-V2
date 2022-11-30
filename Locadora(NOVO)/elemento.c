#include "elemento.h"
#include <string.h>
#define MAX_ELEMENTO 5

int qtdElementos = 0;
int codigoAtualE = 1;

Elemento listaDeElementos [MAX_ELEMENTO];

int inicializarElementos(){
		int i;
	for (i = 0; i < MAX_ELEMENTO; i++)
		{
			listaDeElementos[i].cod = 0;
			listaDeElementos[i].nome[0] = '\0';
			listaDeElementos[i].vulnerabilidade[0] = '\0';

	}
	strcpy(listaDeElementos[0].nome, "Ar");
	strcpy(listaDeElementos[0].vulnerabilidade, "Terra");
	listaDeElementos[0].cod = codigoAtualE;
	qtdElementos++;
	codigoAtualE++;
	
	strcpy(listaDeElementos[1].nome, "Raio");
	strcpy(listaDeElementos[1].vulnerabilidade, "Plasma");
	listaDeElementos[1].cod = codigoAtualE;
	qtdElementos++;
	codigoAtualE++;
}
int encerraElementos(){
	
}
int salvarElemento(Elemento c){
	
		if (qtdElementos<MAX_ELEMENTO){
		c.cod = codigoAtualE++;
		listaDeElementos[qtdElementos] = c;
		qtdElementos++;
		return 1; // funcionou
	}
	
	else
		return 0; //falhou
	
	
}
int QuantidadeElementos(){
	return qtdElementos;
}
Elemento obterElementoPeloIndice(int indice){
	return listaDeElementos[indice];
}
Elemento obterElementoPeloCodigo(int codigo){
	
	int encontrado = 0;
	int i;
	for (i=0; i <qtdElementos; i++){
		Elemento e = listaDeElementos[i];
		if (e.cod == codigo){
			return listaDeElementos[i];
			encontrado++;
		}
		
	}
	if (encontrado == 0){
		Elemento d;
		d.cod = -1;
		return d;
	}
	
}
int ApagarElementoPeloCodigo(int codigo){
		int i;
	for(i=0; i <qtdElementos; i++){
		if (listaDeElementos[i].cod == codigo){
			listaDeElementos[i] = listaDeElementos[qtdElementos-1];
			listaDeElementos[qtdElementos - 1].cod = 0;
			qtdElementos--;
			return 1; //funcionou
		}
	}
	return 0; //falhou
}



