long M=1e9+7,s=1,c[2<<17],*q;p(b,a)long b,a;{return b?p(b/2,a*a%M)*(b%2?a:1)%M:1;}main(a){for(scanf("%*d");~scanf("%d",&a);s*=*c%2)c[a]++;for(q=c;q-c<2e5;)s=s*p(*q,p(*q++,2)-1+M)%M*p(~-*q**q/2,2)%M;printf("%d\n",s);} ./Main.c:1:30: warning: return type defaults to ‘int’ [-Wimplicit-int]
 long M=1e9+7,s=1,c[2<<17],*q;p(b,a)long b,a;{return b?p(b/2,a*a%M)*(b%2?a:1)%M:1;}main(a){for(scanf("%*d");~scanf("%d",&a);s*=*c%2)c[a]++;for(q=c;q-c<2e5;)s=s*p(*q,p(*q++,2)-1+M)%M*p(~-*q**q/2,2)%M;printf("%d\n",s);}
                              ^
./Main.c:1:83: warning: return type defaults to ‘int’ [-Wimplicit-int]
 long M=1e9+7,s=1,c[2<<17],*q;p(b,a)long b,a;{return b?p(b/2,a*a%M)*(b%2?a:1)%M:1;}main(a){for(scanf("%*d");~scanf("%d",&a);s*=*c%2)c[a]++;for(q=c;q-c<2e5;)s=s*p(*q,p(*q++,2)-1+M)%M*p(~-*q**q/2,2)%M;printf("%d\n",s);}
                                                                                   ^
./Main.c: In function ‘main’:
./Main.c:1:83: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:95: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 long M=1e9+7,s=1,c[2<<17],*q;p(b,a)long b,a;{return b?p(b/2,a*a%M)*(b%2?a:1)%M:1;}main(a){for(scanf("%*d");~scanf("%d",&a);s*=*c...