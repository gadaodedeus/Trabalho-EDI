#include <iostream>
#include "listas.h"
#include <cstddef>
using namespace std;


void menuDisciplina(disciplina* disc);

int main(int argc, char** argv) {
	list_avaliacao* avaliacoes = new list_avaliacao();
	iniciaAval(avaliacoes);

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
    	cout<<"5: Cadastrar aluno\n";
    	cout<<"6: Mostrar informacoes das disciplinas\n";
    	cout<<"7: Sair\n";
    	cout<<"-----------------------------\n";
    	do
    	{
      	cin>>op;
      	if(op < 1 || op > 7)
        	cout<<"Opcao invalida\n";
    	}while(op < 1 || op > 7);    
  
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
     
    	else if(op == 5)
    	{
    		aluno novaInfo;
      		novaInfo = novoAluno();
      		elem_aluno* temp = new elem_aluno();
      		temp = novoElemAluno(&novaInfo);
      		
      		disciplina* discTemp = new disciplina();
      		
      		int flag;
      		
      		cout<<"\nDeseja matricular o aluno em alguma disciplina?[Sim-1/Nao-0]";
      		cin>>flag;
      		while(flag)
      		{
      			printRefDisc(disciplinas);
				char disc[10];
      			cout<<"\nInforme o codigo da disciplina: ";
      			cin>>disc;
      			discTemp = buscaDisc(disciplinas, disc);
      			if(discTemp)
      			{
      				addAluno(discTemp->info.alunos, temp);
      				discTemp->info.qnt_alunos++;
			  	}
      		
      			cout<<"\nDeseja matricular o aluno em mais alguma disciplina?[Sim-1/Nao-0]";
      			cin>>flag;
			}
    	}
    	
    	else if(op == 6) printListDisc(disciplinas);
      
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
  		cout<<"\n0: Voltar";
	  	do{
  			cin>>op;
		}while(op<0 || op >2);
	
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
