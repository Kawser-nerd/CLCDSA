#include "stdio.h"
#include "string.h"
int flag;
int f[32];
char a[128][2];
char str[256];
int sum;
long long mo;
long long c1[32],c2[32];
int tt[128];
	void add_init(char* str,int num){
		char x = str[0];
		int T1 = 0;
		int Tflag =1;
		a[num][0] = x;
		for(int i=1;i<strlen(str);i++){
			if(str[i] != x){
				if(T1==1){
					if(f[x-'a']==1)flag =1;
					f[x - 'a'] =1;
				}
				x = str[i];
				T1 = 1;
			}
		}
		a[num][1] = x;
		if(a[num][1] == a[num][0] && T1 ==1)flag = 1;
	}
	void check(){
		for(int i=0;i<sum;i++)
			if(f[a[i][0]-'a']==1 || f[a[i][1]-'a']==1)flag =1;
	}
	long long Tcalc1(int num){
		int x = c1[a[num][1]-'a'];
		c1[a[num][1]-'a'] = -1;
		if(x == -1)return 0;
		if(x == 0)x = 1;
		for(int i=0;i<sum;i++)
			if(tt[i]==1 && a[i][0]==a[num][1]){
				tt[i] = 0;
				return (x*Tcalc1(i))% mo;
			}
		return x;
	}
	long long Tcalc2(int num){
		int x = c1[a[num][0]-'a'];
		c1[a[num][0]-'a'] = -1;
		if(x == -1)return 0;
		if(x==0) x= 1;
		for(int i=0;i<sum;i++)
			if(tt[i]==1 && a[i][1] == a[num][0]){
				tt[i] = 0;
				return (x*Tcalc2(i)) % mo;
			}
		return x;
	}
	long long Tcalc(int num){
		tt[num] = 0;
		return (Tcalc1(num)*Tcalc2(num)) % mo;
	}
	long long  calc(){
		for(int i=0;i<sum;i++)tt[i] =1;
		for(int i=0;i<26;i++)
			c1[i] = 0;
		for(int i=0;i<sum;i++)
			if(a[i][0]==a[i][1]){
				tt[i] =0; 
				int x = a[i][0] - 'a';
				if(c1[x] == 0){
					c1[x] =1;
					c2[x] =1;
				}else{
					c2[x]++;
					c1[x] = (c1[x]*c2[x])% mo;
				}
			}
		long long ans = 1;
		int tsum = 0;
		for(int i=0;i<sum;i++)
			if(tt[i]==1){
				ans = (ans * Tcalc(i))%mo;
				tsum++;
			}
		for(int i=0;i<26;i++)
			if(c1[i]>0){
				tsum++;
				ans = (ans *c1[i])%mo;
			}
		while(tsum > 1){
			ans = (ans * tsum)%mo;
			tsum--;
		}
		return ans;
	}
int main(){
	int T;
	mo = 1000000007;
	freopen("b.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&T);
	for(int tot=1;tot<=T;tot++){
		scanf("%d",&sum);
		flag =0;
		for(int i=0;i<26;i++)f[i] = 0;
		for(int i=0;i<sum;i++){
			scanf("%s",str);
			add_init(str,i);
		}
		check();
		printf("Case #%d: ",tot);
		if(flag ==1)printf("0\n");else printf("%lld\n",calc());
	}
	return 0;
}
