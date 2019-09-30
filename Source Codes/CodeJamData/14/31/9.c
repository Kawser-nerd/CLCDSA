#include "stdio.h"
	int gcd(int p,int q){
		if(q == 0)return p;
		return gcd(q,p%q);
	}
	int check(int p,int q){
		int k = gcd(p,q);
		q = q / k;
		while(q%2==0){
			q = q / 2;
		}
		if(q !=1) return 0;else return 1;
	}
	int search(int p,int q,int tot){
		int  t1 = q /2;
		if(p < t1)return search(p,t1,tot+1);
		return tot;
	}
	int find(int p,int q){
		int k = gcd(p,q);
		q = q/k;
		p = p/k;
		return search(p,q,1);
	}
int main(){
	int T,p,q;
	freopen("a.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&T);
	for(int tot=1;tot<=T;tot++){
		scanf("%d/%d",&p,&q);
		if(check(p,q)==1){
			printf("Case #%d: %d\n",tot,find(p,q));
		}else{
			printf("Case #%d: impossible\n",tot);
		}
	}
}
