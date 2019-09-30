int m[2000][2000];
main(){
	int N,K;
	for(scanf("%d%d",&N,&K);N--;){
		int x,y;char c;
		scanf("%d%d%*c%c",&x,&y,&c);
		if(c=='W'){x+=K;}
		for(int i=0;i<2;++i){
			x%=2*K;
			y%=2*K;
			if(x<K){
				if(y<K){
					++m[y][x];
					--m[y][x+K];
					--m[y+K][x];
					++m[y+K][x+K];
				}else{
					++m[y][x];
					--m[y][x+K];
					
					++m[0][x];
					--m[0][x+K];
					--m[y-K][x];
					++m[y-K][x+K];
				}
			}else{
				if(y<K){
					++m[y][x];
					--m[y+K][x];
					
					++m[y][0];
					--m[y][x-K];
					--m[y+K][0];
					++m[y+K][x-K];
				}else{
					++m[y][x];
					
					++m[y][0];
					--m[y][x-K];
					
					++m[0][x];
					--m[y-K][x];
					
					++m[0][0];
					--m[0][x-K];
					--m[y-K][0];
					++m[y-K][x-K];
				}
			}
			x+=K;
			y+=K;
		}
	}
	for(int y=0;y<2*K;++y){
		for(int x=1;x<2*K;++x){
			m[y][x]+=m[y][x-1];
		}
	}
	int z=0;
	for(int x=0;x<2*K;++x){
		for(int y=0;y<2*K;++y){
			if(y){
				m[y][x]+=m[y-1][x];
			}
			if(m[y][x]>z){
				z=m[y][x];
			}
		}
	}
	printf("%d",z);
} ./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:4:6: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  for(scanf("%d%d",&N,&K);N--;){
      ^
./Main.c:4:6: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:4:6: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:70:2: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
  printf("%d",z);
  ^
./Main.c:70:2: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:70:2: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’