//Data
typedef struct data{
	int dia;
	int mes;
	int ano;
}date;




//Avalicao
typedef struct aval{
	char nome[50];
	char tipo;
	date data;
	int peso;	//De 0 a 100
}avaliacao;

typedef struct elem_av{
	avaliacao info;
	struct elem_av *prox;
}elem_avaliacao;

typedef struct list_av{
	elem_avaliacao* inicio;
	elem_avaliacao* fim;
	int qnt;
}list_avaliacao;




//Aula
typedef struct aul{
	int num;	//Comeca em 1 -> 2 -> 3 ...
	date data;
	int qnt_horas;	//Padrao 2h
	char conteudo[255];
}aula;

typedef struct elem_aul{
	aula info;
	struct elem_aul *prox;
}elem_aula;

typedef struct list_au{
	elem_aula *inicio, *fim;
	int qnt;
}list_aula;




//Aluno
typedef struct aluno{
	int num;		//Entre 1 e 50
	char nome[50];
	float notas[14];//10 trab + 4 provas
	//int i_notas;
  	float exame;
	float media_final;
	char freq[60];	//Max 60 horas
}aluno;

typedef struct elem_alun{
	aluno info;
	struct elem_alun *prox;
}elem_aluno;

typedef struct list_al{
	elem_aluno *inicio, *fim;
	int qnt;
}list_aluno;




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
	list_aula *aulas;
	list_aluno *alunos;
}info_disc;

typedef struct elemd{
	info_disc info;
	elemd *prox;
}disciplina;

typedef struct listd{
  disciplina *inicio, *fim;
  int qnt;
}list_disc;

//Professor
typedef struct prof{
	char nome[50];
	int qnt_disc;
}professor;


/////////////////////////////////////////

//Func

	//Criacao de structs
date novaData();
avaliacao novaAvaliacao();
info_disc novaDisciplina();
aula novoAula();
aluno novoAluno();
professor novoProf();

	//Print
void printData(date);
void printAvaliacao(avaliacao);
void printDisc(info_disc);
void printAula(aula);
//void printAluno(aluno);
void printProf(professor);

	//Outros
int compStr(char str1[], char str2[]);

//Aluno
int VaziaAl(list_aluno*);
void iniciaAluno(list_aluno*);
void addAluno(list_aluno*, elem_aluno*);
void removeAluno(list_aluno*, char*);
void printListAluno(list_aluno*);
void printListAlunoArq(list_aluno*, char*);
elem_aluno* novoElemAluno(aluno*);
void backupAluno(list_aluno*);
int contemAluno(list_aluno* d, char nomeAluno[]);
elem_aluno* buscaAluno(list_aluno* l, char nomeAluno[]);
void printRefAluno(list_aluno* l);


//Disciplina
disciplina* novoElemDisc(info_disc* d);
int VaziaDisc(list_disc* l);
void iniciaDisc(list_disc* l);
void addDisc(list_disc* l, disciplina* elem);
void removeDisc(list_disc* l, char codigo[]);
void printRefDisc(list_disc* l);
void printListDisc(list_disc* l);
void printListDiscArq(list_disc* l, char arqName[]);
void backupDisc(list_disc* l);
int contemDisc(list_disc* l, char codDisc[]);
disciplina* buscaDisc(list_disc* l, char codDisc[]);

//Aula
elem_aula* novoElemAula(aula* info);
void iniciaAula(list_aula* l);
int VaziaAu(list_aula* l);
void addAula(list_aula* l, elem_aula* elem);
void removeAula(list_aula* l, int n);
void printListAula(list_aula* l);
void printListAulaArq(list_aula* l, char arqName[]);
void backupAula(list_aula* l);

//Avaliacao
int VaziaAv(list_avaliacao* l);
void iniciaAval(list_avaliacao* l);
void addAvaliacao(list_avaliacao* l, elem_avaliacao* elem);
void removeAval(list_avaliacao* l, char nome[]);
void printListAval(list_avaliacao* l);
void printListAvalArq(list_avaliacao* l, char arqName[]);
elem_avaliacao* novoElemAv(avaliacao* a);
void backupAval(list_avaliacao* l);
