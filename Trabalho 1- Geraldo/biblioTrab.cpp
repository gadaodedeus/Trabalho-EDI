#include "biblioTrab.h"
#include <stdio.h>
#include <iostream>
#include <cstddef>
using namespace std;

//Criaçao das structs
date novaData()
{
	date temp;
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

avaliacao novaAvaliacao()
{
	avaliacao temp;
	
	cout<<"Nome: \n";
	gets(temp.nome);
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

//Prints
void printData(date temp)
{
	cout<<temp.dia<<"/"<<temp.mes<<"/"<<temp.ano<<"";
}

void printAvaliacao(avaliacao temp)
{
	cout<<"\nNome: "<<temp.nome;
	cout<<"\nTipo: "<<temp.tipo;
	cout<<"\nData: ";
	printData(temp.data);
	cout<<"\nPeso: "<<temp.peso<<"\n";
}




