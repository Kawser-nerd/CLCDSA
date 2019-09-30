int b[2][3],c[3][2],m[3][3];
int f(int d){
	int s=0,u=0;
	if(d==9){
		for(int x=0;x<3;++x){
			for(int y=0;y<2;++y){
				if(m[y][x]==m[y+1][x]){
					s+=b[y][x];
				}
			}
		}
		for(int y=0;y<3;++y){
			for(int x=0;x<2;++x){
				if(m[y][x]==m[y][x+1]){
					s+=c[y][x];
				}
			}
		}
	}else{
		for(int y=0;y<3;++y){
			for(int x=0;x<3;++x){
				if(!m[y][x]){
					m[y][x]=d%2?-1:1;
					int t=f(d+1);
					m[y][x]=0;
					if(d%2){
						if(!u||t<s){
							s=t;
							u=1;
						}
					}else{
						if(!u||t>s){
							s=t;
							u=1;
						}
					}
				}
			}
		}
	}
	return s;
}
main(){
	int s=0;
	for(int y=0;y<2;++y){
		for(int x=0;x<3;++x){
			scanf("%d",b[y]+x);
			s+=b[y][x];
		}
	}
	for(int y=0;y<3;++y){
		for(int x=0;x<2;++x){
			scanf("%d",c[y]+x);
			s+=c[y][x];
		}
	}
	printf("%d\n%d\n",f(0),s-f(0));
} ./Main.c:43:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:47:4: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
    scanf("%d",b[y]+x);
    ^
./Main.c:47:4: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:47:4: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:53:4: warning: incompatible implicit declaration of built-in function ‘scanf’
    scanf("%d",c[y]+x);
    ^
./Main.c:53:4: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:57:2: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
  printf("%d\n%d\n",f(0),s-f(0));
  ^
./Main.c:57:2: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:57:2: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’