#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <list>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
using namespace std;
#define pb push_back
#define all(v) v.begin(),v.end()
#define sz size()
#define rep(i,m) for(int i=0;i<m;i++)
#define rep2(i,x,m) for(int i=x;i<m;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef long long ll;
int oo = (int) 1e9;
int N;
int I,J;
int m[100][100];
map<pii,int> mm;
int di[]={-1,0,0,1};
int dj[]={0,-1,1,0};
int same[100][100];
map<int,char> m2;
char ret[100][100];
int main() {
//#define SAMPLE
#ifndef SAMPLE
	freopen("B-large.in","rt",stdin);
	freopen("B-large.out","wt",stdout);
#endif
#ifdef SAMPLE
	freopen("a.txt", "rt", stdin);
#endif
	cin>>N;
	rep(nn,N){
		cin>>I>>J;
		rep(i,I)
			rep(j,J)
				cin>>m[i][j];
		mm.clear();
		rep(i,I)rep(j,J){
			int ii=i,jj=j;
			while(1){
				int mn=oo;
				int kk;
				rep(k,4){
					int ni=ii+di[k];
					int nj=jj+dj[k];
					if(ni>=0 && nj>=0 && ni<I && nj<J && m[ni][nj]<m[ii][jj] && m[ni][nj]<mn){
						mn=m[ni][nj];
						kk=k;
					}
				}
				if(mn==oo)
					break;
				ii+=di[kk];
				jj+=dj[kk];
			}
			if(mm.count(mp(ii,jj)))
				same[i][j]=mm[mp(ii,jj)];
			else{
				same[i][j]=mm.sz;
				mm[mp(ii,jj)]=same[i][j];
			}
		}
		m2.clear();
		char cc='a';
		rep(i,I)
			rep(j,J){
				if(m2.count(same[i][j]))
					ret[i][j]=m2[same[i][j]];
				else{
					ret[i][j]=cc++;
					m2[same[i][j]]=ret[i][j];
				}
		}
		printf("Case #%d:\n",nn+1);
		rep(i,I){
			rep(j,J){
				if(j)
					printf(" ");
				printf("%c",ret[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
