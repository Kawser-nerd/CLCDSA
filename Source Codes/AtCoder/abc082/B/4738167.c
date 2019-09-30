c(char*a,char*b){return *a-*b;}r(char*a,char*b){return *b-*a;}s[2][30];n;main(m){scanf("%s%s",s,s[1]);n=strlen(s);m=strlen(s[1]);qsort(s,n,1,c);qsort(s[1],m,1,r);puts(bcmp(s,s[1],n>m?n:m)<0?"Yes":"No");} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 c(char*a,char*b){return *a-*b;}r(char*a,char*b){return *b-*a;}s[2][30];n;main(m){scanf("%s%s",s,s[1]);n=strlen(s);m=strlen(s[1]);qsort(s,n,1,c);qsort(s[1],m,1,r);puts(bcmp(s,s[1],n>m?n:m)<0?"Yes":"No");}
 ^
./Main.c:1:32: warning: return type defaults to ‘int’ [-Wimplicit-int]
 c(char*a,char*b){return *a-*b;}r(char*a,char*b){return *b-*a;}s[2][30];n;main(m){scanf("%s%s",s,s[1]);n=strlen(s);m=strlen(s[1]);qsort(s,n,1,c);qsort(s[1],m,1,r);puts(bcmp(s,s[1],n>m?n:m)<0?"Yes":"No");}
                                ^
./Main.c:1:63: warning: data definition has no type or storage class
 c(char*a,char*b){return *a-*b;}r(char*a,char*b){return *b-*a;}s[2][30];n;main(m){scanf("%s%s",s,s[1]);n=strlen(s);m=strlen(s[1]);qsort(s,n,1,c);qsort(s[1],m,1,r);puts(bcmp(s,s[1],n>m?n:m)<0?"Yes":"No");}
                                                               ^
./Main.c:1:63: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
./Main.c:1:...