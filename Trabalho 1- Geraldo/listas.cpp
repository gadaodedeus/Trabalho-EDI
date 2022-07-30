#include "listas.h"
#include <iostream>
#include <cstddef>
#include <stdio.h>
using namespace std;

/////////////////////////////////////
//Alunos/////////////////////////////
/////////////////////////////////////

//Novo elemento do tipo avaliacao
elem_aluno* novoElemAluno(aluno* a)
{
	elem_aluno* elem = new elem_aluno();
	elem->info = *a;
	elem->prox = NULL;
		
	return elem;
}


int VaziaAl(list_aluno* l)
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
  if(VaziaAl(l))
  {
    l->qnt++;
    l->inicio = elem;
    l->fim = elem;
  }
  
  else if(l->qnt<50)
  {
    l->fim->prox = elem;
    l->fim = elem;
    l->qnt++;
  }
  
  else
  	cout<<"\nSala cheia!";
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
		aux = aux->prox;
	}
	
	
	if(achou && l->qnt == 1)
		iniciaAluno(l);
		
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
	if(VaziaAl(l))
	{
		cout<<"Lista vazia!\n";
	}
		
	else
	{
		elem_aluno* aux = l->inicio;
		while(aux)
		{
			//printAluno(aux->info);
			aux = aux->prox;
		}
	}
}

//Print no arquivo
void printListAlunoArq(list_aluno* l, char arqName[])
{
	if(VaziaAl(l))
	{
		cout<<"Lista vazia!\n";
	}
		
	else
	{
		FILE* arq;
		arq = fopen(arqName, "w");
		elem_aluno* aux = l->inicio;
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
			while(aux->info.freq[i] != '\0')
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

int contemAluno(list_aluno* l, char nomeAluno[])
{

	if(!l->qnt)
		return 0;
	else
	{
		elem_aluno* aux = new elem_aluno();
		aux = l->inicio;
		
		while(aux)
		{
			if(compStr(aux->info.nome, nomeAluno))
				return 1;
			aux = aux->prox;
		}
	}
	return 0;
}

elem_aluno* buscaAluno(list_aluno* l, char nomeAluno[])
{
	if(contemAluno(l, nomeAluno))
	{
		elem_aluno* aux = new elem_aluno();
		aux = l->inicio;
		
		while(aux)
		{
			if(compStr(aux->info.nome, nomeAluno))
				return aux;
			aux = aux->prox;
		}
	}	
	else 
		return NULL;
}

void printRefAluno(list_aluno* l)
{
	elem_aluno* aux = new elem_aluno();
	aux = l->inicio;
	
	if(!VaziaAl(l))
	{
		while(aux)
		{
			cout<<"\n\t"<<aux->info.nome;
			aux = aux->prox;
		}		
	}
}

/////////////////////////////////////
//Aulas//////////////////////////////
/////////////////////////////////////


elem_aula* novoElemAula(aula* info)
{
	elem_aula* elem = new elem_aula();
	elem->info = *info;
	elem->prox = NULL;
	
	return elem;
}

void iniciaAula(list_aula* l)
{
	l->inicio = NULL;
	l->fim = NULL;
	l->qnt = 0;
}

int VaziaAu(list_aula* l)
{
	return(l->inicio == NULL);
}

void addAula(list_aula* l, elem_aula* elem)
{
	if(VaziaAu(l))
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
		aux = aux->prox;
	}
	
	
	if(achou && l->qnt == 1)
		iniciaAula(l);
		
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
	if(VaziaAu(l))
	{
		cout<<"Lista vazia!\n";
	}
		
	else
	{
		elem_aula* aux = l->inicio;
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
	if(VaziaAu(l))
	{
		cout<<"Lista vazia!\n";
	}
		
	else
	{
		FILE* arq;
		arq = fopen(arqName, "w");
		elem_aula* aux = l->inicio;
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


/////////////////////////////////////
//Avaliacao//////////////////////////
/////////////////////////////////////


//Novo elemento do tipo avaliacao
elem_avaliacao* novoElemAv(avaliacao* a)
{
	elem_avaliacao* elem = new elem_avaliacao();
	elem->info = *a;
	elem->prox = NULL;
		
	return elem;
}


int VaziaAv(list_avaliacao* l)
{
	return(l->inicio == NULL);
}

void iniciaAval(list_avaliacao* l)
{
	l->inicio = NULL;
	l->fim = NULL;
	l->qnt = 0;
}

void addAvaliacao(list_avaliacao* l, elem_avaliacao* elem)
{
  if(VaziaAv(l))
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

void removeAval(list_avaliacao* l, char nome[])
{
	elem_avaliacao* aux = l->inicio;
	elem_avaliacao* ant;
	int achou = 0;
	
	while(aux)
	{
		if(compStr(aux->info.nome, nome))
		{
			achou = 1;
			break;
		}
		ant = aux;
		aux = aux->prox;
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
		ant->prox == NULL;
		l->fim = ant;
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

void printRefAval(list_avaliacao* l)
{
	elem_avaliacao* aux = new elem_avaliacao();
	aux = l->inicio;
	while(aux)
	{
		cout<<" "<<aux->info.nome;
		aux = aux->prox;
	}
}


//Print na tela
void printListAval(list_avaliacao* l)
{
	if(VaziaAv(l))
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
	if(VaziaAv(l))
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
		avaliacao aux;	//%50[^\n] --> 50 = num max de char// input de strign com espaï¿½o
		fscanf(arq, "%50[^\n]\n%c\n%d\n%d\n%d\n%d\n", &aux.nome,&aux.tipo,&aux.data.dia,&aux.data.mes,&aux.data.ano,&aux.peso);
		elem_avaliacao* elem =  novoElemAv(&aux);
		addAvaliacao(l, elem);
	}
	fclose(arq);
	
}


/////////////////////////////////////
//Disciplina/////////////////////////
/////////////////////////////////////



//Novo elemento do tipo avaliacao
disciplina* novoElemDisc(info_disc* d)
{
	disciplina* elem = new disciplina();
	elem->info = *d;
	elem->prox = NULL;
		
	return elem;
}


int VaziaDisc(list_disc* l)
{
	return(l->inicio == NULL);
}

void iniciaDisc(list_disc* l)
{
	l->inicio = NULL;
	l->fim = NULL;
	l->qnt = 0;
}

void addDisc(list_disc* l, disciplina* elem)
{
	if(l->qnt == 14 )
		return;
	else
	{
		elem->prox = NULL;
		if(VaziaDisc(l))
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
			cout<<"\nDisciplina removida com sucesso!";
			achou = 1;
			break;
		}
		ant = aux;
		aux = aux->prox;
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
void printRefDisc(list_disc* l)
{
	if(VaziaDisc(l))
	{
		cout<<"Lista vazia!\n";
	}
	
	else
	{
		disciplina* aux = l->inicio;
		while(aux)
		{
			cout<<aux->info.codigo<<"\n";
			aux = aux->prox;
		}
	}
}

void printListDisc(list_disc* l)
{
	if(VaziaDisc(l))
	{
		cout<<"Lista vazia!\n";
	}
		
	else
	{
		disciplina* aux = l->inicio;
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
	if(VaziaDisc(l))
	{
		cout<<"Lista vazia!\n";
	}
		
	else
	{
		FILE* arq;
		arq = fopen(arqName, "w");
		disciplina* aux = l->inicio;
		while(aux)
		{
			fprintf(arq, "%s\n", aux->info.codigo);
			fprintf(arq, "%s\n", aux->info.nome);
			fprintf(arq, "%d\n", aux->info.ano);
			fprintf(arq, "%d\n", aux->info.semestre);
			fprintf(arq, "%d\n", aux->info.qnt_alunos);
			fprintf(arq, "%d\n", aux->info.qnt_provas);
      		fprintf(arq, "%d\n", aux->info.qnt_trab);
	      	fprintf(arq, "%d\n", aux->info.carga_prev);
    	  	fprintf(arq, "%d\n", aux->info.carga_real);
	      	fprintf(arq, "%f\n", aux->info.nota_aprov);
    	  	fprintf(arq, "%d\n", aux->info.freq);
      		
      		//printListAvalArq(aux->info.avaliacoes, arq);
      		//printListAulaArq(aux->info.aulas, arq);
        	//printListAlunoArq(aux->info.alunos, arq);
       
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
		avaliacao aux;	//%50[^\n] --> 50 = num max de char// input de strign com espaï¿½o
		fscanf(arq, "%50[^\n]\n%c\n%d\n%d\n%d\n%d\n", &aux.nome,&aux.tipo,&aux.data.dia,&aux.data.mes,&aux.data.ano,&aux.peso);
		elem_avaliacao* elem =  novoElemAv(&aux);
		addAvaliacao(l, elem);
	}
	fclose(arq);
	
}*/

int contemDisc(list_disc* l, char codDisc[])
{
	if(!l->qnt)
		return 0;
	else
	{
		disciplina* aux = new disciplina();
		aux = l->inicio;
		while(aux)
		{
			if(compStr(aux->info.codigo, codDisc))
				return 1;
			aux = aux->prox;
		}
	}
}

disciplina* buscaDisc(list_disc* l, char codDisc[])
{
	disciplina* aux = new disciplina();
	aux = l->inicio;
	
	if(contemDisc(l, codDisc))
	{
		while(aux)
		{
			if(compStr(aux->info.codigo, codDisc))
				return aux;
			aux = aux->prox;
		}
			
	}
	else
		return NULL;
}




///////////////////////////////////////
//Biblioteca Base//////////////////////
///////////////////////////////////////

//Comparacao de strings
int compStr(char str1[], char str2[])
{
	int i=0;
	while(str1[i] != '\0' && str2[i] != '\0')
	{
		if(str1[i] != str2[i])
			return 0;
		i++;
	}
	if((str1[i] == '\0' && str2[i] != '\0') || (str2[i] == '\0' && str1[i] != '\0'))
		return 0;
	
	return 1;
}

//Criaï¿½ao das structs
date novaData()
{
	date* temp = new date();
	do
	{
		cout<<"Dia: \n";
		cin>>temp->dia;
	}while(temp->dia<1 || temp->dia>31);
	do
	{
		cout<<"Mes: \n";
		cin>>temp->mes;
	}while(temp->mes<1 || temp->mes>12);	
	do
	{
		cout<<"Ano: \n";
		cin>>temp->ano;
	}while(temp->ano<2012);

	return *temp;	
}

avaliacao novaAvaliacao()    //ESSE AQUI
{
	avaliacao* temp = new avaliacao();
	
	cout<<"Nome: \n";
	cin>>temp->nome;
	do
	{
		cout<<"Tipo: \n";
		cin>>temp->tipo;
	}while(temp->tipo != 't' && temp->tipo != 'T' && temp->tipo != 'p' && temp->tipo != 'P');
	
	temp->data = novaData();
	do
	{
		cout<<"Peso: \n";
		cin>>temp->peso;
	}while(temp->peso<0 || temp->peso>100);
	cout<<"\n\n";
	char c = getchar();
	
	return *temp;
}

aula novoAula()
{
  
  aula* temp = new aula();
 
  /*do{
    cout<<"Numero de ordem: \n";
    cin>>temp.num;
  }while(temp.num < 1);		Segue a sequencia crescente 1, 2, 3, ...*/
  temp->num = 0;
  cout<<"Data da aula: \n";
  temp->data = novaData();
  cout<<"Quantidade de horas associadas a aula: \n";
  cin>>temp->qnt_horas;
  cout<<"Conteudo: ";
  cin>>temp->conteudo;
  cout<<"\n\n";
  char c = getchar();
  
  return *temp;
}

aluno novoAluno()
{
  aluno* temp = new aluno();

  cout<<"Numero do aluno: \n";
  do{
    cin>>temp->num;
    if (temp->num < 1 || temp->num > 50)
      cout<<"Numero invalido, digite novamente";
  }while(temp->num < 1 || temp->num > 50);
    
  cout<<"Nome do aluno: \n";
  cin>>temp->nome;

  /*cout<<"Nota em avaliacoes: \n";
    cout<<"Provas \n";
    for(int i=0; i < info_disc.qnt_prov; i++)
    cin>>temp.notas[i];

    cout<<"Trabalhos \n";  
   	 for(int i=1; i <= info_disc.qnt_trab; i++)
    cin>>temp.notas[qnt_prov+i];

  media = 

  if(media < info_disc.nota_aprov)
  {
    cout<<"Nota avaliacao final: \n";
    cin>>temp.
  }

  cout<<"Presencas e faltas: \n";
  for(int i=0; i <= info_disc.carga_real; i++)
  {
    cin>>freq[i];
  }
*/
  return *temp;
}


info_disc novaDisciplina(list_disc* l)
{
  info_disc* temp = new info_disc();
  
  do{
  	cout<<"Codigo: \n";
  	cin>>temp->codigo;
  }while(contemDisc(l, temp->codigo));
  
  cout<<"Nome: \n";
	cin>>temp->nome;

  do{
    cout<<"Ano: \n";
    cin>>temp->ano;
  }while(temp->ano<2000);
  
  do{
    cout<<"Semestre: \n";
    cin>>temp->semestre;	
  }while(temp->semestre != 1 && temp->semestre != 2);

  do{
    cout<<"Quantidade de alunos: \n";
    cin>>temp->qnt_alunos;
  }while(temp->qnt_alunos<0 || temp->qnt_alunos>50);	//Apenas settar como 0

  do{
    cout<<"Quantidade de provas: \n";
    cin>>temp->qnt_provas;
  }while(temp->qnt_provas>4 || temp->qnt_provas<0);		

  do{
    cout<<"Quantidade de trabalhos: \n";
    cin>>temp->qnt_trab;
  }while(temp->qnt_trab<0 || temp->qnt_trab>10);

  do{
    cout<<"Carga horaria prevista: \n";
    cin>>temp->carga_prev;
  }while(temp->carga_prev<0 || temp->carga_prev>60);

  do{
    cout<<"Carga horaria real: \n";		//Apenas settar como 0
    cin>>temp->carga_real;
  }while(temp->carga_real<0 || temp->carga_real>temp->carga_prev);

  do{
    cout<<"Nota minima para aprovacao: \n";
    cin>>temp->nota_aprov;
  }while(temp->nota_aprov<0.0 || temp->nota_aprov>10.0);

  do{
    cout<<"Frequencia minima para aprovacao: \n";
    cin>>temp->freq;
  }while(temp->freq<0 || temp->freq>100);
  
  
	temp->avaliacoes = new list_avaliacao();
	iniciaAval(temp->avaliacoes);
	
	temp->aulas = new list_aula();
	iniciaAula(temp->aulas);
	
	temp->alunos = new list_aluno();
	iniciaAluno(temp->alunos);
  
  
  return *temp;
}

professor novoProf()
{
  professor* temp = new professor();

  cout<<"Nome: ";
  cin>>temp->nome;

  cout<<"Quantidade de disciplinas: ";
  cin>>temp->qnt_disc;

  char c = getchar();
  return *temp;
}

//Prints
void printData(date temp)
{
	cout<<temp.dia<<"/"<<temp.mes<<"/"<<temp.ano;
}

void printAvaliacao(avaliacao temp)
{
	cout<<"\nNome: "<<temp.nome;
	cout<<"\nTipo: "<<temp.tipo;
	cout<<"\nData: ";
	printData(temp.data);
	cout<<"\nPeso: "<<temp.peso<<"\n";
}

void printDisc(info_disc d)
{
  cout<<"\nCodigo: "<<d.codigo;
  cout<<"\n----------------------------";
	cout<<"\n\nNome: "<<d.nome;
	cout<<"\n\nAno: "<<d.ano;
	cout<<"\n\nSemestre: "<<d.semestre;
	cout<<"\n\nQuantidade de anos: "<<d.qnt_alunos;
	cout<<"\n\nQuantidade de provas: "<<d.qnt_provas;
	cout<<"\n\nQuantidade de trabalhos: "<<d.qnt_trab;
	cout<<"\n\nCarga horaria prevista: "<<d.carga_prev;
	cout<<"\n\nCarga horaria real: "<<d.carga_real;
	float nota_aprov;	//Entre 0 e 10 (padrao 5.0)
	int freq;		//entre 0 e 100 (padrao 70 -> calculada com base em carga_prev)

	/*list_avaliacao *avaliacoes;
	list_aulas *aulas;*/
	
	cout<<"\n\nAlunos: ";
	printRefAluno(d.alunos);
	
	cout<<"\n\n";
}

void printAula(aula temp)
{
  cout<<"\nNumero de ordem: "<<temp.num;
  cout<<"\nData: ";
  printData(temp.data);
  cout<<"\nQuantidade de horas associadas a aula: "<<temp.qnt_horas;
  cout<<"\nConteudo: "<<temp.conteudo;
}

void printProf(professor p)
{
  cout<<"\nNome: "<<p.nome;
  cout<<"\nQuantidade de disciplinas: "<<p.qnt_disc;
}

/*void printAluno(aluno a)
{
  cout<<"\nNumero: "<<a.num;
  cout<<"\nNome: "<<a.nome;
  cout<<"\nNota trabalhos:"<<a.notas_trab;
  cout<<"\nNota provas:"<<a.notas_prova;
  for (int i=0; i<a.i_notas; i++)
    cout<<"\nAvaliacao "<<i+1<<":"<<a.nome[i];
    cout<"\nNota do exame: "<<a.exame;
  for (int i=0; i<)
}*/


