long n,k;long fun(long n, long x){if(n==0)return(x<=0?0:1);long p=(1LL<<n)-1;if(x<=2*p)return fun(n-1,x-1);return p+1+fun(n-1,x-1-2*p);}main(){scanf("%ld%ld",&n,&k);printf("%ld\n",fun(n,k));} ./Main.c:1:137: warning: return type defaults to ‘int’ [-Wimplicit-int]
 long n,k;long fun(long n, long x){if(n==0)return(x<=0?0:1);long p=(1LL<<n)-1;if(x<=2*p)return fun(n-1,x-1);return p+1+fun(n-1,x-1-2*p);}main(){scanf("%ld%ld",&n,&k);printf("%ld\n",fun(n,k));}
                                                                                                                                         ^
./Main.c: In function ‘main’:
./Main.c:1:144: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 long n,k;long fun(long n, long x){if(n==0)return(x<=0?0:1);long p=(1LL<<n)-1;if(x<=2*p)return fun(n-1,x-1);return p+1+fun(n-1,x-1-2*p);}main(){scanf("%ld%ld",&n,&k);printf("%ld\n",fun(n,k));}
                                                                                                                                                ^
./Main.c:1:144: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:144: note: include ‘<stdio.h>’ or provide a declarat...