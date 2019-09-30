#include<stdio.h>

FILE *out,*in;
int q[1100],g[1100],f[1100];
int t[2200],next[2200],h[2200];
int num;
const max=10000000;
void make(int x,int y){
	num++;
	t[num]=y;
	next[num]=h[x];
	h[x]=num;
	num++;
	t[num]=x;
	next[num]=h[y];
	h[y]=num;		
}
void init(void){
	int i;
	for (i=0;i<2200;i++){
		t[i]=0;
		h[i]=0;
		next[i]=0;
	}
}
void dg(int x){
	int i,j,k,xx;
	int tot=0,sum=0;
	q[x]=1;
	i=h[x];
	int w[1000];
	while(i!=0){
		if (q[t[i]]==0){
			tot++;
			w[tot]=t[i];
			dg(t[i]);
			sum+=g[t[i]];
		}
		i=next[i];
	}
	g[x]=sum+1;
	if (tot<2){
		f[x]=g[x]-1;
	}
	else {
		int min=max;
		int k;
		for(i=0;i<tot;i++){
			for(j=i+1;j<=tot;j++){
				k=sum-g[w[i]]-g[w[j]]+f[w[i]]+f[w[j]];	
				if (k<min) min=k;
			}
		} 
		f[x]=min;			
	}
}
int main(){
	in=fopen("a.in","r");
	out=fopen("a.out","w");
	int tt,ii,i,j,a,b;
	fscanf(in,"%d",&tt);
	for(ii=0;ii<tt;ii++){
		int n;
		int ans=max;
		num=0;
		init();
		fscanf(in,"%d",&n);
		for (i=1;i<n;i++){
			fscanf(in,"%d%d",&a,&b);
			make(a,b);
		}	
		
		for (i=1;i<=n;i++){
			for (j=0;j<=n;j++){
				q[j]=0;
				f[j]=max;
				g[j]=0;
			}
			dg(i);
			if (f[i]<ans) ans=f[i];
		}
		fprintf(out,"Case #%d: %d\n",ii+1,ans);
	}
	fclose(in);
	fclose(out);
	return 0;
}