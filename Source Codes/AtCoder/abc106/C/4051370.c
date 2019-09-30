n,i;char s[111];main(){scanf("%s%d",s,&n);while(n--){if(s[i]!='1'){printf("%c\n",s[i]);return 0;}i++;}puts("1");} ./Main.c:1:1: warning: data definition has no type or storage class
 n,i;char s[111];main(){scanf("%s%d",s,&n);while(n--){if(s[i]!='1'){printf("%c\n",s[i]);return 0;}i++;}puts("1");}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 n,i;char s[111];main(){scanf("%s%d",s,&n);while(n--){if(s[i]!='1'){printf("%c\n",s[i]);return 0;}i++;}puts("1");}
   ^
./Main.c:1:17: warning: return type defaults to ‘int’ [-Wimplicit-int]
 n,i;char s[111];main(){scanf("%s%d",s,&n);while(n--){if(s[i]!='1'){printf("%c\n",s[i]);return 0;}i++;}puts("1");}
                 ^
./Main.c: In function ‘main’:
./Main.c:1:24: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 n,i;char s[111];main(){scanf("%s%d",s,&n);while(n--){if(s[i]!='1'){printf("%c\n",s[i]);return 0;}i++;}puts("1");}
                        ^
./Main.c:1:24: warning: incompatible implicit declaration of built-in fun...