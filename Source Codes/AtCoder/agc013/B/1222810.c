#include<stdio.h>
#include<stdlib.h>
int f[100000];
typedef struct{
	long a;
	long b;
} ver;
ver v[200000];
long c[100000],s[100000],e[100000];

int cmp(const void *a,const void *b){
	return ((ver *)a)->a-((ver *)b)->a;
}

int main(int argc, char const *argv[]){
	long n,m,a,b,sn=1,en=0,i;
	scanf("%ld %ld",&n,&m);
	for(i=0;i<m;i++){
		scanf("%ld %ld",&a,&b);
		v[i*2].a=a;
		v[i*2].b=b;
		v[i*2+1].a=b;
		v[i*2+1].b=a;
		c[a-1]++;
		c[b-1]++;
	}
	qsort(v,m*2,sizeof(ver),cmp);
	for(i=1;i<n;i++){
		c[i]+=c[i-1];
	}
	s[0]=1;
	b=v[0].b;
	f[0]=1;
	while(1){
		s[sn]=b;
		sn++;
		f[b-1]=1;
		for(i=c[b-2];i<c[b-1];i++){
			if(v[i].a==b && f[v[i].b-1]==0) break;
		}
		if(i>=c[b-1]) break;
		b=v[i].b;
	}
	for(i=1;i<c[0];i++){
		if(f[v[i].b-1]==0) break;
	}
	if(i<c[0]){
		b=v[i].b;
		while(1){
			e[en]=b;
			en++;
			f[b-1]=1;
			for(i=c[b-2];i<c[b-1];i++){
				if(v[i].a==b && f[v[i].b-1]==0) break;
			}
			if(i>=c[b-1]) break;
			b=v[i].b;
		}
	}
	printf("%ld\n",sn+en);
	a=0;
	for(i=en;i>0;i--){
		if(a==1) printf(" ");
		else a=1;
		printf("%ld",e[i-1]);
	}
	for(i=0;i<sn;i++){
		if(a==1) printf(" ");
		else a=1;
		printf("%ld",s[i]);
	}
	printf("\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld %ld",&n,&m);
  ^
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld %ld",&a,&b);
   ^