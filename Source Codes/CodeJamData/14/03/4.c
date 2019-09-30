#include <stdio.h>

int main(){
	int t,cas,r,c,m,i,j,k,l,low,high;
	scanf("%d",&t);
	for(cas=1;cas<=t;cas++){
		scanf("%d%d%d",&r,&c,&m);
		printf("Case #%d:\n",cas);
		if(r==1){
			for(i=0;i<m;i++)putchar('*');
			for(i=m;i<c-1;i++)putchar('.');
			puts("c");
			continue;
		}else if(c==1){
			for(i=0;i<m;i++)puts("*");
			for(i=m;i<r-1;i++)puts(".");
			puts("c");
			continue;
		}else if(m==r*c-1){
			for(i=1;i<=r;i++){
				for(j=1;j<=c;j++){
					putchar((i==r&&j==c)?'c':'*');
				}
				puts("");
			}
			continue;
		}
		for(i=0;i<=r-2;i++){
			for(j=0;j<=c-2;j++){
				low=r*c-(r-i)*(c-j);
				high=low+(r-2-i)*(c-2-j);
				if(low<=m&&m<=high){
					m-=low;
					for(k=1;k<=i;k++){
						for(l=1;l<=c;l++)putchar('*');
						puts("");
					}
					for(k=i+1;k<=r-2;k++){
						for(l=1;l<=j;l++)putchar('*');
						for(l=j+1;l<=c-2;l++){
							putchar(m>0?'*':'.');
							m--;
						}
						puts("..");
					}
					for(k=r-1;k<=r;k++){
						for(l=1;l<=j;l++)putchar('*');
						for(l=j+1;l<=c;l++)putchar((k==r&&l==c)?'c':'.');
						puts("");
					}
					goto END;
				}
			}
		}
		puts("Impossible");
		END:
		continue;
	}
	return 0;
}
