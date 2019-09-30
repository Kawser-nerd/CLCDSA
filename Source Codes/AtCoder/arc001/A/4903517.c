c[99];M,m=99;i=5;main(a,b){for(gets(&a);a=getchar()+1;)c[a]++;for(;--i;m=b<m?b:m)b=c[i+49],M=b>M?b:M;printf("%d %d\n",M,m);} ./Main.c:1:1: warning: data definition has no type or storage class
 c[99];M,m=99;i=5;main(a,b){for(gets(&a);a=getchar()+1;)c[a]++;for(;--i;m=b<m?b:m)b=c[i+49],M=b>M?b:M;printf("%d %d\n",M,m);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
./Main.c:1:7: warning: data definition has no type or storage class
 c[99];M,m=99;i=5;main(a,b){for(gets(&a);a=getchar()+1;)c[a]++;for(;--i;m=b<m?b:m)b=c[i+49],M=b>M?b:M;printf("%d %d\n",M,m);}
       ^
./Main.c:1:7: warning: type defaults to ‘int’ in declaration of ‘M’ [-Wimplicit-int]
./Main.c:1:9: warning: type defaults to ‘int’ in declaration of ‘m’ [-Wimplicit-int]
 c[99];M,m=99;i=5;main(a,b){for(gets(&a);a=getchar()+1;)c[a]++;for(;--i;m=b<m?b:m)b=c[i+49],M=b>M?b:M;printf("%d %d\n",M,m);}
         ^
./Main.c:1:14: warning: data definition has no type or storage class
 c[99];M,m=99;i=5;main(a,b){for(gets(&a);a=getchar()+1;)c[a]++;for(;--i;m=b<m?b:m)b=c[i+49],M=b>M?b:M;printf("%d %d\n",M,m);}
              ^
./Main.c:1:14: warnin...