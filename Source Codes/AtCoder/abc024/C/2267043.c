#include<stdlib.h>
int N,D,K;
int L[10000],R[10000];
main(){
	scanf("%d%d%d%*c",&N,&D,&K);
	for(int i=0;i<D;++i){
		scanf("%d%d%*c",L+i,R+i);
	}
	for(int j=0;j<K;++j){
		int S,T;
		scanf("%d%d%*c",&S,&T);
		if(S<T){
			for(int i=0;i<D;++i){
				if(L[i]<=S&&S<R[i]){
					S=R[i];
				}
				if(T<=S){
					printf("%d\n",i+1);
					break;
				}
			}
		}else{
			for(int i=0;i<D;++i){
				if(S<=R[i]&&L[i]<S){
					S=L[i];
				}
				if(S<=T){
					printf("%d\n",i+1);
					break;
				}
			}
		}
	}
} ./Main.c:4:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:5:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%d%d%d%*c",&N,&D,&K);
  ^
./Main.c:5:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:5:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:18:6: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
      printf("%d\n",i+1);
      ^
./Main.c:18:6: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:18:6: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
./Main.c:28:6: warning: incompatible implicit declaration of built-in function ‘printf’
      printf("%d\n",i+1);
      ^
./Main.c:28:6: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’