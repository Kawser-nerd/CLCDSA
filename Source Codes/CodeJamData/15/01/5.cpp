#include<cstdio>

using namespace std;

int cnt[1010];

int S;
char ch[1010];
int num[1010];

bool check(){
	int sum=0;
	for(int i=0;i<=S;i++){
		if(sum>=i){
			sum+=num[i];
		}else{
			return false;
		}
	}
	return true;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int datano=0;datano<T;datano++){
		scanf("%d",&S);
		scanf("%s",ch);
		for(int i=0;i<S+1;i++) num[i]=ch[i]-'0';
		for(int x=0;x<=1000;x++){
			num[0]+=x;
			bool flg=check();
			if(flg){
				printf("Case #%d: %d\n",datano+1,x);
				break;
			}
			num[0]-=x;
		}
	}
	return 0;
}
