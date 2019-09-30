#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int a[101][101];
char t[101][101];

int comp(const void *p,const void *q){
	return *(int *)p-*(int *)q;
}

int main(){
	int tt,ttt,n,i,j,cnt,f,res;
	char s[101],tmp;
	scanf("%d",&tt);
	for(ttt=1;ttt<=tt;ttt++){
		f=1;res=0;
		memset(a,0,sizeof(a));
		memset(t,0,sizeof(t));
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%s",s);
			cnt=0;tmp=0;
			for(j=0;j<strlen(s);j++){
				if(tmp!=s[j]){
					a[cnt][i]=1;
					t[i][cnt++]=s[j];
					tmp=s[j];
				}else a[cnt-1][i]++;
			}
		}
		for(i=1;i<n;i++){
			if(memcmp(t[0],t[i],100)){f=0;goto END;}
		}
		for(i=0;i<cnt;i++){
			qsort(a[i],n,4,comp);
			for(j=0;j<n;j++){
				res+=abs(a[i][j]-a[i][n/2]);
			}
		}
		END:
		printf("Case #%d: ",ttt);
		if(f)printf("%d\n",res);
		else puts("Fegla Won");
	}
	return 0;
}
