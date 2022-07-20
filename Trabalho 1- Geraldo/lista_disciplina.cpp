#include "biblioTrab.h"
#include <iostream>
#include <cstddef>
#include <stdio.h>
using namespace std;

//Novo elemento do tipo avaliacao
disciplina* novoElemDisc(info_disc* d)
{
	disciplina* elem = new disciplina();
	elem->info = *d;
	elem->prox = NULL;
		
	return elem;
}


int Vazia(list_disciplina* l)
{
	return(l->inicio == NULL);
}

void iniciaDisc(list_disciplina* l)
{
	l->inicio = NULL;
	l->fim = NULL;
	l->qnt_elem = 0;
}

void addDisc(list_disciplina* l, disciplina* elem)
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
			fprintf(arq, "%s\n", aux->info.codigo);
			fprintf(arq, "%s\n", aux->info.nome);
			fprintf(arq, "%d\n", aux->info.ano);
			fprintf(arq, "%d\n", aux->info.semestre);
			fprintf(arq, "%d\n", aux->info.qtd_alunos);
			fprintf(arq, "%d\n", aux->info.qtd_provas);
      fprintf(arq, "%d\n", aux->info.qtd_trab);
      fprintf(arq, "%d\n", aux->info.carga_prev);
      fprintf(arq, "%d\n", aux->info.carga_real);
      fprintf(arq, "%f\n", aux->info.nota_aprov);
      fprintf(arq, "%d\n", aux->info.freq);
      int i=0;
      
      avaliacao* aval = new avaliacao();
      aval = info.avaliacoes->inicio;
      while(i < aux->info.qnt_trab+aux->info.qnt_trab)  
      {
        printAvalArq(aval, arq);
        aval = aval->prox;
      }

      i=0;
      aula* aulaTemp = new aula();
      aulaTemp = info.aulas->inicio;
      while(i < /*qntidade de aulas*/)  
      {
        printAulaArq(aulaTemp, arq);
        aulaTemp = aulaTemp->prox;
      }

      i=0;
      aluno* al = new aluno();
      al = info.alunos->inicio;
      while(i < aux->info.qnt_alunos)  
      {
        printAlunoArq(al, arq);
        al = al->prox;
      }
        
       
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