#include<stdio.h>

int main(){
		int n,m,i,ans=0;
		int a[1000][3];
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++){
				scanf("%d%d",&a[i][0],&a[i][1]);
				a[i][2]=0;
		}
		for(i=0;i<m;i++){
				a[i][2]=1;
				int p[10000]={0},j,flag[51]={0};
				p[0]=a[i][0];flag[a[i][0]-1]=1;
				int st=0,fin=1;
				while(st<=fin){
						for(j=0;j<m;j++){
								if((p[st]==a[j][0]&&a[j][2]!=1&&flag[a[j][1]-1]!=1)){
							//			printf("%d %d\n",a[j][0],a[j][1]);
										p[fin]=a[j][1];
										flag[a[j][1]-1]=1;
										fin++;
								}
								if((p[st]==a[j][1]&&a[j][2]!=1&&flag[a[j][0]-1]!=1)){
							//			printf("%d %d\n",a[j][1],a[j][0]);
										p[fin]=a[j][0];
										flag[a[j][0]-1]=1;
										fin++;
								}
						}
						st++;
				}
				a[i][2]=0;
				int f=0;
				for(j=0;j<n;j++){
	//					printf("%d\n",flag[j]);
						if(flag[j]==0)f=1;
						if(flag[j]==1){
								flag[j]=0;
						}
				}
				if(f==1)ans++;
		}
		printf("%d\n",ans);
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a[i][0],&a[i][1]);
     ^