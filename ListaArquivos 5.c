/*================================================================*?
EXERCICIO 5 - LISTA DE ARQUIVOS DE VINICIUS ARAGAO 4323
-------------------------------------------------------------------
5. O programa deve abrir um arquivo no formato texto selecionado
 pelo usuário. A seguir :
a. Contabilizar a ocorrência de cada letra (não considerar 
diferenças de maiusculas/minusculas) e digito presente no 
arquivo. Não considerar espaço ou caracteres de pontuação. 
(contar quantas letras a, quantas letras b, etc…)

b. Abrir um arquivo  formato texto com nome identico ao 
original, acrescentado de “rpt_” no inicio.

c. Escrever neste arquivo o resultado da analise feita.
Organizar as informações em 3 colunas, na primeira o 
caracter (letra ou digito),  na segunda o numero de 
ocorrências em valor absoluto e na terceira o 
percentual de ocorrências em relação ao total.

d.Acrescente  ao  arquivo  informações que  entenderem  
como  necessárias  para  facilitar  a compreensão deste 
relatório.
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
/*											PRE CODIGO														*/
/*																											*/
/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/

int CtAlfbt[26]={};													// string global pra ser usada na funcao e na main

/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/
/*																											*/
/*											MAIN															*/
/*																											*/
/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/


int main()
{
/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/
/*																											*/
/*											PARTE 1															*/
/*																											*/
/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/
	////////////////////////////////////CRIANDO VARIAVEIS/////////////////////////////////////

	setlocale (LC_ALL,"");
	srand(time(NULL));
	FILE *fp, *fg;																				// fp eh o arquivo normal, o fg eh o do relatorio 
	int ContaLetras(char string[50]);															// funcao que conta repeticao de letras

	int i;																								
	float pct, j;
	char string[50];																			// string com o conteudo pra ver a repeticao
	char nome[20], nome2[26]= "rpt_";															// nome = nome do arquivo normal, nome2 = nome do arquivo relatorio

/////////////////////////////////////////////////APRESENTANDO A FUNÇAO - CONSOLE/////////////////////////////
	printf("===========================================================================\n");
	printf("\n\t\t\t EXERCICIO 5 \n");
	printf("\n\t * Esse programa pede um conteudo de um arquivo \n");
	printf("\n\t * E faz várias funcoes listadas a seguir\n");
	printf("===========================================================================\n");
///////////////////////////////////////////APRESENTANDO E DANDO NOME A FUNCAO - ARQUIVO///////////////////////////////////////////////////

	printf("\n Digite o nome do arquivo (até 15 caracteres): ");
	gets(nome);	
	fflush(stdin);
	
	strcat(nome, ".txt");
	
	fp = fopen(nome,"wt");															
	fputs("==========================================\n", fp);
	fputs("\n\t\t EXERCICIO 5 - Vinicius Aragão\n", fp);
	fputs("==========================================\n", fp);

////////////////////////////////////PEDINDO CONTEUDO PRO ARQUIVO/////////////////////////////////////////////////////////

	printf("\n Coloque palavras no arquivo (até 50 caract.): \n");
	printf("\n--------------------------------------------\n\n");
	gets(string);
	fflush(stdin);
	printf("\n--------------------------------------------\n\n");
	
////////////////////////////////////INSERINDO O CONTEUDO DADO NO ARQUIVO////////////////////////////////////////////////	
	
	fputs("\n REPETICAO DE CARACTERES: Parte 1 \n ",fp);
	fputs("\n Será contada a ocorrencia de chars na seguinte string: \n \" ",fp);
	fputs(string,fp);
	fputs("\" ",fp);
	
	fclose(fp);
/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/
/*																											*/
/*											PARTE 2															*/
/*																											*/
/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/

	strcat(nome2, nome);
	fg = fopen(nome2,"wt");
	
	fputs("\n REPETICAO DE CARACTERES: Parte 2 \n ",fg);
	fputs("\n Como dito na parte 1, a contagem a seguir de:  \n  \" ",fg);
	fputs(string,fg);
	fputs("\" \n",fg);
	
	ContaLetras(string);
	
	//////////////////////////////////////LENDO OS CARACTERES REPETIDOS/////////////////////////////////
	
	fprintf(fg,"\n | CARACTERE |		| NUM REPT |			| % REPT |");
	
	j = strlen(string);
	
///////////////////////////////////////ESCREVENDO NO ARQUIVO RPT_////////////////////////////////////////	
	
	for(i= 0; i<26; i++)
	{
		if(CtAlfbt[i]!= 0)
		{	
			pct = 100*(CtAlfbt[i]/j);
			printf("\n O caractere %c aparece %d, vezes, porcentagem de %.2f \n", (i+'A'), CtAlfbt[i], pct);
			
			fprintf(fg,"\n %c				%d			%.2f \n", (i+'A'), CtAlfbt[i], pct);
		}
	}
	
	fclose(fg);
	getch();
	
}

/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/
/*																											*/
/*											FUNCOES EXTERNAS												*/
/*																											*/
/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/
 int ContaLetras(char string[50])
{
	int i, temp;
	
	for(i=0; i<strlen(string); i++)
	{
		if(string[i]>= 'A' && string[i]<= 'Z')
		{
			temp = string[i] - 'A';											//se string[i] tiver A dentro, vai ser 0, que é a primeira posição da string
			CtAlfbt[temp]++;												// soma na posição <temp> da string +1, lembrando que a posição temp esta de acordo com o alfabeto	
		}
		else if(string[i]>= 'a' && string[i]<= 'z')
		{
			temp = string[i] - 'a';											//se string[i] tiver A dentro, vai ser 0, que é a primeira posição da string
			CtAlfbt[temp]++;													// soma na posição <temp> da string +1, lembrando que a posição temp esta de acordo com o alfabeto	
		}
	}
	
	return (CtAlfbt);	
}
	
