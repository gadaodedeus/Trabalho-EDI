#include <iostream>
#include "listas.h"
#include <cstddef>
using namespace std;




int main(int argc, char** argv) {
	list_avaliacao* avaliacoes = new list_avaliacao();
	iniciaAval(avaliacoes);

	list_disc* disciplinas = new list_disc();
	iniciaDisc(disciplinas);

	
	int on = 1;
	int op;
	while(on)
  	{
    	cout<<"-----MENU-----\n";
    	cout<<"1: Consultar disciplinas\n";
    	cout<<"2: Entrar menu da disciplina\n";
    	cout<<"3: Cadastrar disciplina\n";
    	cout<<"4: Cadastrar aluno\n";
    	cout<<"5: Mostrar informacoes das disciplinas\n";
    	cout<<"6: Sair\n";
    	cout<<"--------------\n";
    	do
    	{
      	cin>>op;
      	if(op < 1 || op > 6)
        	cout<<"Opcao invalida\n";
    	}while(op < 1 || op > 6);    
  
    	if(op == 1) printRefDisc(disciplinas);

    	//else if (op == 2) menuDisciplina();

    	else if (op == 3) 
		{
      		disciplina* temp = new disciplina();
			info_disc novo = novaDisciplina();
      		temp = novoElemDisc(&novo);
      		addDisc(disciplinas, temp);
    	}
     
    	else if(op == 4)
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
      				addAluno(discTemp->info.alunos, temp);
      			cout<<"\nDeseja matricular o aluno em mais alguma disciplina?[Sim-1/Nao-0]";
      			cin>>flag;
			}
    	}
    	
    	else if(op == 5) printListDisc(disciplinas);
      
    	else on = 0;
      
	}
	
	
	return 0;
}
/*
void menuDisciplina()
{
  cadastrar -> menuCadastro(int )
  consultar ->print
  atualsfiafdiuhgfaso0asafqwa -> menu
 
  
  alunos
  avaliacao 
  aulas
}

void menuCadastro(){
  cout<<"-----CADASTRAR-----\n";
  cout<<"1: Disciplina\n";
  cout<<"2: Aluno(a)\n";
  cout<<"-------------------\n";
}*/
