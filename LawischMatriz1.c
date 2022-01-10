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
int main(void)
{
FILE *fp;
float exemplo[10][10];
int i,j;

fp=fopen("teste.dat","wb");
for(i=0; i<10; i++)
{
for(j=0; j<10; j++)
{
exemplo[i][j] = (float) i+j;
}
}
fwrite(exemplo, sizeof(exemplo), 1, fp);
fclose(fp);
getch();

fp=fopen("teste.dat","rb");
fread(exemplo,sizeof(exemplo), 1, fp);
for(i=0; i<10; i++)
{
for(j=0; j<10; j++)
printf("%5.1f ", exemplo[i][j]);
printf("\n\n");
}
fclose(fp);
getch();


}


