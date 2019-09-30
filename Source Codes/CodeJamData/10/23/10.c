#include <stdio.h>
#include <stdlib.h>

void doTestCase();
void init();

int main(){
	int i,n;
	scanf("%d",&n);
	init();
	for (i=1;i<=n;i++){
		printf("Case #%d: ",i);
		doTestCase();
	}
	return 0;
}

#define MAXN 500
#define MOD 100003

int arrNo[MAXN+1][MAXN+1];
int combArr[MAXN+1][MAXN+1];
int inv[MOD];

void allInverses();
int comb(int a, int b);
int noWays(int n, int s);

void doTestCase(){
	int n;
	scanf("%d",&n);
	
	int i,s=0;
	for (i=1;i<n;i++){
		s+=noWays(n,i);
		s=s%MOD;
	}
	//printf("%d %d %d %d %d %d\n",noWays(2,1),noWays(3,1),noWays(3,2),noWays(4,1),noWays(4,2),noWays(4,3));
	//printf("%d\n",comb(5,2));
	printf("%d\n",s);
}

void init(){
	allInverses();
	int i,j;
	for (i=0;i<=MAXN;i++){
		for (j=0;j<=MAXN;j++){
			arrNo[i][j]=-1;
			combArr[i][j]=-1;
		}
	}
}

//inverses modulo MOD
void allInverses(){
	inv[0]=0;	//doesn't have one...
	
	int i=0;
	long long int n=2,invn;
	for (i=2;i<MOD;i++){
		if ((n*i)%MOD==1){
			inv[n]=i;
			inv[i]=n;
			break;
		}
	}
	
	invn=inv[2];
	long long int a=n,b=invn;
	do{
		a=(a*n)%MOD;
		b=(b*invn)%MOD;
		inv[a]=b;
		inv[b]=a;
	}while (a!=1);
}

//Combinations
int comb(int a, int b){
	if (a<b)
		return 0;
	if (b==0)
		return 1;
	if (a==b)
		return 1;
	if (combArr[a][b]!=-1)
		return combArr[a][b];
	long long res;
	res=a;
	res*=inv[b];
	res=res%MOD;
	res*=comb(a-1,b-1);
	res=res%MOD;
	combArr[a][b]=res;
	return (int) res;
}

int noWays(int n, int s){
	if (s==1)
		return 1;
	if (arrNo[n][s]!=-1)
		return arrNo[n][s];
	
	int i;
	long long t;
	long long res=0;
	for (i=1;i<s;i++){	// The number of ways for n and size of the set s, is equal to having the numbers of ways
						// for the number s and 1<=i<s size, and then choosing (s-k-1) numbers to fill the rest
						// of the set, from the numbers s<k<n (n-s-1 numbers) so we have as the result
						// sum of noWays(s,i)*comb(n-s-1,s-i-1) , 1<=i<s
		t=noWays(s,i);
		t*=comb(n-s-1,s-i-1);
		t=t%MOD;
		res+=t;
		res=res%MOD;
	}
	arrNo[n][s]=res;
	return res;
}
