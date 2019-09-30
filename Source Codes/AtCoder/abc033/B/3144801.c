s[9],t[9];v,a;main(M){for(;~scanf("%s%d",t,&a);v+=a)a>M&&(M=a,strcpy(s,t));puts(M*2>v?s:"atcoder");} ./Main.c:1:1: warning: data definition has no type or storage class
 s[9],t[9];v,a;main(M){for(;~scanf("%s%d",t,&a);v+=a)a>M&&(M=a,strcpy(s,t));puts(M*2>v?s:"atcoder");}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
./Main.c:1:6: warning: type defaults to ‘int’ in declaration of ‘t’ [-Wimplicit-int]
 s[9],t[9];v,a;main(M){for(;~scanf("%s%d",t,&a);v+=a)a>M&&(M=a,strcpy(s,t));puts(M*2>v?s:"atcoder");}
      ^
./Main.c:1:11: warning: data definition has no type or storage class
 s[9],t[9];v,a;main(M){for(;~scanf("%s%d",t,&a);v+=a)a>M&&(M=a,strcpy(s,t));puts(M*2>v?s:"atcoder");}
           ^
./Main.c:1:11: warning: type defaults to ‘int’ in declaration of ‘v’ [-Wimplicit-int]
./Main.c:1:13: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
 s[9],t[9];v,a;main(M){for(;~scanf("%s%d",t,&a);v+=a)a>M&&(M=a,strcpy(s,t));puts(M*2>v?s:"atcoder");}
             ^
./Main.c:1:15: warning: return type defaults to ‘int’ [-Wimplicit-int]
 s[9],t[9];v,a;main(M){for(...