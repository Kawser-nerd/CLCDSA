#include<stdio.h>
char c;
int f;
int nextInt();

int N, ans, i, t;
int a[100000];
char b[100000];
int main(){
	N=nextInt();
	for(i=0; i<N; i++){
		a[i]=nextInt();
	}
	i = 1;
	ans = 1;
	while(1){
		t = a[i-1];
		if(t==2){break;}
		if(b[t-1]){break;}
		b[t-1] = 1;
		i = t;
		ans++;
	}
	if(t==2){
		printf("%d\n", ans);
	}else{
		printf("-1\n");
	}
	return 0;
}

int nextInt(){
	f=0; c=getchar();
	while((c<'0')||('9'<c)){c=getchar();}
	while((c>='0')&&(c<='9')){f=f*10+(c-'0'); c=getchar();}
	return f;
}