main(void)
{
  char a,b;
  scanf("%c %c",&a,&b);
  puts(a==b?"H":"D");
} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(void)
 ^
./Main.c: In function ‘main’:
./Main.c:4:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%c %c",&a,&b);
   ^
./Main.c:4:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:4:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:5:3: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
   puts(a==b?"H":"D");
   ^