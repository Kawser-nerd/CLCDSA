#include<iostream>
using namespace std;

#define LL long long

const LL inf = 1000000000000000001ll; 

char s[1000];

int rep[256], a[256], vst[100];

int N;

int run() {
	scanf("%s", s);
	memset(rep,-1,sizeof(rep));
	memset(vst,0,sizeof(vst));
	N=strlen(s);
	int n = 1;
	rep[s[0]]=1;vst[1]=1;
	for(int i=1;i<N;++i)
		if(rep[s[i]]<0) {
			for(int j=0;;j++)
				if(!vst[j]) {
					vst[j]=1;
					rep[s[i]]=j;
					n >?= j;
					break;
				}
		}
	n ++;
	LL ans=0;
	for(int i=0;i<N;++i)
		ans = ans * n + rep[s[i]];
	cout<<ans<<endl;
}

int main() {
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int test;scanf("%d",&test);
	for(int no=1;no<=test;++no){
		printf("Case #%d: ",no);
		run();
	}
}
