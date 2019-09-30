#define R for(g=0,p=v[i];*p;g+=c[r])r=*p++-'1'
c[9],i,f,g,r;
char*p,v[50][99],w[50][99],s[9][9],t[9];
main(n){
	for(scanf("%*d%d",&n);~scanf("%s%s",v+i++,w+i););
	for(;++g<9;)c[g]=1;
	for(;!f;){
		for(i=f=0;c[f]++>2;)c[f++]=1;
		for(f=1;i<n;f&=g==strlen(w[i++]))R;
		if(f){
			for(i=0;i<9;)*s[i++]=0;
			for(i=0;i<n;i++)R,t[c[r]]=!strncpy(t,w[i]+g,c[r]),*s[r]?f&=!strcmp(s[r],t):strcpy(s[r],t);
			for(i=0;f&&*s[i];)puts(s[i++]);
		}
	}
} ./Main.c:2:1: warning: data definition has no type or storage class
 c[9],i,f,g,r;
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
./Main.c:2:6: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 c[9],i,f,g,r;
      ^
./Main.c:2:8: warning: type defaults to ‘int’ in declaration of ‘f’ [-Wimplicit-int]
 c[9],i,f,g,r;
        ^
./Main.c:2:10: warning: type defaults to ‘int’ in declaration of ‘g’ [-Wimplicit-int]
 c[9],i,f,g,r;
          ^
./Main.c:2:12: warning: type defaults to ‘int’ in declaration of ‘r’ [-Wimplicit-int]
 c[9],i,f,g,r;
            ^
./Main.c:4:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(n){
 ^
./Main.c: In function ‘main’:
./Main.c:4:1: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:5:6: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  for(scanf("%*d%d",&n);~scanf("%s%s",v+i++,w+i););
      ^
./Main.c:5:6: warning: incompatible implicit declaration of...