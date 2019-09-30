#include <stdio.h>
#include <stdlib.h>
typedef struct pair{
	int a,b;
}PAIR;

int comp(const void *_p,const void *_q){
	PAIR *p=(PAIR *)_p,*q=(PAIR *)_q;
	return q->b-p->b;
}

int main(){
	PAIR s[208];
	double r[208],tmp;
	int t,n,n2,k,sum=0,sum2,i;
	scanf("%d",&t);
	for(k=1;k<=t;k++){
		sum=0;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&s[i].b);
			sum+=s[i].b;
			s[i].a=i;
		}
		qsort(s,n,sizeof(PAIR),comp);
		tmp=sum*2.0/n;
		sum2=sum*2;
		n2=n;
		for(i=0;i<n;i++){
			if((double)s[i].b>tmp){
				r[s[i].a]=0;sum2-=s[i].b;n2--;
			}else{
				tmp=sum2*1.0/n2;
				r[s[i].a]=(tmp-s[i].b)*100.0/sum;
			}
		}
		printf("Case #%d: ",k);
		for(i=0;i<n;i++){
			printf("%.6lf%c",r[i],(i==n-1)?'\n':' ');
		}
	}
	return 0;
}
