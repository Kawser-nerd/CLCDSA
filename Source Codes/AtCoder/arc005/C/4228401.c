#define _'			'
d[555][555],v[_]={0,1,0,-1};a[_],b[_];char s[555][555];i,j;L;X,Y,x,y,c,r=4;main(R,h,w){for(scanf("%d%d",&h,&w);gets(s[i]);i++)for(j=w;c=s[i][--j];c<110?c>99?X=i,Y=j:0,d[i][j]=1e9:(*a=i,*b=j));for(;r?:(r=4,R>++L);)(c=d[x=a[L%_]][y=b[L%_]]+(s[x+=v[r]][y+=v[--r]]%7?1:_))<d[x][y]&&(d[a[R%_]=x][b[R++%_]=y]=c);puts(d[X][Y]<3*_?"YES":"NO");} ./Main.c:1:10: warning: ISO C99 requires whitespace after the macro name
 #define _'   '
          ^
./Main.c:2:1: warning: data definition has no type or storage class
 d[555][555],v[_]={0,1,0,-1};a[_],b[_];char s[555][555];i,j;L;X,Y,x,y,c,r=4;main(R,h,w){for(scanf("%d%d",&h,&w);gets(s[i]);i++)for(j=w;c=s[i][--j];c<110?c>99?X=i,Y=j:0,d[i][j]=1e9:(*a=i,*b=j));for(;r?:(r=4,R>++L);)(c=d[x=a[L%_]][y=b[L%_]]+(s[x+=v[r]][y+=v[--r]]%7?1:_))<d[x][y]&&(d[a[R%_]=x][b[R++%_]=y]=c);puts(d[X][Y]<3*_?"YES":"NO");}
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘d’ [-Wimplicit-int]
./Main.c:2:15: warning: multi-character character constant [-Wmultichar]
 d[555][555],v[_]={0,1,0,-1};a[_],b[_];char s[555][555];i,j;L;X,Y,x,y,c,r=4;main(R,h,w){for(scanf("%d%d",&h,&w);gets(s[i]);i++)for(j=w;c=s[i][--j];c<110?c>99?X=i,Y=j:0,d[i][j]=1e9:(*a=i,*b=j));for(;r?:(r=4,R>++L);)(c=d[x=a[L%_]][y=b[L%_]]+(s[x+=v[r]][y+=v[--r]]%7?1:_))<d[x][y]&&(d[a[R%_]=x][b[R++%_]=y]=c);puts(d[X][Y]<3*_?"YES":"NO");}
               ^
....