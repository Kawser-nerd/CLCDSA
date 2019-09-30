unsigned long long d[2000*2000/64+1]={1};
N,A,S,i;
main(){
	for(scanf("%d",&N);N--;){
		scanf("%d",&A);
		S+=A;
		for(i=S/64;i>=0;--i){
			d[i+A/64]|=d[i]<<A%64;
			if(A%64){
				d[i+A/64+1]|=d[i]>>64-A%64;
			}
		}
	}
	for(i=-~S/2;;++i){
		if(d[i/64]>>i%64&1){
			printf("%d\n",i);
			break;
		}
	}
} ./Main.c:2:1: warning: data definition has no type or storage class
 N,A,S,i;
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘N’ [-Wimplicit-int]
./Main.c:2:3: warning: type defaults to ‘int’ in declaration of ‘A’ [-Wimplicit-int]
 N,A,S,i;
   ^
./Main.c:2:5: warning: type defaults to ‘int’ in declaration of ‘S’ [-Wimplicit-int]
 N,A,S,i;
     ^
./Main.c:2:7: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 N,A,S,i;
       ^
./Main.c:3:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:4:6: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  for(scanf("%d",&N);N--;){
      ^
./Main.c:4:6: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:4:6: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:16:4: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
    printf("%d\n",i);
    ^
./Main.c:...