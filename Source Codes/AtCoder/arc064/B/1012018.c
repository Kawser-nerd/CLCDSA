char s[1<<20];l;main(){gets(s);l=strlen(s)-1;puts(l%2^s[0]==s[l]?"Second":"First");} ./Main.c:1:15: warning: data definition has no type or storage class
 char s[1<<20];l;main(){gets(s);l=strlen(s)-1;puts(l%2^s[0]==s[l]?"Second":"First");}
               ^
./Main.c:1:15: warning: type defaults to ‘int’ in declaration of ‘l’ [-Wimplicit-int]
./Main.c:1:17: warning: return type defaults to ‘int’ [-Wimplicit-int]
 char s[1<<20];l;main(){gets(s);l=strlen(s)-1;puts(l%2^s[0]==s[l]?"Second":"First");}
                 ^
./Main.c: In function ‘main’:
./Main.c:1:24: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
 char s[1<<20];l;main(){gets(s);l=strlen(s)-1;puts(l%2^s[0]==s[l]?"Second":"First");}
                        ^
./Main.c:1:34: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
 char s[1<<20];l;main(){gets(s);l=strlen(s)-1;puts(l%2^s[0]==s[l]?"Second":"First");}
                                  ^
./Main.c:1:34: warning: incompatible implicit declaration of built-in function ‘strlen’
./Main.c:1:34: note: include ‘<strin...