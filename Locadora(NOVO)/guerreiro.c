#include "guerreiro.h"
#include <stdlib.h>
#include <string.h>
#define MAX_GUERREIRO 5


int qtdGuerreiros = 0;
int codigoAtualG = 1;

Guerreiro listaDeGuerreiros [MAX_GUERREIRO];

int inicializarGuerreiros(){
	int i;
	for (i = 0; i < MAX_GUERREIRO; i++)
		{
			
			listaDeGuerreiros[i].nome[0] = '\0';
			listaDeGuerreiros[i].reino[0] = '\0';
			listaDeGuerreiros[i].titulo[0] = '\0';
			listaDeGuerreiros[i].cod = 0;
	}
	strcpy(listaDeGuerreiros[0].nome,"Arthur");
	strcpy(listaDeGuerreiros[0].reino,"Osorius");
	strcpy(listaDeGuerreiros[0].titulo,"Rei");
	listaDeGuerreiros[0].cod = codigoAtualG;
	codigoAtualG++;
	qtdGuerreiros++;
	
	strcpy(listaDeGuerreiros[1].nome,"Philip");
	strcpy(listaDeGuerreiros[1].reino,"Winterfell");
	strcpy(listaDeGuerreiros[1].titulo,"Cavaleiro");
	listaDeGuerreiros[1].cod = codigoAtualG;
	codigoAtualG++;
	qtdGuerreiros++;
	
	
}	

int encerraGuerreiros(){
 // util no final do trabalho
}

int salvarGuerreiro(Guerreiro c){
	
	if (qtdGuerreiros<MAX_GUERREIRO){
		c.cod = codigoAtualG++;
		listaDeGuerreiros[qtdGuerreiros] = c;
		qtdGuerreiros++;
		return 1; // funcionou
	}
	
	else
		return 0; //falhou
	
	
}

int QuantidadeGuerreiros(){
	
	return qtdGuerreiros;
}

Guerreiro obterGuerreiroPeloIndice(int indice){
	
	return listaDeGuerreiros[indice];
	
}

Guerreiro obterGuerreiroPeloCodigo(int codigo){
	
	int encontrado = 0;
	int i;
	for (i=0; i <qtdGuerreiros; i++){
		Guerreiro g = listaDeGuerreiros[i];
		if (g.cod == codigo){
			return listaDeGuerreiros[i];
			encontrado++;
		}
		
	}
	if (encontrado == 0){
		Guerreiro d;
		d.cod = -1;
		return d ;
	}
	
}

int ApagarGuerreiroPeloCodigo(int codigo){
	int i;
	for(i=0; i <qtdGuerreiros; i++){
		if (listaDeGuerreiros[i].cod == codigo){
			listaDeGuerreiros[i] = listaDeGuerreiros[qtdGuerreiros-1];
			listaDeGuerreiros[qtdGuerreiros - 1].cod = 0;
			qtdGuerreiros--;
			return 1; //funcionou
		}
	}
	return 0; //falhou
}
