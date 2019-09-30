#include<stdio.h>
#include<stdlib.h>

int cmp1( const void *a , const void *b ) 
{ 
	return *(__int64 *)b - *(__int64 *)a; 
}

/* 
P * K ¡Ý L 
0 ¡Ü The frequency of each letter ¡Ü 1 000 000 
Large dataset

1 ¡Ü N ¡Ü 100
1 ¡Ü P ¡Ü 1 000
1 ¡Ü K ¡Ü 1 000
1 ¡Ü L ¡Ü 1 000

*/
int main()
{
	int t,tn;
	int p,k,l;
	__int64 x[1001];
	__int64 re;
	int i,j,an;
	
	freopen("A-large.in.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	scanf("%d",&t);
	for(tn=0; tn<t;tn++) {
		scanf("%d%d%d",&p,&k,&l);	
		for(i=0;i<l;i++) scanf("%I64d",&x[i]);
		qsort(x,l,sizeof(x[0]),cmp1);
		re = 0; i = 0; an = 1;
		while(i<l) {
			for(j = 0;j < k;j++) {
				re+=x[i]*an;
				i++;
				if(i>=l) break;
			}
			an++;
		}
		printf("Case #%d: %I64d\n",tn+1,re);		
	}
	return 0;
}