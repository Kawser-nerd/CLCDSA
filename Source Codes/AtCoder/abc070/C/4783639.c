long t,m=1,d,e,f;i;main(){for(;~scanf("%ld",&t);i++?m=i-2?t/e*m:t:0)for(d=t<m?e=t,m:(e=m,t);f=d%e;e=f)d=e;printf("%ld",m);} ./Main.c:1:18: warning: data definition has no type or storage class
 long t,m=1,d,e,f;i;main(){for(;~scanf("%ld",&t);i++?m=i-2?t/e*m:t:0)for(d=t<m?e=t,m:(e=m,t);f=d%e;e=f)d=e;printf("%ld",m);}
                  ^
./Main.c:1:18: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:20: warning: return type defaults to ‘int’ [-Wimplicit-int]
 long t,m=1,d,e,f;i;main(){for(;~scanf("%ld",&t);i++?m=i-2?t/e*m:t:0)for(d=t<m?e=t,m:(e=m,t);f=d%e;e=f)d=e;printf("%ld",m);}
                    ^
./Main.c: In function ‘main’:
./Main.c:1:33: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 long t,m=1,d,e,f;i;main(){for(;~scanf("%ld",&t);i++?m=i-2?t/e*m:t:0)for(d=t<m?e=t,m:(e=m,t);f=d%e;e=f)d=e;printf("%ld",m);}
                                 ^
./Main.c:1:33: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:33: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:107: warning: implicit declaration of func...