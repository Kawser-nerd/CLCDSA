N,i,j,k;
long long A[301][301],inf=1e15,z;
main(){
	for(scanf("%d",&N);i++<N;){
		for(j=0;j++<N;){
			scanf("%d",A[i]+j);
		}
		A[i][i]=inf;
	}
	for(;k++<N;){
		for(i=0;i++<N;){
			if(A[i][k]!=inf){
				for(j=0;j++<N;){
					if(A[i][j]!=inf){
						if(A[i][j]>A[i][k]+A[k][j]){
							return!puts("-1");
						}
						if(A[i][j]==A[i][k]+A[k][j]){
							A[i][j]=inf;
						}
					}
				}
			}
		}
	}
	for(i=0;i++<N;){
		for(j=0;j++<N;){
			z+=A[i][j]==inf?0:A[i][j];
		}
	}
	printf("%lld",z/2);
} ./Main.c:1:1: warning: data definition has no type or storage class
 N,i,j,k;
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘N’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 N,i,j,k;
   ^
./Main.c:1:5: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 N,i,j,k;
     ^
./Main.c:1:7: warning: type defaults to ‘int’ in declaration of ‘k’ [-Wimplicit-int]
 N,i,j,k;
       ^
./Main.c:3:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:4:6: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  for(scanf("%d",&N);i++<N;){
      ^
./Main.c:4:6: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:4:6: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:6:10: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
    scanf("%...