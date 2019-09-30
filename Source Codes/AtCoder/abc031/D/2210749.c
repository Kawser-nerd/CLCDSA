int c[9],i,j,f,g,r;
char v[50][99],w[50][99],s[9][9],t[9];
main(k,n)
{
	for(scanf("%d%d",&k,&n);~scanf("%s%s",v+i++,w+i););
	for(;++j<k;)c[j]=1;
	for(;!f;){
		for(i=f=0;c[f]++>2;)c[f++]=1;
		for(f=1;i<n;f&=g==strlen(w[i++]))for(g=j=0;j<strlen(v[i]);)g+=c[v[i][j++]-'1'];
		if(f){
			for(i=0;i<k;)*s[i++]=0;
			for(i=0;i<n;i++)for(g=j=0;j<strlen(v[i]);g+=c[r])
			{
				r=v[i][j++]-'1';
				t[c[r]]=!strncpy(t,w[i]+g,c[r]);
				*s[r]?f&=!strcmp(s[r],t):strcpy(s[r],t);
			}
			for(i=0;f&i<k;)puts(s[i++]);
		}
	}
} ./Main.c:3:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(k,n)
 ^
./Main.c: In function ‘main’:
./Main.c:3:1: warning: type of ‘k’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:3:1: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:5:6: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  for(scanf("%d%d",&k,&n);~scanf("%s%s",v+i++,w+i););
      ^
./Main.c:5:6: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:5:6: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:5:33: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[99]’ [-Wformat=]
  for(scanf("%d%d",&k,&n);~scanf("%s%s",v+i++,w+i););
                                 ^
./Main.c:5:33: warning: format ‘%s’ expects argument of type ‘char *’, but argument 3 has type ‘char (*)[99]’ [-Wformat=]
./Main.c:9:21: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
   for(f=1;i...