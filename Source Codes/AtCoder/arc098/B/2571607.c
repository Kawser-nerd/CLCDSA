long a[2<<17],S,w,m;f,i;
main(){
	for(gets(a);~scanf("%d",a+i);S+=++i-f)for(w^=a[i],m+=a[i];w-m;w^=a[f++])m-=a[f];
	printf("%ld",S);
} ./Main.c:1:21: warning: data definition has no type or storage class
 long a[2<<17],S,w,m;f,i;
                     ^
./Main.c:1:21: warning: type defaults to ‘int’ in declaration of ‘f’ [-Wimplicit-int]
./Main.c:1:23: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 long a[2<<17],S,w,m;f,i;
                       ^
./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:3:6: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  for(gets(a);~scanf("%d",a+i);S+=++i-f)for(w^=a[i],m+=a[i];w-m;w^=a[f++])m-=a[f];
      ^
./Main.c:3:15: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  for(gets(a);~scanf("%d",a+i);S+=++i-f)for(w^=a[i],m+=a[i];w-m;w^=a[f++])m-=a[f];
               ^
./Main.c:3:15: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:3:15: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:3:21: ...