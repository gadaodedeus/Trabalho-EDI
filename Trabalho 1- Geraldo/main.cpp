#include <iostream>
#include "listas.h"
#include <cstddef>
using namespace std;


void menuDisciplina(disciplina* disc);

int main(int argc, char** argv) {
	list_disc* disciplinas = new list_disc();
	iniciaDisc(disciplinas);
	
	
	int on = 1;
	int op;
	while(on)
  	{
    	cout<<"\n\n----------MENU-----------\n";
    	cout<<"1: Consultar disciplinas\n";
    	cout<<"2: Entrar menu da disciplina\n";
    	cout<<"3: Cadastrar disciplina\n";
    	cout<<"4: Remover disciplina\n";
    	cout<<"5: Mostrar informacoes das disciplinas\n";
    	cout<<"0: Sair\n";
    	cout<<"-----------------------------\n";
    	do
    	{
      	cin>>op;
      	if(op < 0 || op > 5)
        	cout<<"Opcao invalida\n";
    	}while(op < 0 || op > 5);    
  
    	if(op == 1) printRefDisc(disciplinas);

    	else if (op == 2)
		{
			char cod[10];
			if(!VaziaDisc(disciplinas))
			{
				printRefDisc(disciplinas);
				cout<<"\nInforme o codigo da disciplina desejada";
				cin>>cod;
				menuDisciplina(buscaDisc(disciplinas, cod));
			}
		
			else
				cout<<"\nNao ha disciplinas iniciadas";
		} 
		
    	else if (op == 3) 
		{
      		disciplina* temp = new disciplina();
			info_disc novo = novaDisciplina(disciplinas);
      		temp = novoElemDisc(&novo);
      		addDisc(disciplinas, temp);
    	}
    	
    	else if(op == 4)
    	{
    		char cod[10];
    		cout<<"\nInforme o codigo da disciplina";
    		cin>>cod;
    		removeDisc(disciplinas, cod);
		}
     
    	
    	else if(op == 5) printListDisc(disciplinas);
      
    	else on = 0;
      
	}
	
	
	return 0;
}

void menuDisciplina(disciplina* disc)
{
  int on=1, op;
  
  if(disc)
  {
  	while(on)
	  {
  		cout<<"\n"<<disc->info.nome;
	  	cout<<"\n------------------------\n";
  		cout<<"\n1: Matricular aluno";
  		cout<<"\n2: Consultar alunos";
  		cout<<"\n3: Adicionar nota dos alunos";
  		cout<<"\n4: Registro de frequencia dos alunos";
  		cout<<"\n5: Menu do aluno";	//Alterar informacoes de um aluno especifico(nome, num, adicionar falta, alterar nota...)
  		cout<<"\n6: Remover aluno";
  		
  		cout<<"\n7: Adicionar avaliacao";
  		cout<<"\n8: Consultar informacoes avaliacoes";
  		cout<<"\n9: Remover avaliacao";
  		cout<<"\n10: Alterar informacoes da avaliacao";
  		
  		cout<<"\n0: Voltar";
	  	do{
  			cin>>op;
		}while(op<0 || op >10);
	
		if(op == 1)
		{	
			if(disc->info.qnt_alunos<50)
			{
				aluno novaInfo;
      			novaInfo = novoAluno();
	      		elem_aluno* temp = new elem_aluno();
    	  		temp = novoElemAluno(&novaInfo);
      		
      			addAluno(disc->info.alunos, temp);
      			disc->info.qnt_alunos++;
			}
			else
				cout<<"\nSala cheia!";
		}
		
		if(op == 2)
		{
			cout<<"\nAlunos Matriculados:";
			printRefAluno(disc->info.alunos);
		}
		
		
		
		if(op == 6)	//Remover aluno
		{
			char nomeAluno[50];
			printRefAluno(disc->info.alunos);
			cout<<"\nInforme o nome do aluno";
			cin>>nomeAluno;
			removeAluno(disc->info.alunos, nomeAluno);
		}
		
		if(op == 7)	//Add aval
		{
			if(disc->info.qnt_provas + disc->info.qnt_trab < 14)
			{
				avaliacao novaInfo;
				novaInfo = novaAvaliacao();
				elem_avaliacao* temp = new elem_avaliacao();
				temp = novoElemAv(&novaInfo);
			
				addAvaliacao(disc->info.avaliacoes, temp);
				if(temp->info.tipo == 't' || temp->info.tipo == 'T')
					disc->info.qnt_trab++;
				else if(temp->info.tipo == 'p' || temp->info.tipo == 'P')
					disc->info.qnt_provas;
			}
			
			else
				cout<<"\nAvaliacoes atingiram seu maximo!";
		}
		
		if(op == 8)	//Consultar avaliacoes
		{
			printListAval(disc->info.avaliacoes);
		}
		
		if(op == 9) //Remover avaliacao
		{
			char nome[15];
			printRefAval(disc->info.avaliacoes);
			cout<<"\nInforme o nome da avaliacao";
			cin>>nome;
			
			removeAval(disc->info.avaliacoes, nome);
		}
	
		if(!op)	on = 0;
	
  	
	  }
  }
  
  else
  	cout<<"\nErro de codigo";
  
  
  
}
/*
void menuCadastro(){
  cout<<"-----CADASTRAR-----\n";
  cout<<"1: Disciplina\n";
  cout<<"2: Aluno(a)\n";
  cout<<"-------------------\n";
}*/
