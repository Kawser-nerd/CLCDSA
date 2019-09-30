long M=1e9+7,m[1<<18],h,w,a,s;long p(a,b)long a,b;{return b?b%2?p(a*a%M,b/2)*a%M:p(a*a%M,b/2):1;}main(i){for(*m=1;i<1<<18;i++)m[i]=m[i-1]*i%M;for(scanf("%d%d%d%d",&h,&w,&a,&i);i<w;i++)s=(s+m[h-a-1+i]*p(m[h-a-1],M-2)%M*p(m[i],M-2)%M*m[a+w-i-2]%M*p(m[a-1],M-2)%M*p(m[w-i-1],M-2)%M)%M;printf("%d",s);} ./Main.c:1:98: warning: return type defaults to ‘int’ [-Wimplicit-int]
 long M=1e9+7,m[1<<18],h,w,a,s;long p(a,b)long a,b;{return b?b%2?p(a*a%M,b/2)*a%M:p(a*a%M,b/2):1;}main(i){for(*m=1;i<1<<18;i++)m[i]=m[i-1]*i%M;for(scanf("%d%d%d%d",&h,&w,&a,&i);i<w;i++)s=(s+m[h-a-1+i]*p(m[h-a-1],M-2)%M*p(m[i],M-2)%M*m[a+w-i-2]%M*p(m[a-1],M-2)%M*p(m[w-i-1],M-2)%M)%M;printf("%d",s);}
                                                                                                  ^
./Main.c: In function ‘main’:
./Main.c:1:98: warning: type of ‘i’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:147: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 long M=1e9+7,m[1<<18],h,w,a,s;long p(a,b)long a,b;{return b?b%2?p(a*a%M,b/2)*a%M:p(a*a%M,b/2):1;}main(i){for(*m=1;i<1<<18;i++)m[i]=m[i-1]*i%M;for(scanf("%d%d%d%d",&h,&w,&a,&i);i<w;i++)s=(s+m[h-a-1+i]*p(m[h-a-1],M-2)%M*p(m[i],M-2)%M*m[a+w-i-2]%M*p(m[a-1],M-2)%M*p(m[w-i-1],M-2)%M)%M;printf("%d",s);}
                                                    ...