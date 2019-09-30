#include <stdio.h>
char s[10008];
int a[10008],b[10008];
int I[8],J[8][8],K[8];

int main(){
	int t,tt,l,i,j,k,tmp,f,flg,fr;
	long long x,tmp2;
	int tab[8][8]={{0,1,2,3,4,5,6,7},{1,4,3,6,5,0,7,2},{2,7,4,1,6,3,0,5},{3,2,5,4,7,6,1,0},
	{4,5,6,7,0,1,2,3},{5,0,7,2,1,4,3,6},{6,3,0,5,2,7,4,1},{7,6,1,0,3,2,5,4}};
	scanf("%d",&t);
	for(tt=1;tt<=t;tt++){
		scanf("%d%lld",&l,&x);
		scanf("%s",s);
		a[0]=0;
		for(i=0;i<l;i++)a[i+1]=tab[a[i]][s[i]-'h'];
		f=a[l];
		b[l]=0;
		for(i=l-1;i>=0;i--)b[i]=tab[s[i]-'h'][b[i+1]];
		tmp=0;
		for(k=1;k<=4;k++){
			tmp=tab[tmp][f];
			if(tmp==0){fr=k;break;}
		}
		for(i=0;i<8;i++){
			tmp=i;I[i]=-1;
			for(k=0;k<fr;k++){
				if(tmp==1){I[i]=k;break;}
				tmp=tab[f][tmp];
			}
		}
		for(i=0;i<8;i++)for(j=0;j<8;j++){
			tmp=i;J[i][j]=-1;
			for(k=0;k<fr;k++){
				if(tab[tmp][j]==2){J[i][j]=k;break;}
				tmp=tab[tmp][f];
			}
		}
		for(j=0;j<8;j++){
			tmp=j;K[j]=-1;
			for(k=0;k<fr;k++){
				if(tmp==3){K[j]=k;break;}
				tmp=tab[tmp][f];
			}
		}
		flg=0;
		for(i=0;i<=l;i++){
			tmp=0;
			for(j=i+1;j<=l;j++){
				tmp=tab[tmp][s[j-1]-'h'];
				if(tmp==2){
					if(I[a[i]]>=0&&K[b[j]]>=0){
						tmp2=x-I[a[i]]-K[b[j]]-1;
						if(tmp2>=0&&tmp2%fr==0){
							flg=1;goto END;
						}
					}
				}
			}
		}
		for(i=0;i<=l;i++){
			for(j=0;j<=l;j++){
				if(I[a[i]]>=0&&J[b[i]][a[j]]>=0&&K[b[j]]>=0){
					tmp2=x-I[a[i]]-J[b[i]][a[j]]-K[b[j]]-2;
					if(tmp2>=0&&tmp2%fr==0){
						flg=1;goto END;
					}
				}
			}
		}
		END:
		printf("Case #%d: %s\n",tt,flg?"YES":"NO");
	}
	return 0;
}
