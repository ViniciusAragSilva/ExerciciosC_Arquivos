/*================================================================*?
EXERCICIO 2 - LISTA DE ARQUIVOS DE VINICIUS ARAGAO 4323
-------------------------------------------------------------------
Solicite ao usuario uma palavra ou frase que será armazenada em
 uma string. Escrever em arquivo formato texto as seguintes informações:
a) A string original
b) A string invertida;
c) A string toda em caracteres maiúsculos
d) A string toda em caracteres minusculos
e) Se houver mais de uma palavra na string, escrever uma palavra por linha.
f) A quantidade de caracteres da string.
Cada um dos itens deve estar separado por uma linha em branco
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
	char InverteStr(char palavra[50]);																	// Funcao pra inverter a string
	char MaiuscStr(char palavra[50]);																	// Funcao para deixar a string MAIUSCULA
	char MinuscStr(char palavra[50]);																	// Funcao pra deixar a string minuscula
	char NovaLinha(char palavra[50]);																	// Funcao que bota nova linha a cada espaco
	
	char palavra[50], palavraO[50]={};																	// string <palavraO> vai ser usada pra botar nova linha depois de <palavra> ficar toda em minusculo
	int i;																								// variavel de controle

	//////////////////////////////////////APRESENTANDO A FUNÇAO/////////////////////////////
	printf("===========================================================================\n");
	printf("\n\t\t\t\t EXERCICIO 2\n");
	printf("\n\t * Esse programa pede uma string pro usuário (até 50 caracteres)\n");
	printf("\n\t * E fornece várias informações listadas a seguir\n");
	printf("===========================================================================\n");
	////////////////////////////////////ATRIBUINDO VALORES/////////////////////////////////

	fp = fopen("ListaArquivos2.txt","wt");																// abrindo o arquivo na funcao de escrever texto
	fputs("==========================================\n", fp);
	fputs("\n\t\t EXERCICIO 2 - Vinicius Aragão\n", fp);
	fputs("==========================================\n", fp);

	printf("\n a) Coloque a string original: ");
	
////////////////////////////////////////////LETRA A////////////////////////////////////////////////////
		
	fputs("\n a) A string original: \n",fp);

	gets(palavra);
	
	for(i=0; palavra[i]!= '\0'; i++)
    {
    	palavraO[i] = palavra[i];
    }
														
	fputs(palavra,fp);															// <fputs> pega a string <ch> e bota ela ao fluxo previamente aberto <fp>
	putc('\n',fp);															// bota um \n, que seria uma nova linha, apos apertar ENTER pra terminar o <fputs>															
	
////////////////////////////////////////////LETRA B////////////////////////////////////////////////////

	fputs("\n b) A string invertida:\n", fp);
		
	InverteStr(palavra);
 
    fputs(palavra,fp);
	putc('\n',fp);
	printf("\n b) A string invertida: %s \n", palavra);
	
////////////////////////////////////////////LETRA C////////////////////////////////////////////////////

	InverteStr(palavra);
	
	fputs("\n c) A string toda em caracteres maiúsculos:\n",fp);
	
	MaiuscStr(palavra);
	
	fputs(palavra,fp);
	putc('\n',fp);
	printf("\n c) A string MAIUSCULA: %s \n", palavra);
	
////////////////////////////////////////////LETRA D////////////////////////////////////////////////////	
	
	fputs("\n d) A string toda em caracteres minusculos:\n",fp);
	
	MinuscStr(palavra);

	fputs(palavra,fp);
	putc('\n',fp);
	printf("\n d) A string minuscula: %s \n", palavra);
	


////////////////////////////////////////////LETRA E////////////////////////////////////////////////////	

	fputs("\n e) Se houver mais de uma palavra na string, escrever uma palavra por linha.\n",fp);
	
	NovaLinha(palavraO);

	fputs(palavraO,fp);
	putc('\n',fp);
	printf("\n e) A string separada: %s \n", palavraO);

////////////////////////////////////////////LETRA F////////////////////////////////////////////////////	

	fputs("\n f) A quantidade de caracteres da string:\n",fp);
	
	i = strlen(palavra);
    
	fprintf(fp,"%d", i);
	putc('\n',fp);
	printf("\n f) A quantidade de caracteres da string: %d \n", i);	
	
	fclose(fp);
}



/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/
/*																											*/
/*											FUNCOES EXTERNAS												*/
/*																											*/
/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/


char InverteStr(char palavra[50])
{
	int t, t2;
	char temp;
	
	t= strlen(palavra)-1;											// o tamanho da string digitada (limite de 50) menos 1
	t2=0;															// zera t2
		
	while(t2 < t)													// enquanto t2 for menor que t:
    {
    	temp = palavra[t2];											// temp vira o valor da palavra em t2 (inicialmente zero)
		palavra[t2] = palavra[t];									// a posicao t2 (inicio 0) é igual a posicao t (inicio ultima posicao)
		palavra[t]=temp;											// a posicao t (ultima posicao no inicio) é igual a temp (valor em t2)
		t--;														
    	t2++;
    }
    return palavra;
}

////////////////////////////////////////////LETRA C////////////////////////////////////////////////////	

char MaiuscStr(char palavra[50])
{
	int i;
	
	for(i=0; palavra[i]!= '\0'; i++)								// for que roda até o final da string
    {
        if(palavra[i]>= 97 && palavra[i]<= 122)						// se ela estiver entre os valores ASCII das letras minusculas
        {
            palavra[i] = palavra[i]  - 32;							// diminui 32, pois é a equivalencia maiuscula - minuscula em ASCII
        }
    }
    
    return palavra;
}

////////////////////////////////////////////LETRA D////////////////////////////////////////////////////	

char MinuscStr(char palavra[50])
{
	int i;
	
	for(i=0; palavra[i]!= '\0'; i++)
    {
        if(palavra[i]>= 65 && palavra[i]<= 90)
        {
            palavra[i] = palavra[i]  + 32;
        }
    }
    
    return palavra;
}

////////////////////////////////////////////LETRA E////////////////////////////////////////////////////	

char NovaLinha(char palavra[50])
{
	int i;
	
	for(i=0; palavra[i]!= '\0'; i++)								
    { 
        if(palavra[i]== ' ')										// se a posicao for um espaco
        {	
        	palavra[i] = '\n';										// substitui por um \n, ou um enter
        }
    }
    
    return palavra;
}


