#include <stdio.h>
#include <math.h>

int max(int x, int y){return(x>y?x:y);} 
int min(int x,int y){return(x>y?y:x);}

int main(){
	int K,k,test,Test,N,n,i,j;
	FILE *file1,*file2;
	double T;
	double t[50],tmpt[50],ans,midp,minp,maxp,mint;

	
	file1=fopen("C-small-1-attempt0.in","r");
	file2=fopen("C-small-1-attempt0.out","w");
	fscanf(file1,"%d",&Test);
	for (test=1;test<=Test;test++){
	    fscanf(file1,"%d %d",&N,&K);
	    fscanf(file1,"%lf",&T);
        for (i=0;i<N;i++){
        	fscanf(file1,"%lf",&t[i]);
		}
        minp=0;maxp=1;
		while (1){
			mint=T;
			for (j=0;j<N;j++) tmpt[j]=t[j];
			midp=(minp+maxp)/2;
			
			for (j=0;j<N;j++){
				if (midp>tmpt[j]){
					mint=mint+tmpt[j]-midp;
					tmpt[j]=midp;
				}
			}
			if (mint>1e-10) minp=midp;
			else if (mint<-1e-10) maxp=midp;
			else break;
		}
		ans=1;
		for (i=0;i<N;i++){
			ans*=tmpt[i];
	    }
	    fprintf(file2,"Case #%d: ",test);
		fprintf(file2,"%.6lf",ans);
	    fprintf(file2,"\n");
    }
	fclose(file1);
    fclose(file2);  
}
