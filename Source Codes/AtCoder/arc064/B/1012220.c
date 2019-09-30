char s[1<<20];main(l){gets(s);l=strlen(s)-1;puts(l%2^s[0]==s[l]?"Second":"First");} ./Main.c:1:15: warning: return type defaults to ‘int’ [-Wimplicit-int]
 char s[1<<20];main(l){gets(s);l=strlen(s)-1;puts(l%2^s[0]==s[l]?"Second":"First");}
               ^
./Main.c: In function ‘main’:
./Main.c:1:15: warning: type of ‘l’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:23: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
 char s[1<<20];main(l){gets(s);l=strlen(s)-1;puts(l%2^s[0]==s[l]?"Second":"First");}
                       ^
./Main.c:1:33: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
 char s[1<<20];main(l){gets(s);l=strlen(s)-1;puts(l%2^s[0]==s[l]?"Second":"First");}
                                 ^
./Main.c:1:33: warning: incompatible implicit declaration of built-in function ‘strlen’
./Main.c:1:33: note: include ‘<string.h>’ or provide a declaration of ‘strlen’
./Main.c:1:45: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 char s[1<<20];main(l){gets(s);l=strlen(s)-1;puts(l%2^...