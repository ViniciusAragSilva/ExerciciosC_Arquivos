/*================================================================*?
EXERCICIO 1 - LISTA DE ARQUIVOS DE VINICIUS ARAGAO 4323
-------------------------------------------------------------------
1. O programa deve armazenar em arquivo no formato texto as
 palavras digitadas pelo usu�rio. O usuario entra com uma palavra 
 por vez.  O programa � encerrado ao entrar com a palavra �telos�, 
 sem que esta seja gravada em arquivo. A escolha do nome pelo
usu�rio � opcional. N�o esque�a de fechar o arquivo.

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
	////////////////////////////////////CRIANDO VARIAVEIS/////////////////////////////////////

	setlocale (LC_ALL,"");
	srand(time(NULL));
	FILE *fp;
	
	char nome[20], ch[20];											// string pro nome, e string pra cada palavra
	char telos[5] = {"telos"};										// � necessario uma string pra palavra de controle
	
	//////////////////////////////////////APRESENTANDO A FUN�AO/////////////////////////////
	
	printf("===========================================================================\n");
	printf("\n\t\t\t EXERCICIO 1 \n");
	printf("\n\t * Esse programa grava uma palavra por vez do usuario em um arquivo \n");
	printf("\n\t * At� que a palavra <telos> seja digitada\n");
	printf("===========================================================================\n");
	
	////////////////////////////////////ATRIBUINDO VALORES/////////////////////////////////

	printf("\n Digite o nome do arquivo (at� 15 caracteres): ");
	gets(nome);	
	fflush(stdin);
	strcat(nome, ".txt");
	
	fp=fopen(nome,"wt");
	printf("\n Grave as palavras(at� 20 caracteres por palavra) at� escrever <telos>: \n");
	
	do
	{
		gets(ch);																					// gets, pega a string atraves do console e bota na string ch
        if(strcmp(ch,telos))																		// compara��o de ch com telos, s� dar� zero se for igual
        {
        	fputs(ch,fp);																			// fun��o que coloca o <ch> em <fp>, lembrando que apos cada <enter> � um <ch> diferente
        	putc('\n',fp);																			// bota um \n no arquivo pra ficar mais organizado
		}
		fflush(stdin);
		
    }while(strcmp(ch,telos));																		// fazer isso acima enquanto a compara��o de <telos> e <ch> n�o for zero (os dois iguais)  
    ch[0]= '\0';																					// limpando a string pra nao aparecer o telos na leitura do conteudo (abaixo disso a leitura)
    
    fclose(fp);
   
    printf("\n\n-----------Conteudo do arquivo----------------\n\n");
    
    fp=fopen(nome,"rt");																			// abrindo de novo, dessa vez para leitura
	while(!feof(fp))																				// enquanto o fim do arquivo de <fp> negado (quando n�o t� no fim � 0, dai nega isso pro while ficar funcionando)
	{
		puts(ch);																					// put string, coloca a <ch> do momento na tela do console
        fgets(ch,20,fp);																			// pega o conteudo de <fp> de at� 20 valores (antes de um enter) e bota em <ch>
		fflush(stdin);
    }

	fclose(fp);
}


