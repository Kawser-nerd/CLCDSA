int main(void){
	int i,x,y,tmp;
	int ans=1000000;

	scanf("%d", &i );
	for( x = 1; x <= sqrt(i) ; x++ ){
		y =  i / x ;
		tmp = y - x + i - (y * x);
		if (tmp < ans ){	
		ans = tmp;
		}
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%d", &i );
  ^
./Main.c:5:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:5:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:6:19: warning: implicit declaration of function ‘sqrt’ [-Wimplicit-function-declaration]
  for( x = 1; x <= sqrt(i) ; x++ ){
                   ^
./Main.c:6:19: warning: incompatible implicit declaration of built-in function ‘sqrt’
./Main.c:6:19: note: include ‘<math.h>’ or provide a declaration of ‘sqrt’
./Main.c:13:2: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
  printf("%d\n", ans);
  ^
./Main.c:13:2: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:13:2: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’