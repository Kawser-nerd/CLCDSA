#define _'			'
d[555][555],v[5]={0,1,0,-1};
a[_],b[_];
char s[555][555];
i,j;L;X,Y,x,y,c,r;
main(R,h,w){
	for(scanf("%d%d",&h,&w);gets(s[i]);i++)for(j=w;j--;)s[i][j]<110?s[i][j]>99?X=i,Y=j:0,d[i][j]=1e9:(*a=i,*b=j);
	for(;R>L;L++)
	{
		for(r=4;r;)
		{
			x=a[L%_]+v[r],y=b[L%_]+v[--r];
			x&&y>=0&x<=h&y<w&&d[x][y]>(c=(s[x][y]%7?1:1e6)+d[a[L%_]][b[L%_]])&&(d[a[R%_]=x][b[R++%_]=y]=c);
		}
	}
	puts(d[X][Y]<3e6?"YES":"NO");
} ./Main.c:1:10: warning: ISO C99 requires whitespace after the macro name
 #define _'   '
          ^
./Main.c:2:1: warning: data definition has no type or storage class
 d[555][555],v[5]={0,1,0,-1};
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘d’ [-Wimplicit-int]
./Main.c:2:13: warning: type defaults to ‘int’ in declaration of ‘v’ [-Wimplicit-int]
 d[555][555],v[5]={0,1,0,-1};
             ^
./Main.c:3:3: warning: multi-character character constant [-Wmultichar]
 a[_],b[_];
   ^
./Main.c:3:1: warning: data definition has no type or storage class
 a[_],b[_];
 ^
./Main.c:3:1: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:3:8: warning: multi-character character constant [-Wmultichar]
 a[_],b[_];
        ^
./Main.c:3:6: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
 a[_],b[_];
      ^
./Main.c:5:1: warning: data definition has no type or storage class
 i,j;L;X,Y,x,y,c,r;
 ^
./Main.c:5:1: warning: type defaults to ‘int’ in de...