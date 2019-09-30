b;c;char*s="takahashikun",w[999];main(i){for(;~scanf("%[^\n\ \.]%*c\n",w);strcmp(s,w)&&*w-84|strcmp(s+1,w+1)&&b|i-12?:c++)for(b=i=0;!b*w[i];)b=s[i]-w[i++]-32;printf("%d\n",c);} ./Main.c:1:1: warning: data definition has no type or storage class
 b;c;char*s="takahashikun",w[999];main(i){for(;~scanf("%[^\n\ \.]%*c\n",w);strcmp(s,w)&&*w-84|strcmp(s+1,w+1)&&b|i-12?:c++)for(b=i=0;!b*w[i];)b=s[i]-w[i++]-32;printf("%d\n",c);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
./Main.c:1:3: warning: data definition has no type or storage class
 b;c;char*s="takahashikun",w[999];main(i){for(;~scanf("%[^\n\ \.]%*c\n",w);strcmp(s,w)&&*w-84|strcmp(s+1,w+1)&&b|i-12?:c++)for(b=i=0;!b*w[i];)b=s[i]-w[i++]-32;printf("%d\n",c);}
   ^
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
./Main.c:1:34: warning: return type defaults to ‘int’ [-Wimplicit-int]
 b;c;char*s="takahashikun",w[999];main(i){for(;~scanf("%[^\n\ \.]%*c\n",w);strcmp(s,w)&&*w-84|strcmp(s+1,w+1)&&b|i-12?:c++)for(b=i=0;!b*w[i];)b=s[i]-w[i++]-32;printf("%d\n",c);}
                                  ^
./Main.c: In function ‘main’:
./Main.c:1:34: warning: type of ‘i’ def...