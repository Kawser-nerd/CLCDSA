#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<map>
using namespace std;
typedef pair<int,int> PI;
typedef long long LL;
typedef double D;
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define R(I,N) for(int I=0;I<N;I++)
#define F(I,A,B) for(int I=A;I<B;I++)
#define FD(I,N) for(int I=N-1;I>=0;I--)
#define make(A) scanf("%d",&A)
#define MAX 52
int r,c,m;
char z[MAX];
void test(){
	static int nr = 0;nr++;
	printf("Case #%d:\n",nr);
	make(r);make(c);make(m);
	z[c] = 0;
	if(r == 1){
		R(i,c)z[i] = '.';
		R(i,m)z[i] = '*';
		z[c-1] = 'c';
		printf("%s\n",z);
		return;
	}
	if(c == 1){
		R(i,r)z[i] = '.';
		R(i,m)z[i] = '*';
		z[r-1] = 'c';
		R(i,r)printf("%c\n",z[i]);
		puts("");
		return;
	}
	m = r*c - m;
	if(m == 1){
		R(i,c)z[i] = '*';
		R(i,r-1)printf("%s\n",z);
		z[0] = 'c';
		printf("%s\n",z);
		return;
	}
	F(i,1,c)F(j,1,r){
		if(m >= 2*(i+j) && m <= (i+1)*(j+1)){
			R(k,c)z[k] = (k<=i?'.':'*');
			z[0]='c';
			printf("%s\n",z);
			z[0]='.';
			printf("%s\n",z);
			m -= 2*(i+j);
			F(k,2,j+1){
				F(l,2,i+1){
					if(m){
						z[l] = '.';
						m--;
					}else
						z[l] = '*';
				}
				printf("%s\n",z);
			}
			R(k,c)z[k] = '*';
			R(_,r-j-1)printf("%s\n",z);
			return;
		}
	}
	printf("Impossible\n");
}
main(){
	int t;make(t);while(t--)test();
}
