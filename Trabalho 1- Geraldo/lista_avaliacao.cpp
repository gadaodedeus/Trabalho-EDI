#include "lista_avaliacao.h"
#include <iostream>
#include <cstddef>
#include <stdio.h>
using namespace std;

//Novo elemento do tipo avaliacao
elem_avaliacao* novoElemAv(avaliacao* a)
{
	elem_avaliacao* elem = new elem_avaliacao();
	elem->info = *a;
	elem->prox = NULL;
		
	return elem;
}


int Vazia(list_avaliacao* l)
{
	return(l->inicio == NULL);
}

void iniciaAval(list_avaliacao* l)
{
	l->inicio = NULL;
	l->fim = NULL;
	l->qnt_elem = 0;
}

void addAvaliacao(list_avaliacao* l, elem_avaliacao* elem)
{
	if(l->qnt_elem == 14)
		return;
	else
	{
		elem->prox = NULL;
		if(Vazia(l))
		{
			l->qnt_elem++;
			l->inicio = elem;
			l->fim = elem;
		}
		
		else
		{
			l->fim->prox = elem;
			l->fim = elem;
      l->qnt_elem++;
		}
	}
}	

//Print na tela
void printListAval(list_avaliacao* l)
{
	if(Vazia(l))
	{
		cout<<"Lista vazia!\n";
	}
		
	else
	{
		elem_avaliacao* aux = l->inicio;
		while(aux)
		{
			printAvaliacao(aux->info);
			aux = aux->prox;
		}
	}
}

//Print no arquivo
void printListAvalArq(list_avaliacao* l, char arqName[])
{
	if(Vazia(l))
	{
		cout<<"Lista vazia!\n";
	}
		
	else
	{
		FILE* arq;
		arq = fopen(arqName, "w");
		elem_avaliacao* aux = l->inicio;
		while(aux)
		{
			fprintf(arq, "%s\n", aux->info.nome);
			fprintf(arq, "%c\n", aux->info.tipo);
			fprintf(arq, "%d\n", aux->info.data.dia);
			fprintf(arq, "%d\n", aux->info.data.mes);
			fprintf(arq, "%d\n", aux->info.data.ano);
			fprintf(arq, "%d\n", aux->info.peso);
			aux = aux->prox;
		}
		fclose(arq);
	}
}	

//Backup do arquivo
void backupAval(list_avaliacao* l)
{
	FILE* arq;
	arq = fopen("teste.txt", "r");
	while(!feof(arq))
	{
		avaliacao aux;	//%50[^\n] --> 50 = num max de char// input de strign com espa�o
		fscanf(arq, "%50[^\n]\n%c\n%d\n%d\n%d\n%d\n", &aux.nome,&aux.tipo,&aux.data.dia,&aux.data.mes,&aux.data.ano,&aux.peso);
		elem_avaliacao* elem =  novoElemAv(&aux);
		addAvaliacao(l, elem);
	}
	fclose(arq);
	
}






