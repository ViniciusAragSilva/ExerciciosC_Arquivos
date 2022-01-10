/*================================================================*?
EXERCICIO 3 - LISTA DE ARQUIVOS DE VINICIUS ARAGAO 4323
-------------------------------------------------------------------
 3. O usuário escolhe um nome de arquivo, que obrigatoriamente
estara no formato texto. O programa abre este arquivo e
exibe seu conteudo na tela.


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
	FILE *fo;
	char nome[20];
	char nome_rpt[25];
	char exemplo[50]={};
	int i=0;
	int space=0;
    int ContaEspaco(char palavra[50]);
	
	printf("===========================================================================\n");
	printf("\n\t\t\t EXERCICIO 3 \n");
	printf("\n\t * Esse programa grava uma matriz binaria no arquivo texto\n");
	printf("\n\t * cujo nome é informado pelo usuario\n");
	printf("===========================================================================\n");
	
	////////////////////////////////////ATRIBUINDO VALORES/////////////////////////////////

	printf("\n Digite o nome do arquivo (até 15 caracteres): ");
	gets(nome);	
	strcpy(nome_rpt,nome);
	fflush(stdin);
	strcat(nome, ".txt");
	strcat(nome_rpt, "_rept.txt");

	fp=fopen(nome,"rb");
	fo=fopen(nome_rpt,"wt");
	fread(&exemplo,sizeof(char), 100, fp);
    printf("\n %s \n", exemplo);
   
	fputs("==========================================\n", fo);
	fputs("\n\t\t EXERCICIO TAL - PATRON\n", fo);
	fputs("==========================================\n", fo);
	
	 ////////////////////////////////////QTD DE CARACTERES/////////////////////////////////
	 
	fputs("\n f) A quantidade de caracteres do arquivo:\n",fo);
	
	i = strlen(exemplo);
    
	fprintf(fo,"%d", i);
	putc('\n',fo);
	printf("\n A quantidade de caracteres do arquivo: %d \n", i);
	
	 ////////////////////////////////////CONTA ESPACOS/////////////////////////////////
    fputs("\n f) A quantidade de espacos do arquivo:\n",fo);
    
	space= ContaEspaco(exemplo);
	
	fprintf(fo,"%d", i);
	putc('\n',fo);
	printf("\n A quantidade de espaços do arquivo: %d \n", space);
	
	fclose(fp);
	fclose(fo);
	getch();

}

int ContaEspaco(char palavra[50])
{
	int i, espacos=0;
	
	for(i=0; palavra[i]!= '\0'; i++)								
    { 
        if(palavra[i]== ' ')										// se a posicao for um espaco
        {	
        	espacos++;										// substitui por um \n, ou um enter
        }
    }
    
    return espacos;
}

