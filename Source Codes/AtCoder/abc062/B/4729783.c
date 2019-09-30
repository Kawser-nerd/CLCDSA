s[99];i;main(h,w){for(scanf("%d%d",&h,&w);i<h+2;putchar(35),printf("%s",s),puts("#"))i++%-~h?scanf("%s",s):memset(s,35,w);} ./Main.c:1:1: warning: data definition has no type or storage class
 s[99];i;main(h,w){for(scanf("%d%d",&h,&w);i<h+2;putchar(35),printf("%s",s),puts("#"))i++%-~h?scanf("%s",s):memset(s,35,w);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
./Main.c:1:7: warning: data definition has no type or storage class
 s[99];i;main(h,w){for(scanf("%d%d",&h,&w);i<h+2;putchar(35),printf("%s",s),puts("#"))i++%-~h?scanf("%s",s):memset(s,35,w);}
       ^
./Main.c:1:7: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:9: warning: return type defaults to ‘int’ [-Wimplicit-int]
 s[99];i;main(h,w){for(scanf("%d%d",&h,&w);i<h+2;putchar(35),printf("%s",s),puts("#"))i++%-~h?scanf("%s",s):memset(s,35,w);}
         ^
./Main.c: In function ‘main’:
./Main.c:1:9: warning: type of ‘h’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:9: warning: type of ‘w’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:23: warning: implicit declaration of function ‘scanf’ [-Wimplicit-fun...