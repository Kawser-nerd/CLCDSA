long M=1e9+7,m[1<<18],h,w,a,s;p(a,b)long a;{return b?p(a*a%M,b/2)*(b%2?a:1)%M:1;}main(i){for(*m=1;i<1<<18;)m[i]=m[i-1]*i++%M;for(scanf("%d%d%d%d",&h,&w,&a,&i);i<w;)s=(s+m[h-a-1+i]*p(m[h-a-1],M-2)%M*p(m[i],M-2)%M*m[a+w-i-2]%M*p(m[a-1],M-2)%M*p(m[w-1-i++],M-2)%M)%M;printf("%d",s);} ./Main.c:1:31: warning: return type defaults to ‘int’ [-Wimplicit-int]
 long M=1e9+7,m[1<<18],h,w,a,s;p(a,b)long a;{return b?p(a*a%M,b/2)*(b%2?a:1)%M:1;}main(i){for(*m=1;i<1<<18;)m[i]=m[i-1]*i++%M;for(scanf("%d%d%d%d",&h,&w,&a,&i);i<w;)s=(s+m[h-a-1+i]*p(m[h-a-1],M-2)%M*p(m[i],M-2)%M*m[a+w-i-2]%M*p(m[a-1],M-2)%M*p(m[w-1-i++],M-2)%M)%M;printf("%d",s);}
                               ^
./Main.c: In function ‘p’:
./Main.c:1:31: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
./Main.c: At top level:
./Main.c:1:82: warning: return type defaults to ‘int’ [-Wimplicit-int]
 long M=1e9+7,m[1<<18],h,w,a,s;p(a,b)long a;{return b?p(a*a%M,b/2)*(b%2?a:1)%M:1;}main(i){for(*m=1;i<1<<18;)m[i]=m[i-1]*i++%M;for(scanf("%d%d%d%d",&h,&w,&a,&i);i<w;)s=(s+m[h-a-1+i]*p(m[h-a-1],M-2)%M*p(m[i],M-2)%M*m[a+w-i-2]%M*p(m[a-1],M-2)%M*p(m[w-1-i++],M-2)%M)%M;printf("%d",s);}
                                                                                  ^
./Main.c: In function ‘main’:
./Main.c:1:82: warning: type of ‘i’ defaults to ‘...