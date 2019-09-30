char a[110];main(i){gets(a);scanf("%d",&i);printf("%c\n",a[i-1]);} ./Main.c:1:13: warning: return type defaults to ‘int’ [-Wimplicit-int]
 char a[110];main(i){gets(a);scanf("%d",&i);printf("%c\n",a[i-1]);}
             ^
./Main.c: In function ‘main’:
./Main.c:1:13: warning: type of ‘i’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:21: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
 char a[110];main(i){gets(a);scanf("%d",&i);printf("%c\n",a[i-1]);}
                     ^
./Main.c:1:29: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 char a[110];main(i){gets(a);scanf("%d",&i);printf("%c\n",a[i-1]);}
                             ^
./Main.c:1:29: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:29: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:44: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 char a[110];main(i){gets(a);scanf("%d",&i);printf("%c\n",a[i-1]);}
                                            ^
./Ma...