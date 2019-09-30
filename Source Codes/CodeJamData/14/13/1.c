#include<stdio.h>
#include<math.h>
double p1000[1000][1000],p3[3][1000];
/*
double q[1000];
int main(int argc,char*argv[]){
	int a,b,c,d,e,f,n;
	scanf("%d",&e);
	for(f=1;f<=e;f++){
		scanf("%d",&n);
		for(a=0;a<n;a++){
			for(b=0;b<n;b++){
				p[a][b]=0;
			}
			p[a][a]=1;
		}
		for(a=0;a<n;a++){
			for(c=0;c<n;c++){
				q[c]=p[a][c];
				p[a][c]=p[a][c]/(double)n;
			}
			for(b=0;b<n;b++){
				if(b==a){
					continue;
				}
				for(c=0;c<n;c++){
					p[a][c]+=p[b][c]/(double)n;
					p[b][c]=
					(p[b][c]*(n-1)+q[c])/(double)n;
				}
			}
		}
		for(a=0;a<n;a++){
			for(b=0;b<n;b++){
				printf("%.9lf ",p[a][b]);
			}
			putchar('\n');
		}
	}
}
*/
void readtable(){
	int a,b,n;
	n=1000;
	FILE*f;
	f=fopen("table1000.txt","r");
	for(a=0;a<n;a++){
		for(b=0;b<n;b++){
			fscanf(f,"%lf",p1000[a]+b);
		}
	}
	fclose(f);
	n=3;
	f=fopen("table3.txt","r");
	for(a=0;a<n;a++){
		for(b=0;b<n;b++){
			fscanf(f,"%lf",p3[a]+b);
		}
	}
	fclose(f);
}

int s[1000];

int main(int argc,char*argv[]){
	int a,e,f,n;
	double (*p)[1000];
	double x;
	readtable();
	scanf("%d",&e);
	for(f=1;f<=e;f++){
		scanf("%d",&n);
		if(n==1000)p=p1000;
		else if(n==3)p=p3;
		else continue;
		for(a=0;a<n;a++){
			scanf("%d",s+a);
		}
		x=1;
		for(a=0;a<n;a++){
			x*=(p[a][s[a]]*n);
		}
		//printf("  %.9lf\n",x);
		printf("Case #%d: ",f);
		puts(x<1?"GOOD":"BAD");
	}
	return 0;
}
