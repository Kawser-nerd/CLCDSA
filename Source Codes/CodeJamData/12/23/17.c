int g[21][2000001];
int f[21][2000001],h[21][2000001];
int s1[2][21],sc[2];
int a[21];
void print(int i, int u, int c){
	if(i==0)return;
	int a=f[i][u];
	switch(h[i][u]){
		case 1:s1[!c][sc[!c]++]=a-u;
		       break;
		case 2:s1[c][sc[c]++]=a+u;
		       c=!c;
		       break;
		case 3:s1[c][sc[c]++]=u-a;
		       break;
		case 4: break;
	}
	print(i-1,a,c);
}
int main(){
	int n,t,p;
	scanf("%d", &t);
	for(p=1;p<=t;p++){
		scanf("%d",&n);
		printf("Case #%d: \n", p);
		int i;
		int j;
		for(i=0;i<n;i++)scanf("%d",a+i);
		memset(g,0,sizeof(g));
		g[0][0]=1;
		sc[0]=sc[1]=0;
		for(i=0;i<n;i++){
			for(j=0;j<=2000000;j++)
				if(g[i][j]){
					if(j>a[i]){
						g[i+1][j-a[i]]=1;
						f[i+1][j-a[i]]=j;
						h[i+1][j-a[i]]=1;
					}
					else{
						g[i+1][a[i]-j]=1;
						f[i+1][a[i]-j]=j;
						h[i+1][a[i]-j]=2;
					}
					if(g[i+1][0])break;
					g[i+1][j+a[i]]=1;
					f[i+1][j+a[i]]=j;
					h[i+1][j+a[i]]=3;
					if(i!=0){
						g[i+1][j]=1;
						h[i+1][j]=4;
						f[i+1][j]=j;
					}
				}
			if(g[i+1][0])break;
		}
		print(i+1,0,0);
		for(i=0;i<sc[0];i++)printf("%d ",s1[0][i]);
		printf("\n");
		for(i=0;i<sc[1];i++)printf("%d ",s1[1][i]);
		printf("\n");
	}
	return 0;
}
