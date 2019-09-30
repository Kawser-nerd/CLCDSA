long long N,a[2000],d[2000][2000],x,i,k,t,s,p,q;main(){
	scanf("%lld%lld",&N,&x);
	for(;~scanf("%lld",a+i);++i)s+=*d[i]=a[i];
	for(;++k<N;s=t<s?t:s)
		for(t=k*x,i=0;i<N;++i)
			t+=d[i][k]=(p=a[(i-k+N)%N])<(q=d[i][k-1])?p:q;
	k=!printf("%lld\n",s);
} ./Main.c:1:49: warning: return type defaults to ‘int’ [-Wimplicit-int]
 long long N,a[2000],d[2000][2000],x,i,k,t,s,p,q;main(){
                                                 ^
./Main.c: In function ‘main’:
./Main.c:2:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%lld%lld",&N,&x);
  ^
./Main.c:2:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:2:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:7:5: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
  k=!printf("%lld\n",s);
     ^
./Main.c:7:5: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:7:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’