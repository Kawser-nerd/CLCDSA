#include<stdio.h>
#define max(x,y) ((x)>(y)?(x):(y))

int main(){
	long n,i;
	long long a,s;
	long long ans,cmp=0;
	char op,f;
	scanf("%ld",&n);
	scanf("%lld",&a);
	f=0;
	s=0;
	ans=a;
	for(i=0;i<n-1;i++){
		scanf(" %c",&op);
		scanf("%lld",&a);
		if(f==0 && op=='-'){
			ans-=a;
			f=1;
			s=0;
		}else if(f==1 && op=='+'){
			s+=a;
		}else if(f==1 && op=='-'){
			if(s-a<=a-s){
				ans+=a-s;
				s=0;
				f=2;
			}else{
				cmp=ans+a-s;
				ans+=s-a;
				f=3;
				s=0;
			}
		}else if(f==3){
			cmp+=a;
			if(op=='+'){
				s+=a;
			}else{
				if(s-a<=a-s){
					ans+=a-s;
					s=0;
					f=4;
				}else{
					cmp=max(cmp,ans+a-s);
					ans+=s-a;
					s=0;
				}
			}
		}else{
			ans+=a;
			cmp+=a;
		}
	}
	if(s>0){
		ans+=s;
	}
	if(f>=3){
		ans=max(ans,cmp);
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld",&n);
  ^
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&a);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf(" %c",&op);
   ^
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&a);
   ^