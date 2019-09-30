#include<cstdio>
using namespace std;
const int N=100;
int n,m,tail;
char AA[N][N];
bool flag,IGN[N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%s",AA[tail]);
		flag=true;
		for(int j=0;j<m&&flag;++j)
			if(AA[tail][j]=='#')flag=false;
		if(!flag)++tail;
	}
	for(int j=0;j<m;++j){
		flag=true;
		for(int i=0;i<tail&&flag;++i)
			if(AA[i][j]=='#')flag=false;
		IGN[j]=flag;
	}
	for(int i=0;i<tail;++i){
		for(int j=0;j<m;++j)
			if(!IGN[j])printf("%c",AA[i][j]);
		printf("\n");
	}
}