#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BIT(a,n) ((a>>n)&1)
typedef struct pair_t{
	int x,y;
}PAIR;
PAIR p[1048578];

int comp(const void *_p,const void *_q){
	PAIR *p=(PAIR *)_p,*q=(PAIR *)_q;
	return p->x-q->x;
}

int main(){
	int s[24];
	int t,n,i,j,k,l,m,f,st;
	scanf("%d",&t);
	for(k=1;k<=t;k++){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&s[i]);
		}
		memset(p,0,sizeof(p));
		printf("Case #%d:\n",k);
		for(j=1;j<(1<<n);j++){
			for(i=0;i<n;i++)
				if(BIT(j,i))p[j-1].x+=s[i];
			p[j-1].y=j;
		}
		p[(1<<n)-1].x=10000000;
		qsort(p,(1<<n),sizeof(PAIR),comp);
		st=0;
		for(i=0;i<(1<<n)-1;){
			while(p[i].x==p[i+1].x)i++;
			i++;
			for(j=st;j<i;j++){
				for(l=j+1;l<i;l++){
					if(p[j].x==p[l].x&&!(p[j].y&p[l].y)){
						f=1;
						for(m=0;m<n;m++){
							if(BIT(p[j].y,m)){
								if(!f)putchar(' ');
								printf("%d",s[m]);
								f=0;
							}
						}
						puts("");
						f=1;
						for(m=0;m<n;m++){
							if(BIT(p[l].y,m)){
								if(!f)putchar(' ');
								printf("%d",s[m]);
								f=0;
							}
						}
						goto END;
					}
				}
			}
			st=i;
		}
		printf("Impossible");
		END:
		puts("");
	}
	return 0;
}
