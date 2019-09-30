char s[];main(){gets(s);puts(s[1]-'B'?s[6]-'B'?"Si":"Mi":s[3]-'B'?s[8]-'B'?"La":"Re":s[5]-'B'?s[10]-'B'?"So":"Do":"Fa");} ./Main.c:1:10: warning: return type defaults to ‘int’ [-Wimplicit-int]
 char s[];main(){gets(s);puts(s[1]-'B'?s[6]-'B'?"Si":"Mi":s[3]-'B'?s[8]-'B'?"La":"Re":s[5]-'B'?s[10]-'B'?"So":"Do":"Fa");}
          ^
./Main.c: In function ‘main’:
./Main.c:1:17: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
 char s[];main(){gets(s);puts(s[1]-'B'?s[6]-'B'?"Si":"Mi":s[3]-'B'?s[8]-'B'?"La":"Re":s[5]-'B'?s[10]-'B'?"So":"Do":"Fa");}
                 ^
./Main.c:1:25: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 char s[];main(){gets(s);puts(s[1]-'B'?s[6]-'B'?"Si":"Mi":s[3]-'B'?s[8]-'B'?"La":"Re":s[5]-'B'?s[10]-'B'?"So":"Do":"Fa");}
                         ^
./Main.c: At top level:
./Main.c:1:6: warning: array ‘s’ assumed to have one element
 char s[];main(){gets(s);puts(s[1]-'B'?s[6]-'B'?"Si":"Mi":s[3]-'B'?s[8]-'B'?"La":"Re":s[5]-'B'?s[10]-'B'?"So":"Do":"Fa");}
      ^
/tmp/ccqXXPgR.o: In function `main':
Main.c:(.text.startup+0xc): warning: the `gets'...