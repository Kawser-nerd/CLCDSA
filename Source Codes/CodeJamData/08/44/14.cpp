#include<cstdio>
#include<cstring>

int T,k,n;
char str[100000];
int opt[1<<17][20];
int i,j,p,l,ans,I;
int map[100][100],lj[100][100];
main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d\n",&k);
		gets(str);
		n=strlen(str);
		for (i=0;i<k;++i)
		    for (j=0;j<i;++j){
				map[i][j]=0;
				for (p=0;p<n;p+=k)
					if (str[p+j]==str[p+i]) map[i][j]++;
				map[j][i]=map[i][j];
				lj[i][j]=0;
				lj[j][i]=0;
				for (p=0;p+k<n;p+=k){
					if (str[p+i]==str[p+k+j]) lj[i][j]++;
					if (str[p+j]==str[p+k+i]) lj[j][i]++;
				}
			}
		ans=n;
		for (i=0;i<k;++i){
			for (j=0;j<(1<<k);++j)
			    for (p=0;p<k;++p)
			        opt[j][p]=100000;
			opt[1<<i][i]=n/k;
			for (j=1;j<(1<<k);++j)
				if (j&(1<<i))
				    for (l=0;l<k;++l)
				        if (j&(1<<l))
						for (p=0;p<k;++p)
				    	if (!(j&(1<<p)))
							opt[j^(1<<p)][p]<?=opt[j][l]+n/k-map[l][p];
			for (j=0;j<k;++j)
				ans<?=opt[(1<<k)-1][j]-lj[j][i];
		}
		printf("Case #%d: %d\n",++I,ans);
	}
}
