char s[2][999];i;j;main(b,n){scanf("%s%s",s,s[1]);for(n=strlen(s);b&i<n;i++)for(b=j=0;j<n;)b|=s[0][j]-s[1][(i+j++)%n];puts(b?"No":"Yes");} ./Main.c:1:16: warning: data definition has no type or storage class
 char s[2][999];i;j;main(b,n){scanf("%s%s",s,s[1]);for(n=strlen(s);b&i<n;i++)for(b=j=0;j<n;)b|=s[0][j]-s[1][(i+j++)%n];puts(b?"No":"Yes");}
                ^
./Main.c:1:16: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:18: warning: data definition has no type or storage class
 char s[2][999];i;j;main(b,n){scanf("%s%s",s,s[1]);for(n=strlen(s);b&i<n;i++)for(b=j=0;j<n;)b|=s[0][j]-s[1][(i+j++)%n];puts(b?"No":"Yes");}
                  ^
./Main.c:1:18: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
./Main.c:1:20: warning: return type defaults to ‘int’ [-Wimplicit-int]
 char s[2][999];i;j;main(b,n){scanf("%s%s",s,s[1]);for(n=strlen(s);b&i<n;i++)for(b=j=0;j<n;)b|=s[0][j]-s[1][(i+j++)%n];puts(b?"No":"Yes");}
                    ^
./Main.c: In function ‘main’:
./Main.c:1:20: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:20: warning: type of ‘n’ defaults to ‘int’ [-Wimpli...