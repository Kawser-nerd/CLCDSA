c[2];i;m;main(j,s)char*s;{gets(s);for(gets(s);s[++i];m=fmax(__builtin_popcount(*c&c[1]),m))for(*c=c[1]=j=0;s[j];)c[j<i]|=1<<s[j++]-97;printf("%d",m);} ./Main.c:1:1: warning: data definition has no type or storage class
 c[2];i;m;main(j,s)char*s;{gets(s);for(gets(s);s[++i];m=fmax(__builtin_popcount(*c&c[1]),m))for(*c=c[1]=j=0;s[j];)c[j<i]|=1<<s[j++]-97;printf("%d",m);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
./Main.c:1:6: warning: data definition has no type or storage class
 c[2];i;m;main(j,s)char*s;{gets(s);for(gets(s);s[++i];m=fmax(__builtin_popcount(*c&c[1]),m))for(*c=c[1]=j=0;s[j];)c[j<i]|=1<<s[j++]-97;printf("%d",m);}
      ^
./Main.c:1:6: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:8: warning: data definition has no type or storage class
 c[2];i;m;main(j,s)char*s;{gets(s);for(gets(s);s[++i];m=fmax(__builtin_popcount(*c&c[1]),m))for(*c=c[1]=j=0;s[j];)c[j<i]|=1<<s[j++]-97;printf("%d",m);}
        ^
./Main.c:1:8: warning: type defaults to ‘int’ in declaration of ‘m’ [-Wimplicit-int]
./Main.c:1:10: warning: return type defaults to ‘int’ [-Wimplicit-int]
 c[2];i;m;main(j,...