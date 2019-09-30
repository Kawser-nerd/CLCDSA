long long f(long long b,long long x){return x<b?x:f(b,x/b)+x%b;}
long long g(){
	long long n,s,b=2,r=-1,z;
	scanf("%lld%lld",&n,&s);
	if(n<s)return r;
	if(n==s)return n+1;
	for(;b*b<=n;b++)if(f(b,n)==s)return b;
	for(b=1;b*b<=n;b++)if((n-s)%b==0&&f(z=(n-s)/b+1,n)==s)r=z;
	return r;
}
int main(){printf("%lld\n",g());} ./Main.c: In function ‘g’:
./Main.c:4:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%lld%lld",&n,&s);
  ^
./Main.c:4:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:4:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c: In function ‘main’:
./Main.c:11:12: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 int main(){printf("%lld\n",g());}
            ^
./Main.c:11:12: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:11:12: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’