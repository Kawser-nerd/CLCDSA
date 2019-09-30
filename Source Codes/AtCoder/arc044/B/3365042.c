long M=1e9+7,c[1<<17],n,a,i,s=1;p(a,b)long a,b;{return b?p(a*a%M,b/2)*(b%2?a:1)%M:1;}main(){for(scanf("%d",&n);~scanf("%d",&a);s*=*c%2)c[a]++;for(;++i<n;)s=s*p(p(2,c[i-1])-1+M,c[i])%M*p(2,~-c[i]*c[i]/2)%M;printf("%d\n",s);} ./Main.c:1:33: warning: return type defaults to ‘int’ [-Wimplicit-int]
 long M=1e9+7,c[1<<17],n,a,i,s=1;p(a,b)long a,b;{return b?p(a*a%M,b/2)*(b%2?a:1)%M:1;}main(){for(scanf("%d",&n);~scanf("%d",&a);s*=*c%2)c[a]++;for(;++i<n;)s=s*p(p(2,c[i-1])-1+M,c[i])%M*p(2,~-c[i]*c[i]/2)%M;printf("%d\n",s);}
                                 ^
./Main.c:1:86: warning: return type defaults to ‘int’ [-Wimplicit-int]
 long M=1e9+7,c[1<<17],n,a,i,s=1;p(a,b)long a,b;{return b?p(a*a%M,b/2)*(b%2?a:1)%M:1;}main(){for(scanf("%d",&n);~scanf("%d",&a);s*=*c%2)c[a]++;for(;++i<n;)s=s*p(p(2,c[i-1])-1+M,c[i])%M*p(2,~-c[i]*c[i]/2)%M;printf("%d\n",s);}
                                                                                      ^
./Main.c: In function ‘main’:
./Main.c:1:97: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 long M=1e9+7,c[1<<17],n,a,i,s=1;p(a,b)long a,b;{return b?p(a*a%M,b/2)*(b%2?a:1)%M:1;}main(){for(scanf("%d",&n);~scanf("%d",&a);s*=*c%2)c[a]++;for(;++i<n;)s=s*p(p(2,c[i-1])-1+M,c[i...