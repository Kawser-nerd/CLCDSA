char s[8002];
x,y;
d[2][40000];
t[40000];
i,j,f,l;
main(){
	scanf("%s%d%d",s,&x,&y);
	s[strlen(s)]='T';
	s[strlen(s)]=0;
	for(i=0;s[i]=='F';++i);
	d[0][20000+i]=1;
	d[1][20000+0]=1;
	for(;s[i];++i){
		if(s[i]=='F'){
			++l;
		}else{
			for(j=-8000;j<=8000;++j)t[20000+j]=0;
			for(j=-8000;j<=8000;++j){
				if(d[f][20000+j]){
					t[20000+j+l]=1;
					t[20000+j-l]=1;
				}
			}
			for(j=-8000;j<=8000;++j)d[f][20000+j]=t[20000+j];
			l=0;
			f^=1;
		}
	}
	puts(d[0][20000+x]&&d[1][20000+y]?"Yes":"No");
} ./Main.c:2:1: warning: data definition has no type or storage class
 x,y;
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘x’ [-Wimplicit-int]
./Main.c:2:3: warning: type defaults to ‘int’ in declaration of ‘y’ [-Wimplicit-int]
 x,y;
   ^
./Main.c:3:1: warning: data definition has no type or storage class
 d[2][40000];
 ^
./Main.c:3:1: warning: type defaults to ‘int’ in declaration of ‘d’ [-Wimplicit-int]
./Main.c:4:1: warning: data definition has no type or storage class
 t[40000];
 ^
./Main.c:4:1: warning: type defaults to ‘int’ in declaration of ‘t’ [-Wimplicit-int]
./Main.c:5:1: warning: data definition has no type or storage class
 i,j,f,l;
 ^
./Main.c:5:1: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:5:3: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 i,j,f,l;
   ^
./Main.c:5:5: warning: type defaults to ‘int’ in declaration of ‘f’ [-Wimplicit-int]
 i,j,f,l;
     ^
./Main.c:5:7: warning: type defaults to ‘int’ in decla...