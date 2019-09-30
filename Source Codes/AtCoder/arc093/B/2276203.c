a;main(b){
	scanf("%d%d",&a,&b);
	puts("99 99");
	for(int i=0;i<99;i++)
	{
		for(int j=0;j<99;j++)
		{
			putchar((i%2|j%2||(i<49?b--:a--)<2)^i>48?'.':'#');
		}
		puts("");
	}
} ./Main.c:1:1: warning: data definition has no type or storage class
 a;main(b){
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:1:3: warning: return type defaults to ‘int’ [-Wimplicit-int]
 a;main(b){
   ^
./Main.c: In function ‘main’:
./Main.c:1:3: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:2:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%d%d",&a,&b);
  ^
./Main.c:2:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:2:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:3:2: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
  puts("99 99");
  ^
./Main.c:8:4: warning: implicit declaration of function ‘putchar’ [-Wimplicit-function-declaration]
    putchar((i%2|j%2||(i<49?b--:a--)<2)^i>48?'.':'#');
    ^