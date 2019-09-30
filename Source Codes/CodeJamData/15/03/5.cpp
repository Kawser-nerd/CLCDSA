#include<cstdio>
#include<cassert>
#include<algorithm>

using namespace std;

int table[5][5]={
{0,0,0,0,0},
{0,1,2,3,4},
{0,2,-1,4,-3},
{0,3,-4,-1,2},
{0,4,3,-2,-1}};

long long min(int x,long long y){
	return min((long long)x,y);
}

int mul(int x,int y){
	int a=0;
	if(x<0){
		x=-x;
		a^=1;
	}
	if(y<0){
		y=-y;
		a^=1;
	}
	int res=table[x][y];
	if(a==1) res*=-1;
	return res;
}

int a[10100];
int L;
long long X;
int right[10100];
int left[10100];
char ch[10100];

bool solve(){
	for(int i=0;i<L;i++){
		if(ch[i]=='i') a[i]=2;
		else if(ch[i]=='j') a[i]=3;
		else a[i]=4;
	}
	left[0]=a[0];
	for(int i=1;i<L;i++) left[i]=mul(left[i-1],a[i]);
	right[L-1]=a[L-1];
	for(int i=L-2;i>=0;i--) right[i]=mul(a[i],right[i+1]);
	assert(right[0]==left[L-1]);
	int all=left[L-1];
	if(all==1) return false;
	else if(all==-1&&(X%2==0)) return false;
	else if((all!=1&&all!=-1)&&(X%4!=2)) return false;
	long long m1=0,m2=0;
	int coe=1;
	for(int x=0;x<min(10,X);x++){
		for(int i=0;i<L;i++){
			if(mul(coe,left[i])==2){
				m1=(long long)x*L+(i+1);
				goto ed;
			}
		}
		coe=mul(coe,all);
	}
	ed:;
	coe=1;
	for(int x=0;x<min(10,X);x++){
		for(int i=L-1;i>=0;i--){
			if(mul(right[i],coe)==4){
				m2=(long long)x*L+(L-i);
				goto ed2;
			}
		}
		coe=mul(all,coe);
	}
	ed2:;
	if(m1==0||m2==0) return false;
	long long tlen=(long long)X*L;
	if(tlen>m1+m2) return true;
	return false;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int datano=1;datano<=T;datano++){
		scanf("%d%lld",&L,&X);
		scanf("%s",ch);
		bool flg=solve();
		if(flg) printf("Case #%d: YES\n",datano);
		else printf("Case #%d: NO\n",datano);
	}
	return 0;
}
