#include<stdio.h>

char s[200001];

int main(int argc, char const *argv[]){
	long n,k,d,f,i,c;
	scanf("%ld %ld",&n,&k);
	getchar();
	scanf("%s",s);
	d=0;
	c=0;
	while(d<n && c<k){
		if(s[d]==((d%2==0)?'B':'A')){
			c++;
		}else c+=2;
		d++;
	}
	if(c==k){
		f=0;
	}else if(c>k){
		d--;
		if(s[d]==((d%2==0)?'B':'A')){
			f=0;
		}else f=1;
	}else{
		f=2;
	}
	if(f==2){
		for(i=n-1;i>=0;i--){
			s[i]=((s[i+1]=='A')?'B':'A');
		}
		if(s[0]=='A' && (k-c)%2==1) s[0]='B';
	}else{
		for(i=0;i<n-d;i++){
			if(d%2==1){
				s[i]=((s[i+d]=='A')?'B':'A');
			}else s[i]=s[i+d];
		}
		for(i=n-1;i>=n-d;i--){
			s[i]=((s[i+1]=='A')?'B':'A');
		}
		if(f==1){
			s[0]='B';
		}
	}
	printf("%s\n",s);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld %ld",&n,&k);
  ^
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^