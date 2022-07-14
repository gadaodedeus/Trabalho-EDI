//Data
typedef struct d{
	int dia;
	int mes;
	int ano;
}date;

//Avalicao
typedef struct avali{
	char nome[50];
	char tipo;
	date data;
	int peso;	//De 0 a 100
}avaliacao;

typedef struct list_av{
	avaliacao info;
	struct list_av *prox;
}list_avaliacao;

//Aula
typedef struct aul{
	int num;	//Comeca em 1 -> 2 -> 3 ...
	date data;
	int qnt_horas;	//Padrao 2h
	char conteudo[255];
}aula;

typedef struct list_aul{
	aula info;
	struct list_aul *prox;
}list_aulas;

//Aluno
typedef struct alun{
	int num;		//Entre 1 e 50
	char nome[50];
	float notas[14];//10 trab + 4 provas
	int i_notas;
	float media_final;
	char freq[60];	//Max 60 horas
}aluno;

typedef struct list_alun{
	aluno info;
	struct list_alun *prox;
}list_alunos;

//Disciplina
typedef struct infod{
	char codigo[10];
	char nome[50];
	int ano;
	int semestre;	//1 ou 2
	int qnt_alunos;	//Max 50
	int qnt_provas;	//Max 4
	int qnt_trab;	//Max 10
	int carga_prev;	//Padrao 60 (max)
	int carga_real;
	float nota_aprov;	//Entre 0 e 10 (padrao 5.0)
	int freq;		//entre 0 e 100 (padrao 70 -> calculada com base em carga_prev)
	list_avaliacao *avaliacoes;
	list_aulas *aulas;
	list_alunos *alunos;
}info_disc;

typedef struct listd{
	info_disc info;
	listd *prox;
}disciplina;

//Professor
typedef struct prof{
	char nome[50];
	int qnt_disc;
}professor;




