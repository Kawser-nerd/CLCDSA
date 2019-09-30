#include <stdio.h>
#include <string.h>
#define M 10008
#define INF (1000000000)
int n,c,C,i,m,m2,v;
int t[M],op[M],mi[2][M],ch[M];
static int MIN(int x, int y) { return x<y? x:y; }
static int MAX(int x, int y) { return x==INF || y==INF ? INF :x+y; }
int main() {
	scanf("%d",&C);
	for(c=1;c<=C;c++) {
		scanf("%d%d",&m,&v);
		memset(mi,0,sizeof(mi));
		memset(t,0,sizeof(t));
		memset(ch,0,sizeof(ch));
		memset(op,0,sizeof(op));
		m2 = (m-1)/2;
//		printf("%d\n",m2);
		for(i=0;i<m2;i++) {
			scanf("%d%d",op+i,ch+i);
			mi[0][i] = mi[1][i] = INF;
		}
		for(;i<m;i++) {
			scanf("%d",t+i);
			mi[t[i]][i] = 0;
			mi[!t[i]][i] = INF;
		}
//		printf("%d\n",m2);
		for(i=m2-1;i>=0;i--) {
			int l = 2*i+1, r = 2*i+2;
			int b0 = INF, b1 = INF;
			int b00 = MAX(mi[0][l],mi[0][r]);
			int b01 = MAX(mi[0][l],mi[1][r]);
			int b10 = MAX(mi[1][l],mi[0][r]);
			int b11 = MAX(mi[1][l],mi[1][r]);
//			printf("%8d%8d%8d%8d\n",b00,b10,b01,b11);
			int b0and = MIN(b00,MIN(b01,b10)), b1and = b11;
			int b1or = MIN(b11,MIN(b01,b10)), b0or = b00;
//			printf("%8d%8d%8d%8d\n",b0and,b1and,b0or,b1or);
			if(b0and != INF) {
				if(op[i])/*AND*/{
					b0 = MIN(b0and, b0);
				} else if(ch[i]) {
					b0 = MIN(b0and + 1, b0);
				}
			}
			if(b1and != INF) {
				if(op[i])/*AND*/{
					b1 = MIN(b1and, b1);
				} else if(ch[i]) {
					b1 = MIN(b1and + 1, b1);
				}
			}
			if(b0or != INF) {
				if(!op[i])/*OR*/{
					b0 = MIN(b0or, b0);
				} else if(ch[i]) {
					b0 = MIN(b0or + 1, b0);
				}
			}
			if(b1or != INF) {
				if(!op[i])/*OR*/{
					b1 = MIN(b1or, b1);
				} else if(ch[i]) {
					b1 = MIN(b1or + 1, b1);
				}
			}
			mi[0][i] = b0;
			mi[1][i] = b1;
//			printf("%d(%d):%8d%8d\n",i,ch[i],b0,b1);
		}
		fprintf(stderr,"\r%d/%d",c,C); fflush(stderr);
		if(mi[v][0]!=INF) {
			printf("Case #%d: %d\n",c,mi[v][0]);
		} else {
			printf("Case #%d: IMPOSSIBLE\n",c);
		}
	}
	fprintf(stderr,"\n");
	return 0;
}
