#include <iostream>
//#include "biblioTrab.h"
#include "lista_avaliacao.h"
#include <cstddef>
using namespace std;


list_avaliacao* avaliacoes = new list_avaliacao();
iniciaAval(avaliacoes);

list_disc* disciplinas = new list_disc();
//iniciaDisc(disciplinas);	//Nao existe ainda


int main(int argc, char** argv) {
	
	
	//FILE* arq = fopen("teste.txt", w);
	
	/*avaliacao teste1 = novaAvaliacao();
  
	elem_avaliacao* elem1 = new elem_avaliacao();
	
  	elem1 = novoElemAv(&teste1);
	addAvaliacao(avaliacoes, elem1);
	
	avaliacao teste2 = novaAvaliacao();
	elem_avaliacao* elem2 = new elem_avaliacao();
	elem2 = novoElemAv(&teste2);
	addAvaliacao(avaliacoes, elem2);
	
	avaliacao teste3 = novaAvaliacao();
	elem_avaliacao* elem3 = new elem_avaliacao();
	elem3 = novoElemAv(&teste3);
	addAvaliacao(avaliacoes, elem3);
	
	
	backupAval(avaliacoes);
	printListAval(avaliacoes);
	
	//printListAval(avaliacoes);
	char teste[15] = "teste.txt";
	printListAvalArq(avaliacoes, teste);*/
	
	int on = 1;
	int op;
  while(on)
  {
    cout<<"-----MENU-----\n";
    cout<<"1: Consultar disciplinas\n";
    cout<<"2: Entrar menu da disciplina\n";
    cout<<"3: Cadastrar disciplina\n";
    cout<<"4: Cadastrar aluno\n";
    cout<<"5: Sair\n";
    cout<<"--------------\n";
    do
    {
      cin>>op;
      if(op < 1 || op > 5)
        cout<<"Opcao invalida\n";
    }while(op < 1 || op > 5);    
  
    if(op == 1) 
      printDisc();

    else if (op == 2) menuDisciplina();

    else if (op == 3) {
      disciplina temp = new disciplina() 
      temp.info = novaDisciplina();
      addDisc(diciplinas, temp);
      
    }
     

    else if(op == 4)
    {
      temp = novoAluno();
      printDisc(info_disc);
      //escolha uma disciplina
      //addAlunoNaDisciplina(algebra, temp);
      
    }
      
    else 
      on = 0;
      
  }
	
	
	return 0;
}

void menuDisciplina()
{
  cadastrar -> menuCadastro(int )
  consultar ->print
  atualsfiafdiuhgfaso0asafqwa -> menu
 
  
  alunos
  avaliacao 
  aulas
}

/*void menuCadastro(){
  cout<<"-----CADASTRAR-----\n";
  cout<<"1: Disciplina\n";
  cout<<"2: Aluno(a)\n";
  cout<<"-------------------\n";
}
