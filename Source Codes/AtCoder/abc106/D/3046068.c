L,R,c[555][555],s;main(n){for(scanf("%*d%d%*d",&n);~scanf("%d%d",&L,&R);s=0)for(n--;n<0?R/L||!printf("%d\n",s):R<501;)n<0?s+=c[L++][R]:c[L][R++]++;} ./Main.c:1:1: warning: data definition has no type or storage class
 L,R,c[555][555],s;main(n){for(scanf("%*d%d%*d",&n);~scanf("%d%d",&L,&R);s=0)for(n--;n<0?R/L||!printf("%d\n",s):R<501;)n<0?s+=c[L++][R]:c[L][R++]++;}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘L’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘R’ [-Wimplicit-int]
 L,R,c[555][555],s;main(n){for(scanf("%*d%d%*d",&n);~scanf("%d%d",&L,&R);s=0)for(n--;n<0?R/L||!printf("%d\n",s):R<501;)n<0?s+=c[L++][R]:c[L][R++]++;}
   ^
./Main.c:1:5: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
 L,R,c[555][555],s;main(n){for(scanf("%*d%d%*d",&n);~scanf("%d%d",&L,&R);s=0)for(n--;n<0?R/L||!printf("%d\n",s):R<501;)n<0?s+=c[L++][R]:c[L][R++]++;}
     ^
./Main.c:1:17: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
 L,R,c[555][555],s;main(n){for(scanf("%*d%d%*d",&n);~scanf("%d%d",&L,&R);s=0)for(n--;n<0?R/L||!printf("%d\n",s):R<501;)n<0?s+=c[L++][R]:c[L][R++]++;}
...