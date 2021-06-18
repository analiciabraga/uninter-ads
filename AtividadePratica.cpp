/*#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct info //cria a struct para guardar os dados
{
	char nome[50];
	float salario;
}; struct info dados, * reg; //cria a vari�vel do tipo da struct criada e o ponteiro para registro


int main()
{
	setlocale(LC_ALL, "Portuguese"); //configura para receber caracteres do teclado ABNT2
	char c;
	reg = &dados;

	printf("    C�lculo de al�quota de imposto de renda\n");
	printf("        Ana L�cia Braga - RU 3423922\n");

	printf("Digite o nome do funcion�rio:\n");
	fgets(reg->nome, 50, stdin); //recebe e guarda o nome do funcionario
	while ((c = getchar()) != '\n' && c != EOF) {} //limpa o buffer de teclado

	printf("Digite o sal�rio do funcion�rio em R$:\n");
	scanf_s("%f", &reg->salario); //recebe e guarda o sal�rio do funcion�rio
	while ((c = getchar()) != '\n' && c != EOF) {} //limpa o buffer de teclado

	if (reg->salario > 0) //verifica se o salario informado � v�lido
	{
		if (reg->salario <= 1903.98) //estabelece as condi��es de cada faixa de al�quota e imprime os dados solicitados
		{
			printf("Dados do funcion�rio:\n");
			printf("Nome completo: %s\n", reg->nome);
			printf("Sal�rio recebido: R$%.2f\n", reg->salario);
			printf("Al�quota devida: Isento.\n");
		}
		else if (reg->salario >= 1903.99 && reg->salario < 2826.65)
		{
			printf("Dados do funcion�rio:\n");
			printf("Nome completo: %s\n", reg->nome);
			printf("Sal�rio recebido: R$%.2f\n", reg->salario);
			printf("Al�quota devida: 7,5%%\n");
			printf("Valor a ser deduzido: R$%.2f\n\n", reg->salario * 0.075);
		}
		else if (reg->salario >= 2826.66 && reg->salario < 3751.05)
		{
			printf("Dados do funcion�rio:\n");
			printf("Nome completo: %s\n", reg->nome);
			printf("Sal�rio recebido: R$%.2f\n", reg->salario);
			printf("Al�quota devida: 15%%\n");
			printf("Valor a ser deduzido: R$%.2f\n\n", reg->salario * 0.15);
		}
		else if (reg->salario >= 2751.06 && reg->salario < 4664.68)
		{
			printf("Dados do funcion�rio:\n");
			printf("Nome completo: %s\n", reg->nome);
			printf("Sal�rio recebido: R$%.2f\n", reg->salario);
			printf("Al�quota devida:22,5%%\n");
			printf("Valor a ser deduzido: R$%.2f\n\n", reg->salario * 0.225);
		}
		else
		{
			printf("Dados do funcion�rio:\n");
			printf("Nome completo: %s\n", reg->nome);
			printf("Sal�rio recebido: R$%.2f\n", reg->salario);
			printf("Al�quota devida:27,5%%\n");
			printf("Valor a ser deduzido: R$%.2f\n\n", reg->salario * 0.275);
		}
	}
	else
	{
		printf("Valor de sal�rio inv�lido!\n\n");
	}

	system("pause");
	return 0;
}*/


//QUEST�O 2
/*#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Portuguese"); //configura para receber caracteres do teclado ABNT2
	printf("    Uso de ponteiros\n");
	printf("    Ana L�cia Braga - RU 3423922\n");
	
	int RU[7], i, soma = 0;
	char c;
	int* pon;
		
	for (i = 0; i < 7; i++)
	{
		printf("Digite o %do algarismo do RU?\n ", i + 1); //recebe os algarismos
		scanf_s("%d", &RU[i]); //guarda o algarismo no vetor
		pon = &RU[i]; //transmite o vetor para o ponteiro
		soma = soma + (*pon); //faz a soma utilizando o ponteiro
		while ((c = getchar()) != '\n' && c != EOF) {} //limpa o buffer de teclado
	}
	//printf("%d", *pon);
	printf("A soma dos algarismos do RU �: %d\n", soma);

	system("pause");
	return 0;
}*/


//QUEST�O 3
/*#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int A[4][4];
int B[4][4];
int C[4][4];

void calc_soma(int* mat_A, int* mat_B, int* mat_C);

int main()
{
	setlocale(LC_ALL, "Portuguese"); //configura para receber caracteres do teclado ABNT2
	printf("    Soma de matrizes\n");
	printf("    Ana L�cia Braga - RU 3423922\n");
	int i, j;
	char ch;
	printf("\n     Defina a Matriz A:\n");
	for (i = 0; i < 4; i++){
		for (j = 0; j < 4; j++){
			printf("Digite o valor %d|%d =  ", i+1, j+1); //preenche a Matriz A
			scanf_s("%d", &A[i][j]);
			while ((ch = getchar()) != '\n' && ch != EOF) {} //limpa o buffer de teclado
			if (A[i][j] < 0)
			{
				printf("Somente n�meros positivos! Programa encerrado!");
				return 1;
			}
		}
	}
	printf("\n     Defina a Matriz B:\n");
	for (i = 0; i < 4; i++)	{
		for (j = 0; j < 4; j++)	{
			printf("Digite o valor %d|%d =  ", i+1, j+1);
			scanf_s("%d", &B[i][j]);
			while ((ch = getchar()) != '\n' && ch != EOF) {} //limpa o buffer de teclado
			if (B[i][j] < 0)
			{
				printf("Somente n�meros positivos! Programa encerrado!");
				return 1;
			}
		}
	}

	calc_soma(*A, *B, *C); //chama a fun��o para c�lculo da soma de matrizes
	printf("\n     Matriz A\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%i\t", A[i][j]);
		}
		printf("\n");
	}
	printf("\n     Matriz B\n");
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			printf("%d\t", B[i][j]);
		}
		printf("\n");
	}
	printf("\n     Matriz C = Matriz A + Matriz B\n");
	for (i = 0; i < 4; i++){
		for (j = 0; j < 4; j++){
			printf("%d\t", C[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

void calc_soma(int* mat_A, int* mat_B, int* mat_C) // declara a fun��o calc_soma
{
	int i;
	for (i = 0; i < 16; i++) { //percorre a matriz (que quando passada por ponteiro, torna-se um vetor unidimensional)
		mat_C[i] = mat_A[i] + mat_B[i]; //faz a soma da matrizes
	}

	return; //retorna para a fun��o principal sem enviar valores (void)
}*/

//QUEST�O 4
/*#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int* v; // define o ponteiro do vetor v

int preencherVetor(int* x, int y, int z); //declara a fun��o recursiva

int main()
{
	setlocale(LC_ALL, "Portuguese"); //configura para receber caracteres do teclado ABNT2
	int i, n, m=0;
	char c;
	printf("    Calculadora de soma recursiva\n");
	printf("    Ana L�cia Braga - RU 3423922\n");
	//define o tamanho do vetor
	printf("Digite o fator multiplicador:\n"); //solicita ao usu�rio o tamanho do vetor(quantidade de posi��es)
	scanf_s("%d", &n);
	while ((c = getchar()) != '\n' && c != EOF) {} //limpa o buffer de teclado
	//preenche o vetor
	printf("Digite o multiplicando:\n"); //solicita ao usu�rio os valores das posi��es do vetor
	scanf_s("%d", &m);
	while ((c = getchar()) != '\n' && c != EOF) {} //limpa o buffer de teclado
													   
	//apresenta o resultado da fun��o que preenche o vetor com os dados coletados, passados por par�metro
	printf("O produto da multiplica��o com fun��o recursiva �: %i\n", preencherVetor(v, n, m));

	system("pause");
	return 0;
}

int preencherVetor(int *x, int y, int z){ //fun��o recursiva recebe os valores preenchidos pelo usu�rio na main
	int i, soma=0;
    x = (int *) malloc(y * sizeof(int)); //estabelece o tamanho do vetor com a aloca��o de mem�ria necess�ria
    for (i=0; i<y; i++) { //preenche as posi��es do vetor e faz a soma recursivamente
        x[i] = z;
        soma += x[i];
    }
    return soma;
}*/

/*QUEST�O 5

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct info { //declara��o da struct contendo os dados solicitados
	char nome[41];
	char CPF[13];//informado long int na aula ao vivo, mas n�o comporta o tamanho de um CPF. Usei char para simplificar a tarefa
	char telefone[12];
	char email[41];
}; struct info dados[6]; //vari�vel do tipo da struct declarada como vetor para 6 posi��es

FILE* p_arq; //ponteiro para arquivo

int main()
{
	setlocale(LC_ALL, "Portuguese"); //configura para receber caracteres do teclado ABNT2

	printf("    Manipula��o de arquivo CSV\n");
	printf(" Ana L�cia Braga - RU 3423922\n");
	int x;
	x = fopen_s(&p_arq, "RU3423922.csv", "w"); //abre o arquivo para escrita

	if (x == NULL) //verifica se o arquivo foi aberto no comando anterior
	{
		int i;
		for (i = 0; i < 6; i++) { //preenche as posi��es do vetor e faz a soma recursivamente
			printf("Digite o nome do %io contato:\n", i+1);
			fgets(dados[i].nome, 41, stdin); //recebe e guarda o nome do contato
			dados[i].nome[strcspn(dados[i].nome, "\n")] = 0;

			printf("Digite o CPF do contato:\n");
			fgets(dados[i].CPF, 13, stdin); //recebe e guarda o CPF do contato
			dados[i].CPF[strcspn(dados[i].CPF, "\n")] = 0;

			printf("Digite o telefone do contato:\n");
			fgets(dados[i].telefone, 12, stdin); //recebe e guarda o telefone do contato
			dados[i].telefone[strcspn(dados[i].telefone, "\n")] = 0;

			printf("Digite o e-mail do contato:\n");
			fgets(dados[i].email, 41, stdin); //recebe e guarda o e-mail do contato
			dados[i].email[strcspn(dados[i].email, "\n")] = 0;
			printf("\n");
		}
		fprintf(p_arq, "Nome; CPF; Telefone; E-mail;\n"); //grava os dados no arquivo com o separador ;
		for (i = 0; i < 6; i++)
		{
			fprintf(p_arq, "%s;%s;%s;%s\n", dados[i].nome, dados[i].CPF, dados[i].telefone, dados[i].email);
		}
		fclose(p_arq); //fecha o arquivo com os dados gravados
		printf("Dados gravados!");
	}
	else //caso o arquivo retorne algum problema para abrir
	{
		printf("Erro na abertura do arquivo!\n");
		return 1;
	}
	system("pause");
	return 0;
}*/