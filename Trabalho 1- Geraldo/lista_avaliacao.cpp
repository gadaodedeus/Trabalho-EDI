#include "lista_avaliacao.h"
#include <iostream>
#include <cstddef>
using namespace std;

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
		}
	}
}	
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




