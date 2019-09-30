#include<stdio.h>
int n,m,d[100010],ta[200010],nt[400010],to[400010],co[400010],q[100010],u[100010]={};
int main(){
	int a,b,c,r,t,i,j;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)ta[i+1]=-1;
	for(i=0;i<m;i++){
		scanf("%d %d %d",&a,&b,&c);
		nt[i  ]=ta[to[i+m]=a];
		nt[i+m]=ta[to[i  ]=b];
		co[ta[a]=i  ]= c;
		co[ta[b]=i+m]=-c;
	}
	for(i=1;i<=n;i++){
		if(u[i])continue;
		u[q[t=0]=i]=1;
		d[i]=0;
		for(r=1;r-t;t++){//printf(":%d %d\n",q[t],d[q[t]]);
			for(j=ta[q[t]];j+1;j=nt[j]){//printf("%d %d %d\n",q[t],to[j],co[j]);
				if(u[to[j]]){
					if(d[to[j]]-d[q[t]]-co[j])goto END;
				}
				else u[q[r++]=to[j]]=1;
				d[to[j]]=d[q[t]]+co[j];
			}
		}
	}
	printf("Yes\n");
	return 0;
	END:;
	//for(i=0;i<n;i++)printf("%d ",d[i+1]);printf("\n");
	printf("No\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&m);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&a,&b,&c);
   ^