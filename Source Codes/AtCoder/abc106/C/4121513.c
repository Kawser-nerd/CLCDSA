char a[110];main(){gets(a);long k;scanf("%ld",&k);int i=0;while(a[i]=='1')i++;if(k>i)printf("%c\n",a[i]);else puts("1");} ./Main.c:1:13: warning: return type defaults to ‘int’ [-Wimplicit-int]
 char a[110];main(){gets(a);long k;scanf("%ld",&k);int i=0;while(a[i]=='1')i++;if(k>i)printf("%c\n",a[i]);else puts("1");}
             ^
./Main.c: In function ‘main’:
./Main.c:1:20: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
 char a[110];main(){gets(a);long k;scanf("%ld",&k);int i=0;while(a[i]=='1')i++;if(k>i)printf("%c\n",a[i]);else puts("1");}
                    ^
./Main.c:1:35: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 char a[110];main(){gets(a);long k;scanf("%ld",&k);int i=0;while(a[i]=='1')i++;if(k>i)printf("%c\n",a[i]);else puts("1");}
                                   ^
./Main.c:1:35: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:35: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:86: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 char a[110];main()...