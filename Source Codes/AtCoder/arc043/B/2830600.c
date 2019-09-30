k,s[5][1<<22],m=1e9+7;main(i){for(scanf("%d",&i);~scanf("%d",&i);s[0][i]++);for(;k++-4;)for(i=m>>9;i--;)s[k][i]=(s[k][i+1]+1LL*s[0][i]*(k-1?s[k-1][2*i]:1))%m;k!=printf("%d",s[4][1]);} ./Main.c:1:1: warning: data definition has no type or storage class
 k,s[5][1<<22],m=1e9+7;main(i){for(scanf("%d",&i);~scanf("%d",&i);s[0][i]++);for(;k++-4;)for(i=m>>9;i--;)s[k][i]=(s[k][i+1]+1LL*s[0][i]*(k-1?s[k-1][2*i]:1))%m;k!=printf("%d",s[4][1]);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘k’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
 k,s[5][1<<22],m=1e9+7;main(i){for(scanf("%d",&i);~scanf("%d",&i);s[0][i]++);for(;k++-4;)for(i=m>>9;i--;)s[k][i]=(s[k][i+1]+1LL*s[0][i]*(k-1?s[k-1][2*i]:1))%m;k!=printf("%d",s[4][1]);}
   ^
./Main.c:1:15: warning: type defaults to ‘int’ in declaration of ‘m’ [-Wimplicit-int]
 k,s[5][1<<22],m=1e9+7;main(i){for(scanf("%d",&i);~scanf("%d",&i);s[0][i]++);for(;k++-4;)for(i=m>>9;i--;)s[k][i]=(s[k][i+1]+1LL*s[0][i]*(k-1?s[k-1][2*i]:1))%m;k!=printf("%d",s[4][1]);}
               ^
./Main.c:1:23: warning: return type defaults to ‘int’ [-Wimplicit-int]
 k,s[5][1<<22],m=1e9+7;main(i){for(scanf("%d",&i)...