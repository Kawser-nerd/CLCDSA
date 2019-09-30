#include<stdio.h>
int p[61],q[61];
long long t[61];
int main(int argc, char const *argv[]){
	long long a,b,c,d;
	int i;
	scanf("%lld",&a);
	scanf("%lld",&b);
	if(a==b){
		printf("1\n");
		return 0;
	}
	t[0]=1;
	for(i=1;i<61;i++){
		t[i]=t[i-1]*2;
	}
	c=a;
	d=b;
	i=1;
	while(c>0){
		p[i]=c%2;
		c/=2;
		i++;
	}
	p[0]=i-1;
	i=1;
	while(d>0){
		q[i]=d%2;
		d/=2;
		i++;
	}
	q[0]=i-1;
	if(p[0]==q[0]){
		while(p[p[0]]==q[p[0]]){
			p[0]--;
			q[0]--;
		}
		while(p[0]>0 && p[p[0]]==0){
			p[0]--;
		}
		a=0;
		b=0;
		for(i=0;i<p[0];i++){
			a+=t[i]*p[i+1];
		}
		for(i=0;i<q[0];i++){
			b+=t[i]*q[i+1];
		}
	}
	c=t[q[0]-1];
	d=b-c;
	i=0;
	while(d>=t[i]){i++;}
	d=t[i]-1;
	if(d>=a) printf("%lld\n",2*c-a);
	else printf("%lld\n",2*c-2*a+d+1);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&a);
  ^
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&b);
  ^