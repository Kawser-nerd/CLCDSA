#include <stdio.h>

int main(int argc, char *argv[]){
    FILE *fin,*fout;
    int tcase,T,counter,res;
	unsigned long long L,P,C;
    
    if (argc>1)
       fin=fopen(argv[1],"r");
    else
       fin=fopen("load.in","r");
    if (!fin)
       return 1;
    if (argc>2)
       fout=fopen(argv[2],"w");
    else
       fout=fopen("load.out","w");
    if (!fout){
       fclose(fin);
       return 1;
 	   }
    fscanf(fin,"%d",&T);
    for (tcase=1;tcase<=T;tcase++)
    {
       fscanf(fin,"%llu",&L);
       fscanf(fin,"%llu",&P);
       fscanf(fin,"%llu",&C);
	   counter = 0;
	   L *= C;
	   while(L<P)
	   {
		   counter++;
		   L *= C;
	   }
	   res = 0;
	   while(counter > 0)
	   {
		   res++;
		   counter >>= 1;
	   }
       fprintf(fout,"Case #%d: %d\r\n",tcase,res);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
