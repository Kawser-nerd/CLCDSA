main(i,a){char n[101];scanf("%s",n);a=strlen(n)-1;for(i=0; i<=a/2; i++){if(n[i]!=n[a-i]){puts("NO");return 0;}}puts("YES");} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(i,a){char n[101];scanf("%s",n);a=strlen(n)-1;for(i=0; i<=a/2; i++){if(n[i]!=n[a-i]){puts("NO");return 0;}}puts("YES");}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘i’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:23: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(i,a){char n[101];scanf("%s",n);a=strlen(n)-1;for(i=0; i<=a/2; i++){if(n[i]!=n[a-i]){puts("NO");return 0;}}puts("YES");}
                       ^
./Main.c:1:23: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:23: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:39: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
 main(i,a){char n[101];scanf("%s",n);a=strlen(n)-1;for(i=0; i<=a/2; i++){if(n[i]!=n[a-i]){puts("NO");return 0;}}puts("YES");}
               ...