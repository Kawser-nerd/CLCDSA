#include <stdio.h>
#include <math.h>

int max(int x, int y){return(x>y?x:y);} 
int min(int x,int y){return(x>y?y:x);}

int main(){
	int K,k,test,Test,N,n,i,j;
	FILE *file1,*file2;
	double s[1000],t[1000],r[1000],h[1000],tmpt[1000];
	double maxst=0;
	int maxsti,maxti;
	double maxt;
	double ans;
	double pi=3.1415926536,tmp;	

	
	file1=fopen("A-large.in","r");
	file2=fopen("A-large.out","w");
	fscanf(file1,"%d",&Test);
	for (test=1;test<=Test;test++){
	    fscanf(file1,"%d %d",&N,&K);
	    maxst=0;
        for (i=0;i<N;i++){
        	fscanf(file1,"%lf %lf",&r[i],&h[i]);
        	s[i]=r[i]*r[i];
        	t[i]=2*r[i]*h[i];
//        	if ((s[i]+t[i])>maxst) {
//        		maxst=s[i]+t[i];
//        		maxsti=i;
//			}
//			s[i]=i;
		}
//		printf("test%d\n %d\n",test,maxsti);
//		s[maxsti]=0;t[maxsti]=0;
		for (i=0;i<N;i++){
			for (j=i+1;j<N;j++){
				if (r[i]<r[j]) {
					tmp=t[i];t[i]=t[j];t[j]=tmp;
					tmp=s[i];s[i]=s[j];s[j]=tmp;
					tmp=r[i];r[i]=r[j];r[j]=tmp;
					tmp=h[i];h[i]=h[j];h[j]=tmp;
				}
			}
		}
//		ans=maxst;
        maxst=0;
		for (i=0;i<=N-K;i++){
			ans = s[i]+t[i];
			for (j=0;j<N;j++) tmpt[j]=t[j];
//			printf("%d %lf\n",i,ans);
			for (k=0;k<K-1;k++){
				maxt=0;
				for (j=i+1;j<N;j++)
					if (tmpt[j]>maxt) {
						maxt=tmpt[j];
						maxti=j;
					}
				ans+=maxt;
				tmpt[maxti]=0;
//				printf("%d %lf",maxti,maxt);
			}
//			printf("\n%lf\n\n",ans);
			if (ans>maxst) maxst=ans;
	    }
			
//			ans+=t[i];
//			printf("%.0f ",s[i]);
	    fprintf(file2,"Case #%d: ",test);
		fprintf(file2,"%.9lf",maxst*pi);
	    fprintf(file2,"\n");
    }
	fclose(file1);
    fclose(file2);  
}
