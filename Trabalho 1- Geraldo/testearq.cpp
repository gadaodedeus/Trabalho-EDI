#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
	char nome [15] = "teste";
	
	int i=49;
	char num=i+'0';
	
	char txt [5] = ".txt";

	nome[5] = num;
	strcat(nome, txt);

	FILE* teste = fopen(nome, "w");
	
	cout<<nome;

	fprintf(teste, "teste");
	
	
	fclose(teste);

	char nome1[15] = "teste";
	
	i++;
	num=i+'0';
	
	nome1[5] = num;
	strcat(nome1, txt);

	teste = fopen(nome1, "w");
	
	cout<<nome;

	fprintf(teste, "teste");
	
	
	fclose(teste);

	return 0;	
}

