#include <stdio.h>
#define rep(i,l,r)for(int i=(l);i<(r);i++)

int n;
int a[200010];
int q[200010];
int c[200010];

int f(int m){
	int qc=0;
	q[0]=a[0];
	c[0]=1;
	qc=1;
	rep(i,1,n){
		if(a[i]>q[qc-1]){
			q[qc]=a[i];
			c[qc]=1;
			qc++;
		}else if(a[i]==q[qc-1]){
			c[qc-1]++;
		}else{
			while(qc&&q[qc-1]>a[i])qc--;
			if(qc==0||q[qc-1]<a[i]){
				q[qc]=a[i];
				c[qc]=2;
				qc++;
			}else{
				c[qc-1]++;
			}
		}
		
		if(c[qc-1]>m){
			int t=a[i];
			//???(t,>m)???????pop??(t-1,*)?inc???
			while(c[qc-1]>m){
				if(t==1)return 0;
				qc--;//pop
				if(qc&&q[qc-1]==t-1){
					c[qc-1]++;
				}else{
					q[qc]=t-1;
					c[qc]=2;
					qc++;
				}
				t--;
			}
			//(a[i],1)??????
			q[qc]=a[i];
			c[qc]=1;
			qc++;
		}
	}
	return 1;
}


int main(){
	scanf("%lld",&n);
	rep(i,0,n)scanf("%lld",a+i);
	
	int lans=0,rans=200010;//l?ng,r?ok
	while(rans-lans>1){
		int m=(lans+rans)/2;
		if(f(m))rans=m;
		else lans=m;
	}
	printf("%d",rans);
} ./Main.c: In function ‘main’:
./Main.c:58:8: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 2 has type ‘int *’ [-Wformat=]
  scanf("%lld",&n);
        ^
./Main.c:59:18: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 2 has type ‘int *’ [-Wformat=]
  rep(i,0,n)scanf("%lld",a+i);
                  ^
./Main.c:58:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:59:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld",a+i);
            ^