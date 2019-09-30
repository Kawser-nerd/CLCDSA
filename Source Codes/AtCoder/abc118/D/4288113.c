#include<stdio.h>
#include<stdlib.h>

int compare_char(const void *a, const void *b){
    return *(char*)a - *(char*)b;
}

int nextInt();
char nextChar();
int maxa(int a, int b){return a<b?b:a;}

int N, M, L, max, now, i, j;
int dp[10011];
char A[9];
char d[] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main(){
	N=nextInt();
	M=nextInt();
	for(i=0; i<M; i++){
		A[i]=nextChar();
	}
    qsort(A, M, sizeof(char), compare_char);
	dp[10] = 1;
	for(i=10, L=N+10; i<=L; i++){
		max = 0;
		for(j=0; j<M; j++){
			max = maxa(max, dp[i-d[A[j]]]);
		}
		if(max!=0){
			dp[i] = max+1;
		}
	}
	now = N+10;
	for(i=dp[N+10]-1; i>=1; i--){
		for(j=M-1; j>=0; j--){
			if(dp[now-d[A[j]]] == i){
				putchar('0'+A[j]);
				now -= d[A[j]];
				break;
			}
		}
	}
	putchar(10);
	return 0;
}

int nextInt(){
	int f=0; char c=getchar();
	while((c<'0')||('9'<c)){c=getchar();}
	while((c>='0')&&(c<='9')){f=f*10+(c-'0'); c=getchar();}
	return f;
}
char nextChar(){
	char f=0; char c=getchar();
	while((c<'0')||('9'<c)){c=getchar();}
	while((c>='0')&&(c<='9')){f=f*10+(c-'0'); c=getchar();}
	return f;
}