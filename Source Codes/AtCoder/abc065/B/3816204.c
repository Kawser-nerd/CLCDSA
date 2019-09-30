#include<stdio.h>
char c;
int f;
int nextInt();

int N, n, i, t;
int A[100001];
int main(){
	N=nextInt();
	for(i=1; i<=N; i++){
		A[i]=nextInt();
	}
	i=0;
	n=1;
	do{
		t = A[n];
		A[n] = 1;
		n = t;
		i++;
	}while(n!=1 && n!=2);
	if(n==2){
		printf("%d\n", i);
	}else{
		printf("-1\n");
	}
}

int nextInt(){
	f=0; c=getchar();
	while((c<'0')||('9'<c)){c=getchar();}
	while((c>='0')&&(c<='9')){f=f*10+(c-'0'); c=getchar();}
	return f;
}