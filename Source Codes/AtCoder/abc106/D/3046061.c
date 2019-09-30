L,R,i,c[555][555],s;main(n){for(scanf("%*d%d%*d",&n);~scanf("%d%d",&L,&R);i++)for(s=0;i/n?R/L||!printf("%d\n",s):R<501;)i/n?s+=c[L++][R]:c[L][R++]++;} ./Main.c:1:1: warning: data definition has no type or storage class
 L,R,i,c[555][555],s;main(n){for(scanf("%*d%d%*d",&n);~scanf("%d%d",&L,&R);i++)for(s=0;i/n?R/L||!printf("%d\n",s):R<501;)i/n?s+=c[L++][R]:c[L][R++]++;}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘L’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘R’ [-Wimplicit-int]
 L,R,i,c[555][555],s;main(n){for(scanf("%*d%d%*d",&n);~scanf("%d%d",&L,&R);i++)for(s=0;i/n?R/L||!printf("%d\n",s):R<501;)i/n?s+=c[L++][R]:c[L][R++]++;}
   ^
./Main.c:1:5: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 L,R,i,c[555][555],s;main(n){for(scanf("%*d%d%*d",&n);~scanf("%d%d",&L,&R);i++)for(s=0;i/n?R/L||!printf("%d\n",s):R<501;)i/n?s+=c[L++][R]:c[L][R++]++;}
     ^
./Main.c:1:7: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
 L,R,i,c[555][555],s;main(n){for(scanf("%*d%d%*d",&n);~scanf("%d%d",&L,&R);i++)for(s=0;i/n?R/L||!printf("%d\n",s):R<501;)i/n?s+=c[L++][R]:c[L][R+...