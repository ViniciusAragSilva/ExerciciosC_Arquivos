/*================================================================*?
EXERCICIO 4 - LISTA DE ARQUIVOS DE VINICIUS ARAGAO 4323
-------------------------------------------------------------------
4 O usuário seleciona um arquivo no formato texto. Contar o 
número de palavras e a quantidade total de caracteres presentes 
neste arquivo. Exibir o resultado na tela.
/*=============================================================*/

/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/
/*																											*/
/*											INCLUDES														*/
/*																											*/
/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>

/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/
/*																											*/
/*											MAIN															*/
/*																											*/
/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/


int main()
{
	////////////////////////////////////CRIANDO VARIAVEIS & APRESENTANDO/////////////////////////////////////

	setlocale (LC_ALL,"");
	srand(time(NULL));
	FILE *fp;
	int * ContaPalavras(char string[50]);															// funcao ponteiro
	
	char nome[20];
	char string[50];
	int *funcao;

	printf("===========================================================================\n");
	printf("\n\t\t\t EXERCICIO 4 \n");
	printf("\n\t * Esse programa grava palavras num arquivo texto de nome escolhido\n");
	printf("\n\t * E conta o tanto de palavras e o numero de letras\n");
	printf("===========================================================================\n");

	printf("\n Digite o nome do arquivo (até 15 caracteres): ");
	gets(nome);	
	fflush(stdin);
	strcat(nome, ".txt");

	fp = fopen(nome,"wt");																// abrindo o arquivo na funcao de escrever texto
	fputs("==========================================\n", fp);
	fputs("\n\t\t EXERCICIO 4 - Vinicius Aragão\n", fp);
	fputs("==========================================\n", fp);
	
	////////////////////////////////////ATRIBUINDO VALORES/////////////////////////////////

	printf("\n Coloque palavras no arquivo (até 50 caract.): \n");
	printf("\n--------------------------------------------\n\n");
	gets(string);
	printf("\n--------------------------------------------\n\n");
	
	fputs("\n Palavras escritas: \n \" ",fp);
	fputs(string,fp);
	fputs("\" ",fp);

	funcao = ContaPalavras(string);														// funcao, que é um ponteiro, é atribuido ao contapalavras, outro ponteiro
	
	fputs("\n--------------------------------------\n", fp);
	printf("\n Quantidade de caracteres: %d \n", funcao[0]);
	fprintf(fp,"\n Quantidade de caracteres: %d", funcao[0]);	
	
	printf("\n Quantidade de palavras: %d \n", funcao[1]);
	fprintf(fp,"\n Quantidade de palavras: %d", funcao[1]);
	
	fclose(fp);
	getch();

}



/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/
/*																											*/
/*											FUNCOES EXTERNAS												*/
/*																											*/
/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/

int * ContaPalavras(char string[50])
{
	static int funcao[2];
	int m, n;
	
	for(m=0; string[m]!= '\0'; m++)
	{
		if(string[m]== ' ')
		{
			n++;
		}	
	}
	
	m =m - n;
	n = n+1;
	
	funcao[0] = m;
	funcao[1] = n;
	
	return funcao;
}


