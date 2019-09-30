#include <stdio.h>
#include <string.h>
#define MAXP 10
#define MAX_MATCHES (1<<MAXP)

int main(int argc, char *argv[]){
    FILE *fin,*fout;
    int tcase,T,counter,i,Mi,P,level,teams,price;
	char matches[MAX_MATCHES];
    
    if (argc>1)
       fin=fopen(argv[1],"r");
    else
       fin=fopen("wcup.in","r");
    if (!fin)
       return 1;
    if (argc>2)
       fout=fopen(argv[2],"w");
    else
       fout=fopen("wcup.out","w");
    if (!fout){
       fclose(fin);
       return 1;
 	   }
    fscanf(fin,"%d",&T);
    for (tcase=1;tcase<=T;tcase++)
    {
       fscanf(fin,"%d",&P);
	   memset(matches,0,sizeof(matches));
	   teams = 1<<P;
	   for(i=0;i<teams;i++)
	   {
		   fscanf(fin,"%d",&Mi);
		   for(level = 1; level <= P-Mi; level++)
		   {
			   matches[(1<<(level-1))-1+(i>>(P-level+1))]=1;
		   }
	   }
	   counter = 0;
	   for(i=0;i<teams-1;i++)
	   {
		   fscanf(fin,"%d",&price);
		   counter+=matches[i];
	   }
       fprintf(fout,"Case #%d: %d\r\n",tcase,counter);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
