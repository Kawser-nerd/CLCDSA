#include <stdio.h>
#define MAXN 1000

int main(int argc, char *argv[]){
    FILE *fin,*fout;
    int tcase,T,N,counter,i,j,A[MAXN],B[MAXN];
    
    if (argc>1)
       fin=fopen(argv[1],"r");
    else
       fin=fopen("rope.in","r");
    if (!fin)
       return 1;
    if (argc>2)
       fout=fopen(argv[2],"w");
    else
       fout=fopen("rope.out","w");
    if (!fout){
       fclose(fin);
       return 1;
 	   }
    fscanf(fin,"%d",&T);
    for (tcase=1;tcase<=T;tcase++)
    {
       fscanf(fin,"%d",&N);
	   for(i=0;i<N;i++)
	   {
		   fscanf(fin,"%d",A+i);
		   fscanf(fin,"%d",B+i);
	   }
	   counter = 0;
	   for(i=0;i<N;i++)
	   {
		   for(j=i+1;j<N;j++)
		   {
			   if((A[i]>A[j] && B[i]<B[j]) || (A[i]<A[j] && B[i]>B[j]))
				   counter++;
		   }
	   }
       fprintf(fout,"Case #%d: %d\r\n",tcase,counter);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
