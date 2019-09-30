int N,D,K;
int L[10000],R[10000];
main(){
	scanf("%d%d%d%*c",&N,&D,&K);
	for(int i=0;i<D;++i){
		scanf("%d%d%*c",L+i,R+i);
	}
	for(int j=0;j<K;++j){
		int S,T,i=0;
		scanf("%d%d%*c",&S,&T);
		for(;S<T;++i){
			if(L[i]<=S){
				S=fmax(S,fmin(R[i],T));
			}
		}
		for(;T<S;++i){
			if(S<=R[i]){
				S=fmin(S,fmax(L[i],T));
			}
		}
		printf("%d\n",i);
	}
} ./Main.c:3:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:4:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%d%d%d%*c",&N,&D,&K);
  ^
./Main.c:4:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:4:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:13:7: warning: implicit declaration of function ‘fmax’ [-Wimplicit-function-declaration]
     S=fmax(S,fmin(R[i],T));
       ^
./Main.c:13:7: warning: incompatible implicit declaration of built-in function ‘fmax’
./Main.c:13:7: note: include ‘<math.h>’ or provide a declaration of ‘fmax’
./Main.c:13:14: warning: implicit declaration of function ‘fmin’ [-Wimplicit-function-declaration]
     S=fmax(S,fmin(R[i],T));
              ^
./Main.c:13:14: warning: incompatible implicit declaration of built-in function ‘fmin’
./Main.c:13:14: note: include ‘<math.h>’ or provide a declaration of ‘fmin’
./Main.c:...