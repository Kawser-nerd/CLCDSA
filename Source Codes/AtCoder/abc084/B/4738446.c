a;b;i;main(c,s)char*s;{for(scanf("%d%d %s",&a,&b,s);c&&i<=a+b;i++)c=i-a?isdigit(s[i]):s[i]==45;puts(c&!s[i]?"Yes":"No");} ./Main.c:1:1: warning: data definition has no type or storage class
 a;b;i;main(c,s)char*s;{for(scanf("%d%d %s",&a,&b,s);c&&i<=a+b;i++)c=i-a?isdigit(s[i]):s[i]==45;puts(c&!s[i]?"Yes":"No");}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:1:3: warning: data definition has no type or storage class
 a;b;i;main(c,s)char*s;{for(scanf("%d%d %s",&a,&b,s);c&&i<=a+b;i++)c=i-a?isdigit(s[i]):s[i]==45;puts(c&!s[i]?"Yes":"No");}
   ^
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
./Main.c:1:5: warning: data definition has no type or storage class
 a;b;i;main(c,s)char*s;{for(scanf("%d%d %s",&a,&b,s);c&&i<=a+b;i++)c=i-a?isdigit(s[i]):s[i]==45;puts(c&!s[i]?"Yes":"No");}
     ^
./Main.c:1:5: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:7: warning: return type defaults to ‘int’ [-Wimplicit-int]
 a;b;i;main(c,s)char*s;{for(scanf("%d%d %s",&a,&b,s);c&&i<=a+b;i++)c=i-a?isdigit(s[i]):s[i]==45;puts(c&!s[i]?"Y...