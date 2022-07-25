#include <iostream>
#include <cstddef>
#include <stdio.h>
#include "lista_aula.h"

using namespace std;

elem_aula* novoElemAula(aula* info)
{
	elem_aula* elem = new elem_aula();
	elem.info = info;
	elem.prox = NULL;
	
	return elem;
}

void iniciaAula(list_aula* l)
{
	l->inicio = NULL;
	l->fim = NULL;
	l->qnt = 0;
}

int Vazia(list_aula* l)
{
	return(l->inicio == NULL);
}

void addAula(list_aula* l, elem_aula* elem)
{
	if(Vazia(l))
	{
		l->qnt++;
		elem->info.num = l->qnt;	//Numero da aula dada 
									//É um problema quando alguma aula ja foi removida
		l->inicio = elem;
		l->fim = elem;		
	}
	
	else
	{
		l->qnt++;
		elem->info.num = l->qnt;
		l->fim->prox = elem;
		l->fim = elem;
	}
}

void removeAula(list_aula* l, int n)
{
	elem_aula* aux = l->inicio;
	elem_aula* ant;
	int achou = 0;
	
	while(aux)
	{
		if(aux->info.num == n)
		{
			achou = 1;
			break;
		}
		ant = aux;
		aux = aux->prox
	}
	
	
	if(achou && l->qnt == 1)
		iniciaAval(l);
		
	else if(achou && aux == l->inicio)
	{
		l->inicio = aux->prox;
		l->qnt--;
		delete(aux);
	}
	
	else if(achou && aux == l->fim)
	{
		l->fim = ant;
		ant->prox == NULL;
		l->qnt--;
		delete(aux);
	}
	
	else if(achou)
	{
		ant->prox = aux->prox;
		l->qnt--;
		delete(aux);
	}
	
	else
		cout<<"\nAula nao encontrada!";
}

void printListAula(list_aula* l)
{
	if(Vazia(l))
	{
		cout<<"Lista vazia!\n";
	}
		
	else
	{
		aula* aux = l->inicio;
		while(aux)
		{
			printAula(aux->info);
			aux = aux->prox;
		}
	}
}

//Print no arquivo
void printListAulaArq(list_aula* l, char arqName[])
{
	if(Vazia(l))
	{
		cout<<"Lista vazia!\n";
	}
		
	else
	{
		FILE* arq;
		arq = fopen(arqName, "w");
		aula* aux = l->inicio;
		while(aux)
		{
			
			fprintf(arq, "%d\n", aux->info.num);
			fprintf(arq, "%d\n", aux->info.data.dia);
			fprintf(arq, "%d\n", aux->info.data.mes);
			fprintf(arq, "%d\n", aux->info.data.ano);
			fprintf(arq, "%d\n", aux->info.qnt_horas);
			fprintf(arq, "%s\n", aux->info.conteudo);
			aux = aux->prox;
		}
		fclose(arq);
	}
}	

//Backup do arquivo
void backupAula(list_aula* l)
{
	FILE* arq;
	arq = fopen("teste.txt", "r");
	while(!feof(arq))
	{
		aula aux;	//%50[^\n] --> 50 = num max de char// input de strign com espaï¿½o
		fscanf(arq, "%d\n%d\n%d\n%d\n%d\n%50[^\n]\n", &aux.num,&aux.data.dia,&aux.data.mes,&aux.data.ano,&aux.qnt_horas, &aux.conteudo);
		elem_aula* elem =  novoElemAula(&aux);
		addAula(l, elem);
	}
	fclose(arq);
}





