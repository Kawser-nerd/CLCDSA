#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<((int)(n));i++)
#define reg(i,a,b) for(int i=((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i=((int)(n))-1;i>=0;i--)
#define ireg(i,a,b) for(int i=((int)(b));i>=((int)(a));i--)
typedef long long int lli;
typedef pair<int,int> mp;
#define fir first
#define sec second
#define IINF INT_MAX
#define LINF LLONG_MAX
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define pque(type) priority_queue<type,vector<type>,greater<type> >
#define memst(a,b) memset(a,b,sizeof(a))

int n;
int dat[405][405];

int det(){
	
	int res=1;
	rep(x,n){
		int p = -1;
		reg(y,x,n-1){
			if(dat[y][x]!=0){
				p=y;
				break;
			}
		}
		if(p==-1)return 0;
		
		reg(i,x,n-1)swap(dat[x][i],dat[p][i]);

		reg(y,x+1,n-1){
			if(dat[y][x]==0)continue;
			reg(i,x,n-1){
				dat[y][i] += dat[x][i];
				dat[y][i]%=2;
			}
		}
	}
	
	//printf("%d\n",res);
	return res;
}


char s[405][405];

int main(void){
	scanf("%d",&n);
	rep(i,n)scanf("%s",s[i]);
	rep(y,n)rep(x,n){
		dat[y][x]=(s[y][x]-'0');
	}
	//if(n<=100)return -1;
	printf("%s\n",(det()%2==0)?"Even":"Odd");
	return 0;
}