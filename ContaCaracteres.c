/*================================================================*?
EXERCICIO X - LISTA DE X DE VINICIUS ARAGAO 4323
-------------------------------------------------------------------
  

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
int CtAlfbt[26]={};

/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/
/*																											*/
/*											MAIN															*/
/*																											*/
/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/


int main()
{
	////////////////////////////////////CRIANDO VARIAVEIS/////////////////////////////////////

	setlocale (LC_ALL,"");
	srand(time(NULL));
	FILE *fp;
	int ContaLetras(char string[50]);

	int repetidas[26];
	int i;
	
	char nome[20], string[50];

/////////////////////////////////////////////////APRESENTANDO A FUN�AO/////////////////////////////
	printf("===========================================================================\n");
	printf("\n\t\t\t EXERCICIO 5 \n");
	printf("\n\t * Esse programa pede um conteudo de um arquivo \n");
	printf("\n\t * E faz v�rias funcoes listadas a seguir\n");
	printf("===========================================================================\n");
///////////////////////////////////////////PEDINDO O NOME DO ARQUIVO///////////////////////////////////////////////////

	
	
////////////////////////////////////PEDINDO CONTEUDO PRO ARQUIVO/////////////////////////////////////////////////////////

	printf("\n Coloque palavras no arquivo (at� 50 caract.): \n");
	printf("\n--------------------------------------------\n\n");
	gets(string);
	fflush(stdin);
	printf("\n--------------------------------------------\n\n");
	
/*	fputs("\n Palavras escritas: \n \" ",fp);
	fputs(string,fp);
	fputs("\" ",fp);
*/	
	ContaLetras(string);
	
	//////////////////////////////////////LENDO OS CARACTERES REPETIDOS/////////////////////////////////
	for(i= 0; i<26; i++)
	{
		if(CtAlfbt[i]!= 0)
		{
			printf("\n O caractere %c aparece %d, vezes\n", (i+'A'), CtAlfbt[i]);
		}
	}
	//
	
///////////////////////////////////////////FECHANDO ARQUIVO///////////////////////////////////////////////////

//	fclose(fp);	
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
			temp = string[i] - 'A';											//se string[i] tiver A dentro, vai ser 0, que � a primeira posi��o da string
			CtAlfbt[temp]++;												// soma na posi��o <temp> da string +1, lembrando que a posi��o temp esta de acordo com o alfabeto	
		}
		else if(string[i]>= 'a' && string[i]<= 'z')
		{
			temp = string[i] - 'a';											//se string[i] tiver A dentro, vai ser 0, que � a primeira posi��o da string
			CtAlfbt[temp]++;													// soma na posi��o <temp> da string +1, lembrando que a posi��o temp esta de acordo com o alfabeto	
		}
	}
	
	return (CtAlfbt);	
}

