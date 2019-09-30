a=66;char s[];main(){gets(s);puts(s[1]-a?s[6]-a?"Si":"Mi":s[3]-a?s[8]-a?"La":"Re":s[5]-a?s[10]-a?"So":"Do":"Fa");} ./Main.c:1:1: warning: data definition has no type or storage class
 a=66;char s[];main(){gets(s);puts(s[1]-a?s[6]-a?"Si":"Mi":s[3]-a?s[8]-a?"La":"Re":s[5]-a?s[10]-a?"So":"Do":"Fa");}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:1:15: warning: return type defaults to ‘int’ [-Wimplicit-int]
 a=66;char s[];main(){gets(s);puts(s[1]-a?s[6]-a?"Si":"Mi":s[3]-a?s[8]-a?"La":"Re":s[5]-a?s[10]-a?"So":"Do":"Fa");}
               ^
./Main.c: In function ‘main’:
./Main.c:1:22: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
 a=66;char s[];main(){gets(s);puts(s[1]-a?s[6]-a?"Si":"Mi":s[3]-a?s[8]-a?"La":"Re":s[5]-a?s[10]-a?"So":"Do":"Fa");}
                      ^
./Main.c:1:30: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 a=66;char s[];main(){gets(s);puts(s[1]-a?s[6]-a?"Si":"Mi":s[3]-a?s[8]-a?"La":"Re":s[5]-a?s[10]-a?"So":"Do":"Fa");}
                              ^
./Main.c: At top level:
./Main.c:1...