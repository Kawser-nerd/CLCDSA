#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

#define modp(x) (((x)%P+P)%P)
#define mod(x,y) (((x)%(y)+(y))%(y))

int board[6262][6262];
int visited[6262][6262];
int vchk[6],echk[6];

int V,E,F;

int siz;

void saiki(int p,int q,int col){
	if(board[p][q]==0)return;
	if(visited[p][q]==col)return;
	visited[p][q]=col;
	if(p==1&&q==1)vchk[0]=1;
	if(p==siz&&q==1)vchk[1]=1;
	if(p==2*siz-1&&q==siz)vchk[2]=1;
	if(p==2*siz-1&&q==2*siz-1)vchk[3]=1;
	if(p==siz&&q==2*siz-1)vchk[4]=1;
	if(p==1&&q==siz)vchk[5]=1;
	if(p>1&&p<siz&&q==1)echk[0]=1;
	if(q>1&&q<siz&&p-q==siz-1)echk[1]=1;
	if(q>siz&&q<2*siz-1&&p==2*siz-1)echk[2]=1;
	if(p>siz&&p<2*siz-1&&q==2*siz-1)echk[3]=1;
	if(p>1&&p<siz&&q-p==siz-1)echk[4]=1;
	if(q>1&&q<siz&&p==1)echk[5]=1;
	V++;
	int dp[7]={-1,0,1,1,0,-1,-1};
	int dq[7]={-1,-1,0,1,1,0,-1};
	for(int d=0;d<6;d++){
		if(board[p+dp[d]][q+dq[d]]==1)E++;
		if(board[p+dp[d]][q+dq[d]]==1 && board[p+dp[d+1]][q+dq[d+1]]==1)F++;
	}
	
	for(int d=0;d<6;d++)saiki(p+dp[d],q+dq[d],col);
}

main(){
	int casenum,totcase;
	scanf("%d",&totcase);
	for(int casenum=1;casenum<=totcase;casenum++){
		int moves;
		scanf("%d%d",&siz,&moves);
		memset(board,0,sizeof(board));
		memset(visited,0,sizeof(visited));
		printf("Case #%d: ",casenum);
		bool done=false;
		for(int i=1;i<=moves;i++){
			int p,q;
			scanf("%d%d",&p,&q);
			if(done)continue;
			board[p][q]=1;
			memset(vchk,0,sizeof(vchk));
			memset(echk,0,sizeof(echk));
			V=0;E=0;F=0;
			saiki(p,q,i);
			E/=2;F/=3;
			bool bridge=false,fork=false,ring=false;
			if(V-E+F!=1)ring=true;
			if(echk[0]+echk[1]+echk[2]+echk[3]+echk[4]+echk[5]>=3)fork=true;
			if(vchk[0]+vchk[1]+vchk[2]+vchk[3]+vchk[4]+vchk[5]>=2)bridge=true;
			if(bridge||fork||ring){
				if(bridge&&!fork&&!ring)printf("bridge ");
				if(!bridge&&fork&&!ring)printf("fork ");
				if(!bridge&&!fork&&ring)printf("ring ");
				if(bridge&&fork&&!ring)printf("bridge-fork ");
				if(bridge&&!fork&&ring)printf("bridge-ring ");
				if(!bridge&&fork&&ring)printf("fork-ring ");
				if(bridge&&fork&&ring)printf("bridge-fork-ring ");
				printf("in move %d\n",i);
				done=true;
			}
		}
		if(!done)printf("none\n");
	}
}