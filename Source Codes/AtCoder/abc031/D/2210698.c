int k,n,c[9];
char v[50][99],w[50][99],s[9][99];
main()
{
	scanf("%d%d",&k,&n);
	for(int i=0;~scanf("%s%s",v+i++,w+i););
	for(int i=0;++i<k;)c[i]=1;
	for(;;){
		int f=0;
		for(;c[f]==3;f++)c[f]=1;
		c[f]++;
		f=1;
		for(int i=0;f&&i<n;i++)
		{
			int now=0;
			for(int j=0;j<strlen(v[i]);j++)
			{
				now+=c[v[i][j]-'1'];
			}
			f&=now==strlen(w[i]);
		}
		if(!f)continue;
		for(int i=0;i<k;i++)strcpy(s[i],"");
		f=1;
		for(int i=0;f&&i<n;i++)
		{
			int l=0;
			for(int j=0;f&&j<strlen(v[i]);j++)
			{
				char t[99];
				strncpy(t,w[i]+l,c[v[i][j]-'1']);t[c[v[i][j]-'1']]=0;
				if(!strcmp(s[v[i][j]-'1'],""))strcpy(s[v[i][j]-'1'],t);
				else f&=!strcmp(s[v[i][j]-'1'],t);
				l+=c[v[i][j]-'1'];
			}
		}
		if(f){
			for(int i=0;i<k;)puts(s[i++]);
			return 0;
		}
	}
} ./Main.c:3:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main()
 ^
./Main.c: In function ‘main’:
./Main.c:5:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%d%d",&k,&n);
  ^
./Main.c:5:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:5:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:6:21: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[99]’ [-Wformat=]
  for(int i=0;~scanf("%s%s",v+i++,w+i););
                     ^
./Main.c:6:21: warning: format ‘%s’ expects argument of type ‘char *’, but argument 3 has type ‘char (*)[99]’ [-Wformat=]
./Main.c:16:18: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
    for(int j=0;j<strlen(v[i]);j++)
                  ^
./Main.c:16:18: warning: incompatible implicit declaration of built-in function ‘strlen’
./Main.c:16:18: note: include ‘<string.h>’ or provide a declaration...