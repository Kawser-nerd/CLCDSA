#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
	char color;
	int n;
} Type;

void impossible(){
	printf("IMPOSSIBLE\n");
}

int main(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		int N,R,O,Y,G,B,V;
		scanf("%d %d %d %d %d %d %d\n",&N,&R,&O,&Y,&G,&B,&V);
		Type a,b,c,d,e,f;
		R-=G;
		Y-=V;
		B-=O;
		if(R<Y){
			if(Y<B){
				a.color='B';
				a.n=B;
				b.color='Y';
				b.n=Y;
				c.color='R';
				c.n=R;
				d.color='O';
				d.n=O;
				e.color='V';
				e.n=V;
				f.color='G';
				f.n=G;
			}else if(B<R){
				a.color='Y';
				a.n=Y;
				b.color='R';
				b.n=R;
				c.color='B';
				c.n=B;
				d.color='V';
				d.n=V;
				e.color='G';
				e.n=G;
				f.color='O';
				f.n=O;
			}else{
				a.color='Y';
				a.n=Y;
				b.color='B';
				b.n=B;
				c.color='R';
				c.n=R;
				d.color='V';
				d.n=V;
				e.color='O';
				e.n=O;
				f.color='G';
				f.n=G;
			}
		}else{
			if(B<Y){
				a.color='R';
				a.n=R;
				b.color='Y';
				b.n=Y;
				c.color='B';
				c.n=B;
				d.color='G';
				d.n=G;
				e.color='V';
				e.n=V;
				f.color='O';
				f.n=O;
			}else if(R<B){
				a.color='B';
				a.n=B;
				b.color='R';
				b.n=R;
				c.color='Y';
				c.n=Y;
				d.color='O';
				d.n=O;
				e.color='G';
				e.n=G;
				f.color='V';
				f.n=V;
			}else{
				a.color='R';
				a.n=R;
				b.color='B';
				b.n=B;
				c.color='Y';
				c.n=Y;
				d.color='G';
				d.n=G;
				e.color='O';
				e.n=O;
				f.color='V';
				f.n=V;
			}
		}
		printf("Case #%d: ",t);
		if(a.n*2>N){
			impossible();
			continue;
		}
		if(R==0 && G>0){
			if(N>G*2){
				impossible();
				continue;
			}
			for(int i=0;i<G;i++) printf("RG");
			printf("\n");
			continue;
		}
		if(Y==0 && V>0){
			if(N>V*2){
				impossible();
				continue;
			}
			for(int i=0;i<V;i++) printf("YV");
			printf("\n");
			continue;
		}
		if(B==0 && O>0){
			if(N>O*2){
				impossible();
				continue;
			}
			for(int i=0;i<O;i++) printf("BO");
			printf("\n");
			continue;
		}
		int over=b.n+c.n-a.n;
		while(N>0){
			if(a.n>0){
				printf("%c",a.color);
				if(d.n>0){
					printf("%c%c",d.color,a.color);
					d.n--;
					a.n--;
					N-=2;
				}
				a.n--;
				N--;
			}
			if(b.n>0){
				printf("%c",b.color);
				if(e.n>0){
					printf("%c%c",e.color,b.color);
					e.n--;
					b.n--;
					N-=2;
				}
				b.n--;
				N--;
				
				if(over>0){
					printf("%c",c.color);
					if(f.n>0){
						printf("%c%c",f.color,c.color);
						f.n--;
						c.n--;
						N-=2;
					}
					c.n--;
					N--;
					over--;
				}
			}else{
				if(c.n>0){
					printf("%c",c.color);
					if(f.n>0){
						printf("%c%c",f.color,c.color);
						f.n--;
						c.n--;
						N-=2;
					}
					c.n--;
					N--;
				}
			}	
		}
		printf("\n");
	}
}