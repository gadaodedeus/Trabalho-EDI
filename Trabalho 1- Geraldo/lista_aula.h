#include "biblioTrab.h"

elem_aula* novoElemAula(aula* info);
void iniciaAula(list_aula* l);
int Vazia(list_aula* l);
void addAula(list_aula* l, elem_aula* elem);
void removeAula(list_aula* l, int n);
void printListAula(list_aula* l);
void printListAulaArq(list_aula* l, char arqName[]);
void backupAula(list_aula* l);
