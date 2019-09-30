long M=1e9+7,m[1<<18],h,w,a,s;
long p(a,b)long a,b;{return b?b%2?p(a*a%M,b/2)*a%M:p(a*a%M,b/2):1;}
main(i)
{
	for(*m=1;i<1<<18;i++)m[i]=m[i-1]*i%M;
	for(scanf("%d%d%d%d",&h,&w,&a,&i);i<w;i++)s=(s+m[h-a-1+i]*p(m[h-a-1],M-2)%M*p(m[i],M-2)%M*m[a+w-i-2]%M*p(m[a-1],M-2)%M*p(m[w-i-1],M-2)%M)%M;
	printf("%d",s);
} ./Main.c:3:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(i)
 ^
./Main.c: In function ‘main’:
./Main.c:3:1: warning: type of ‘i’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:6:6: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  for(scanf("%d%d%d%d",&h,&w,&a,&i);i<w;i++)s=(s+m[h-a-1+i]*p(m[h-a-1],M-2)%M*p(m[i],M-2)%M*m[a+w-i-2]%M*p(m[a-1],M-2)%M*p(m[w-i-1],M-2)%M)%M;
      ^
./Main.c:6:6: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:6:6: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:6:12: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘long int *’ [-Wformat=]
  for(scanf("%d%d%d%d",&h,&w,&a,&i);i<w;i++)s=(s+m[h-a-1+i]*p(m[h-a-1],M-2)%M*p(m[i],M-2)%M*m[a+w-i-2]%M*p(m[a-1],M-2)%M*p(m[w-i-1],M-2)%M)%M;
            ^
./Main.c:6:12: warning: format ‘%d’ expects argument of type ‘int *’, but argument 3 has type ‘long int *’ [-Wformat=]
./Main.c:6:12: warning: format ‘%...