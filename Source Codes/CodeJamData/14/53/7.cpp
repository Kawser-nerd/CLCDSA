#include<bits/stdc++.h>
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
#define MAX 4000
int sn[MAX],sm[MAX];
vector<int> d[MAX],d2[MAX];
bool cz[MAX];
bool dfs(int nr){
	if(nr == -1)return 1;
	if(cz[nr]==1)return 0;
	cz[nr]=1;
	for(int i=0;i<d[nr].size();i++){
		if(dfs(sm[d[nr][i]])){
			sm[d[nr][i]]=nr;
			sn[nr]=d[nr][i];
			return 1;
		}
	}
	return 0;
}
int n;
char z[MAX];
int t[MAX];
set<int> s;
map<int,char> os;
int czzle[MAX];
void test(){
	static int test_nr = 0;test_nr++;
	printf("Case #%d: ",test_nr);
	int ilE = 0,iltr = 0;
	make(n);
	os.clear();
	R(i,n){
		d[i].clear();
		d2[i].clear();
		sn[i] = -1;
		sm[i] = -1;
		czzle[i] = 0;
		scanf(" %c%d",&z[i],&t[i]);
		if(z[i] == 'E')ilE ++;
		if(t[i] != 0){
			if(os[t[i]] == 0)
				czzle[i] = 2;
			if(os[t[i]] == z[i]){
				iltr++;
				czzle[i] = 1;
			}
			os[t[i]] = z[i];
		}
	}
//	printf("%d %d\n",ilE,iltr);
	R(i,n){
		if(z[i] == 'E'){
			if(t[i] == 0){
				int j = i;
				s.clear();
				while(j < n){
					if(z[j] == 'L'){
			//			printf("set %d %d\n",s.count(t[j]),t[j]);
						if(t[j] == 0 || !s.count(t[j])){
							s.insert(t[j]);
							if(czzle[j] == 1){
			//					printf("add: %d %d\n",i,j);
								d[i].PB(j);
							}else{
			//					printf("add2: %d %d\n",i,j);
								d2[i].PB(j);
							}
						}
					}
					j++;
				}
			}else{
				int j = i+1;
				while(j < n && t[j] != t[i])j++;
		//		printf("  %d\n",j);
				if(j == n || z[j] == 'E'){
		//			printf("%d %d\n",i,j);
					F(k,i,j){
						if(z[k] == 'L' && t[k] == 0){
							if(j!=n){
								d[i].PB(k);
		//						printf("add: %d %d\n",i,k);
							}else
								d2[i].PB(k);
						}
					}
				}else{
					d[i].PB(j);
					iltr ++;
					F(k,i,j){
						if(z[k] == 'L' && t[k] == 0)
							d2[i].PB(k);
					}
				}
			}
		}
	}
	bool x = 1;
	int sk = 0;
	while(x){
		x=0;
		R(i,n)cz[i]=0;
		R(i,n)if(sn[i]==-1)if(dfs(i)){
				x=1;
				sk++;
			}
	}
	if(sk != iltr){
		puts("CRIME TIME");
		return;
	}
	R(i,n)
		R(j,d2[i].size())
			d[i].PB(d2[i][j]);
	x=1;
	while(x){
		x=0;
		R(i,n)cz[i]=0;
		R(i,n)if(sn[i]==-1)if(dfs(i)){
				x=1;
				sk++;
			}
	}
	//puts("WYNIK\n");
	printf("%d\n",ilE - sk);
}
main(){
	int _;make(_);while(_--)test();
}
