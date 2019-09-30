int s[2][51];main(){scanf("%s%s",*s,s[1]);puts(strlen(*s)<strlen(s[1])?s[1]:*s);} ./Main.c:1:14: warning: return type defaults to ‘int’ [-Wimplicit-int]
 int s[2][51];main(){scanf("%s%s",*s,s[1]);puts(strlen(*s)<strlen(s[1])?s[1]:*s);}
              ^
./Main.c: In function ‘main’:
./Main.c:1:21: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 int s[2][51];main(){scanf("%s%s",*s,s[1]);puts(strlen(*s)<strlen(s[1])?s[1]:*s);}
                     ^
./Main.c:1:21: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:21: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:27: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘int *’ [-Wformat=]
 int s[2][51];main(){scanf("%s%s",*s,s[1]);puts(strlen(*s)<strlen(s[1])?s[1]:*s);}
                           ^
./Main.c:1:27: warning: format ‘%s’ expects argument of type ‘char *’, but argument 3 has type ‘int *’ [-Wformat=]
./Main.c:1:43: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 int s[2][51];m...