#include<stdio.h>
#include<stdlib.h>
double b1[1000],b2[1000],b3[1000],b4[1000];
int u1[1000],u2[1000];

int dcmp(const void*a,const void*b){
	double c=*(double*)a,d=*(double*)b;
	if(c!=d)return c>d?1:-1;
	return 0;
}

void del(double*p,int k,int n){
	int a;
	for(a=k+1;a<n;a++){
		p[a-1]=p[a];
	}
}

int war(int n,double*x,double*y){
	int a,ret;
	ret=0;
	while(n--){
		for(a=n;y[a]>x[n]&&a>=0;a--);
		a++;
		if(a==n+1){
			ret++;
			a=0;
		}
		del(y,a,n+1);
	}
	return ret;
}

int deceit(int n,double*x,double*y){
	int a,ret;
	ret=0;
	for(a=0;a<n;a++){
		if(x[a]<y[0]){
			del(y,n-a-1,n-a);
		}
		else{
			ret++;
			del(y,0,n-a);
		}
	}
	return ret;
}

int main(int argc,char*argv[]){
	int a,t,t2,n;
	scanf("%d",&t2);
	for(t=1;t<=t2;t++){
		scanf("%d",&n);
		for(a=0;a<n;a++)scanf("%lf",b1+a);
		for(a=0;a<n;a++){
			scanf("%lf",b2+a);
			u1[a]=u2[a]=0;
		}
		qsort(b1,n,sizeof(double),dcmp);
		qsort(b2,n,sizeof(double),dcmp);
		for(a=0;a<n;a++){
			b3[a]=b1[a];
			b4[a]=b2[a];
		}
		printf("Case #%d: %d %d\n",t,deceit(n,b1,b2), war(n,b3,b4));
	}
	return 0;
}
