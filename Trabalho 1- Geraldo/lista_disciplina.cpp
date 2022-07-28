#include "lista_disciplina.h"
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

void iniciaDisc(list_disc* l)
{
	l->inicio = NULL;
	l->fim = NULL;
	l->qnt_elem = 0;
}

void addDisc(list_disc* l, disciplina* elem)
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

void removeDisc(list_disc * l, char codigo[])
{
	disciplina* aux = l->inicio;
	disciplina* ant;
	int achou = 0;
	
	while(aux)
	{
		if(compStr(aux->info.codigo, codigo))
		{
			achou = 1;
			break;
		}
		ant = aux;
		aux = aux->prox
	}
	
	
	if(achou && l->qnt == 1)
		iniciaDisc(l);
		
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
		cout<<"\nDisciplina nao encontrada!";
}

//Print na tela
void printListDisc(list_disc* l)
{
	if(Vazia(l))
	{
		cout<<"Lista vazia!\n";
	}
		
	else
	{
		elem_disciplina* aux = l->inicio;
		while(aux)
		{
			printDisc(aux->info);
			aux = aux->prox;
		}
	}
}

//Print no arquivo
void printListDiscArq(list_disc* l, char arqName[])
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
      
      		elem_avaliacao* aval = new avaliacao();
	    	aval = aux->info.avaliacoes->inicio;
    		while(i < aval->qnt)  
      		{	
        		printAvalArq(aval, arq);
	    	    aval = aval->prox;
	    	    i++;
    	  	}

      		i=0;
      		elem_aula* aulaTemp = new aula();
      		aulaTemp = aux->info.aulas->inicio;
      		while(i < aulaTemp->qnt)  
      		{
        		printAulaArq(aulaTemp, arq);
        		aulaTemp = aulaTemp->prox;
        		i++;
      		}

      		i=0;
      		elem_aluno* al = new elem_aluno();
      		al = info.alunos->inicio;
      		while(i < al->qnt)  
      		{
        		printAlunoArq(al, arq);
        		al = al->prox;
        		i++;
      		}
        
       
			aux = aux->prox;
		}
		fclose(arq);
	}
}	

//Backup do arquivo
/*void backupDisc(list_disc* l)
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
