main(a,b){b=0;scanf("%c %c",&a,&b);puts(a^b?"D":"H");} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(a,b){b=0;scanf("%c %c",&a,&b);puts(a^b?"D":"H");}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:15: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(a,b){b=0;scanf("%c %c",&a,&b);puts(a^b?"D":"H");}
               ^
./Main.c:1:15: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:15: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:21: warning: format ‘%c’ expects argument of type ‘char *’, but argument 2 has type ‘int *’ [-Wformat=]
 main(a,b){b=0;scanf("%c %c",&a,&b);puts(a^b?"D":"H");}
                     ^
./Main.c:1:21: warning: format ‘%c’ expects argument of type ‘char *’, but argument 3 has type ‘int *’ [-Wformat=]
./Main.c:1:36: warning: implicit declaration of function ‘puts’ [-Wimplicit-func...