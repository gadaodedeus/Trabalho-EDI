#include <iostream>
//#include "biblioTrab.h"
#include "lista_avaliacao.h"
#include <cstddef>
using namespace std;

int main(int argc, char** argv) {
	list_avaliacao* avaliacoes = new list_avaliacao();
	iniciaAval(avaliacoes);
	
	avaliacao teste1 = novaAvaliacao();
	elem_avaliacao* elem1 = new elem_avaliacao();
	elem1 = novoElemAv(&teste1);
	addAvaliacao(avaliacoes, elem1);
	
	/*avaliacao teste2 = novaAvaliacao();
	elem_avaliacao* elem2 = new elem_avaliacao();
	elem2 = novoElemAv(&teste2);
	addAvaliacao(avaliacoes, elem2);
	
	avaliacao teste3 = novaAvaliacao();
	elem_avaliacao* elem3 = new elem_avaliacao();
	elem3 = novoElemAv(&teste3);
	addAvaliacao(avaliacoes, elem3);*/
	
	
	
	printListAval(avaliacoes);
	
	
	
	
	
	return 0;
}
