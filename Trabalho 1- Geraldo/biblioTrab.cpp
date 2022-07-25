
#include "biblioTrab.h"
#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <cstddef>
using namespace std;

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

//Cria�ao das structs
date novaData()
{
	date temp = new date();
	do
	{
		cout<<"Dia: \n";
		cin>>temp.dia;
	}while(temp.dia<1 || temp.dia>31);
	do
	{
		cout<<"Mes: \n";
		cin>>temp.mes;
	}while(temp.mes<1 || temp.mes>12);	
	do
	{
		cout<<"Ano: \n";
		cin>>temp.ano;
	}while(temp.ano<2012);

	return temp;	
}

avaliacao novaAvaliacao()    //ESSE AQUI
{
	avaliacao temp = new avaliacao();
	
	cout<<"Nome: \n";
	cin>>temp.nome;
	cout<<"Tipo: \n";
	cin>>temp.tipo;
	temp.data = novaData();
	do
	{
		cout<<"Peso: \n";
		cin>>temp.peso;
	}while(temp.peso<0 || temp.peso>100);
	cout<<"\n\n";
	char c = getchar();
	
	return temp;
}

aula novoAula()
{
  
  aula temp = new aula();
 
  /*do{
    cout<<"Numero de ordem: \n";
    cin>>temp.num;
  }while(temp.num < 1);*/
  
  cout<<"Data da aula: \n";
  temp.data = novaData();
  cout<<"Quantidade de horas associadas a aula: \n";
  cin>>temp.qtd_horas;
  cout<<"Conteudo: ";
  cin>>temp.conteudo;
  cout<<"\n\n";
  char c = getchar();
  
  return temp;
}

aula novoAluno()
{
  aluno temp = new aluno();

  cout<<"Numero do aluno: \n";
  do{
    cin>>temp.num;
    if (temp.num < 1 || temp.num > 50)
      cout<<"Numero invalido, digite novamente";
  }while(temp.num < 1 || temp.num > 50);
    
  cout<<"Nome do aluno: \n";
  cin>>temp.nome;

  cout<<"Nota em avaliacoes: \n";
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

  
}


info_disc novaDisciplina()
{
  info_disc temp = new info_disc();
  
  cout<<"Codigo: \n";
  cin>>temp.codigo;

  cout<<"Nome: \n";
	cin>>temp.nome;

  do{
    cout<<"Ano: \n";
    cin>>temp.ano;
  }while(temp.ano<2000);
  
  do{
    cout<<"Semestre: \n";
    cin>>temp.semestre;	
  }while(temp.semestre != 1 && temp.semestre != 2);

  do{
    cout<<"Quantidade de alunos: \n";
    cin>>temp.qnt_alunos;
  }while(temp.qnt_alunos<0 || temp.qnt_alunos>50);

  do{
    cout<<"Quantidade de provas: \n";
    cin>>temp.qnt_provas;
  }while(temp.qnt_provas>4 || temp.qnt_provas<0);

  do{
    cout<<"Quantidade de trabalhos: \n";
    cin>>temp.qnt_trab;
  }while(temp.qnt_trab<0 || temp.qnt_trab>10);

  do{
    cout<<"Carga horaria prevista: \n";
    cin>>temp.carga_prev;
  }while(temp.carga_prev<0 || temp.carga_prev>60);

  do{
    cout<<"Carga horaria real: \n";
    cin>>temp.carga_real;
  }while(temp.carga_real<0 || temp.caga_real>temp.carga_prev);

  do{
    cout<<"Nota minima para aprovacao: \n";
    cin>>temp.nota_aprov;
  }while(temp.nota_aprov<0.0 || temp.nota_aprov>10.0);

  do{
    cout<<"Frequencia minima para aprovacao: \n";
    cin>>temp.freq;
  }while(temp.freq<0 || temp.freq>100);
  
  /*
	list_avaliacao *avaliacoes;
	list_aulas *aulas;
	list_alunos *alunos;
  */
  
}

professor novoProf()
{
  professor temp = new professor();

  cout<<"Nome: ";
  cin>>temp.nome;

  cout<<"Quantidade de disciplinas: ";
  cin>>temp.qnt_disc;

  char c = getchar();
  return temp;
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
	cout<<"\nNome: "<<d.nome;
	cout<<"\nAno: "<<d.ano;
	cout<<"\nSemestre: "<<d.semestre;
	cout<<"\nQuantidade de anos: "<<d.qnt_alunos;
	cout<<"\nQuantidade de provas: "<<d.qnt_provas;
	cout<<"\nQuantidade de trabalhos: "<<d.qnt_trab;
	cout<<"\nCarga horaria prevista: "<<d.carga_prev;
	cout<<"\nCarga horaria real: "carga_real;
	float nota_aprov;	//Entre 0 e 10 (padrao 5.0)
	int freq;		//entre 0 e 100 (padrao 70 -> calculada com base em carga_prev)

	/*list_avaliacao *avaliacoes;
	list_aulas *aulas;
	list_alunos *alunos;    */
}

void printAula(aula temp)
{
  cout<<"\nNumero de ordem: "<<temp.num;
  cout<<"\nData: ";
  printData(temp.data);
  cout<<"\nQuantidade de horas associadas a aula: "<<temp.qtd_horas;
  cout<<"\nConteudo: "<<temp.conteudo;
}

void printProf(professor p)
{
  cout<<"\nNome: "<<p.nome;
  cout<<"\nQuantidade de disciplinas: "<<p.qnt_disc;
}

void printAluno(aluno a)
{
  cout<<"\nNumero: "<<a.num;
  cout<<"\nNome: "<<a.nome;
  cout<<"\nNota trabalhos:"<<a.notas_trab;
  cout<<"\nNota provas:"<<a.notas_prova;
  for (int i=0; i<a.i_notas; i++)
    cout<<"\nAvaliacao "<<i+1<<":"<<a.nome[i];
    cout<"\nNota do exame: "<<a.exame;
  for (int i=0; i<)
}
