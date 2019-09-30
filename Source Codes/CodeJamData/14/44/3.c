#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int strptrcmp(char**a,char**b){
	return strcmp(*a,*b);
}

char s1[1000][128],*s2[1000];
int countnode(const char**z,int zc,int k){
	int a,b,c,d,ans;
	ans=1;
	b=0;
	for(a=1;1;a++){
		c=0;
		if(a!=zc){
			if(z[a][k]!=z[b][k])c=1;
		}
		else c=1;
		if(c==1){
			if(z[b][k]!='\0')ans+=countnode(z+b,a-b,k+1);
			b=a;
		}
		if(a==zc)break;
	}
	return ans;
}

int numtoassign(int k,int n,int m,int*t){
	int a;
	for(a=0;a<n;a++){
		t[a]=k%4;
		if(t[a]>=m)return 0;
		k/=4;
	}
	return 1;
}

int main(int argc,char*argv[]){
	int a,b,c,d,e,f,m,n,ans,max;
	int te[8];
	scanf("%d",&e);
	for(f=1;f<=e;f++){
		scanf("%d%d",&n,&m);
		for(a=0;a<n;a++){
			scanf("%s",s1[a]);
		}
		max=0;
		ans=0;
		for(a=0;a<(1<<(2*n));a++){
			if(numtoassign(a,n,m,te)==0)continue;
			int max2;
			max2=0;
			for(b=0;b<m;b++){
				int s2count;
				s2count=0;
				for(c=0;c<n;c++){
					if(te[c]!=b)continue;
					s2[s2count]=s1[c];
					s2count++;
				}
				if(s2count==0)continue;
				qsort(s2,s2count,sizeof(char*),strptrcmp);
				max2+=countnode(s2,s2count,0);
			}
			if(max2>max){
				max=max2;
				ans=0;
			}
			if(max2==max)ans++;
		}
		printf("Case #%d: %d %d\n",f,max,ans);
	}
	return 0;
}
