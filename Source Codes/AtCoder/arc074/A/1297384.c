#include<stdio.h>
#define min(a,b) (((a)<(b))?(a):(b))
int main(int argc, char const *argv[]){
	long long h,w,ans,i,a,b,c;
	scanf("%lld %lld",&h,&w);
	if(h%3==0 || w%3==0){
		printf("0\n");
	}else{
		ans=h*w;
		if(h>=3) ans=w;
		if(w>=3) ans=min(ans,h);
		for(i=1;i<w;i++){
			a=i*h;
			b=(w-i)*(h/2);
			c=(w-i)*(h/2+h%2);
			if(a<b){
				ans=min(ans,c-a);
			}else{
				if(a>c){
					ans=min(ans,a-b);
				}else{
					ans=min(ans,c-b);
				}
			}
		}
		for(i=1;i<h;i++){
			a=i*w;
			b=(h-i)*(w/2);
			c=(h-i)*(w/2+w%2);
			if(a<b){
				ans=min(ans,c-a);
			}else{
				if(a>c){
					ans=min(ans,a-b);
				}else{
					ans=min(ans,c-b);
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld",&h,&w);
  ^