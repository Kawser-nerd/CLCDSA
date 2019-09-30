i,j;main(a){
	for(puts("98 99");i<98;i++)
	{
		i%49||scanf("%d",&a);
		for(int j=0;j<99;j++)
		{
			putchar((i%2|j%2||a--<2)^i>48?'#':'.');
		}
		puts("");
	}
} ./Main.c:1:1: warning: data definition has no type or storage class
 i,j;main(a){
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 i,j;main(a){
   ^
./Main.c:1:5: warning: return type defaults to ‘int’ [-Wimplicit-int]
 i,j;main(a){
     ^
./Main.c: In function ‘main’:
./Main.c:1:5: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:2:6: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
  for(puts("98 99");i<98;i++)
      ^
./Main.c:4:9: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   i%49||scanf("%d",&a);
         ^
./Main.c:4:9: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:4:9: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:7:4: warning: implicit declaration of function ‘putchar’ [-Wimplicit-function-declaration]
    putchar((i%2|j%2||a...