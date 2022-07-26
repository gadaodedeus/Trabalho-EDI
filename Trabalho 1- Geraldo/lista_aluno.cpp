#include "lista_aluno.h"
#include <iostream>
#include <cstddef>
#include <stdio.h>
using namespace std;

//Novo elemento do tipo avaliacao
elem_aluno* novoElemAluno(aluno* a)
{
	elem_aluno* elem = new elem_aluno();
	elem->info = *a;
	elem->prox = NULL;
		
	return elem;
}


int Vazia(list_aluno* l)
{
	return(l->inicio == NULL);
}

void iniciaAluno(list_aluno* l)
{
	l->inicio = NULL;
	l->fim = NULL;
	l->qnt = 0;
}

void addAluno(list_aluno* l, elem_aluno* elem)
{
  if(Vazia(l))
  {
    l->qnt++;
    l->inicio = elem;
    l->fim = elem;
  }
  
  else
  {
    l->fim->prox = elem;
    l->fim = elem;
    l->qnt++;
  }
}	

void removeAluno(list_aluno* l, char nome[])
{
	elem_aluno* aux = l->inicio;
	elem_aluno* ant;
	int achou = 0;
	
	while(aux)
	{
		if(compStr(aux->info.nome, nome))
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
		cout<<"\nAvaliacao nao encontrada!";
}


//Print na tela
void printListAluno(list_aluno* l)
{
	if(Vazia(l))
	{
		cout<<"Lista vazia!\n";
	}
		
	else
	{
		aluno* aux = l->inicio;
		while(aux)
		{
			printAluno(aux->info);
			aux = aux->prox;
		}
	}
}

//Print no arquivo
void printListAlunoArq(list_aluno* l, char arqName[])
{
	if(Vazia(l))
	{
		cout<<"Lista vazia!\n";
	}
		
	else
	{
		FILE* arq;
		arq = fopen(arqName, "w");
		aluno* aux = l->inicio;
		int i = 0;
		while(aux)
		{
			fprintf(arq, "%d\n", aux->info.num);
			fprintf(arq, "%s\n", aux->info.nome);
			while(aux->info.notas[i] != '\0')
			{
				fprintf(arq, "%f\n", aux->info.notas[i]);
				i++;
			}
			fprintf(arq, "%d\n", i);
			fprintf(arq, "%f\n", aux->info.exame);
			fprintf(arq, "%f\n", aux->info.media_final);
			i = 0;
			while(freq[i] != '\0')
			{
				fprintf(arq, "%c\n", aux->info.freq[i]);
				i++;
			}
			fprintf(arq, "%d\n", i);
			
			aux = aux->prox;
		}
		fclose(arq);
	}
}	

//Backup do arquivo
void backupAluno(list_avaliacao* l)
{
	FILE* arq;
	arq = fopen("teste.txt", "r");
	while(!feof(arq))
	{
		avaliacao aux;	
		
		//Ver como vai fazer a leitura de vetores
		
		fscanf(arq, "%d\n%50[^\n]\n%c\n%d\n%d\n%d\n", &aux.nome,&aux.tipo,&aux.data.dia,&aux.data.mes,&aux.data.ano,&aux.peso);
		elem_avaliacao* elem =  novoElemAv(&aux);
		addAvaliacao(l, elem);
	}
	fclose(arq);
	
}


