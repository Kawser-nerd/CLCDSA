c(int*a,int*b){return strcmp(a,b);}s[9999];i;j;main(){for(scanf("%*d%*d");~scanf("%s",s+i*32);)i++;for(qsort(s,i,128,c);j-i;)printf("%s",s+32*j++);} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 c(int*a,int*b){return strcmp(a,b);}s[9999];i;j;main(){for(scanf("%*d%*d");~scanf("%s",s+i*32);)i++;for(qsort(s,i,128,c);j-i;)printf("%s",s+32*j++);}
 ^
./Main.c: In function ‘c’:
./Main.c:1:23: warning: implicit declaration of function ‘strcmp’ [-Wimplicit-function-declaration]
 c(int*a,int*b){return strcmp(a,b);}s[9999];i;j;main(){for(scanf("%*d%*d");~scanf("%s",s+i*32);)i++;for(qsort(s,i,128,c);j-i;)printf("%s",s+32*j++);}
                       ^
./Main.c: At top level:
./Main.c:1:36: warning: data definition has no type or storage class
 c(int*a,int*b){return strcmp(a,b);}s[9999];i;j;main(){for(scanf("%*d%*d");~scanf("%s",s+i*32);)i++;for(qsort(s,i,128,c);j-i;)printf("%s",s+32*j++);}
                                    ^
./Main.c:1:36: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
./Main.c:1:44: warning: data definition has no type or storage class
 c(int*a,int*b){return strcmp(a,b);}s[9999];i;j;main(){for(scan...