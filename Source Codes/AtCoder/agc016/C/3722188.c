#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

int main(){
	int H,W,h,w;
	scanf("%d%d%d%d",&H,&W,&h,&w);
	if(H%h==0&&W%w==0){
		puts("No");
		return 0;
	}
	puts("Yes");
	rep(i,1,H+1){
		rep(j,1,W+1)printf("%d ",i%h==0&&j%w==0?-1-4000*(h*w-1):4000);
		puts("");
	}
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%d%d%d%d",&H,&W,&h,&w);
  ^
./Main.c:6:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:6:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:8:3: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
   puts("No");
   ^
./Main.c:13:15: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
   rep(j,1,W+1)printf("%d ",i%h==0&&j%w==0?-1-4000*(h*w-1):4000);
               ^
./Main.c:13:15: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:13:15: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’