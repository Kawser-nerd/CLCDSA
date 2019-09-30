#include<stdio.h>
#include<stdlib.h>
int in_station[1001];
int in_station_c[1001];
struct inout{
	int c;
	int s, t;
}rec[2001];
int cmp(const void *a, const void *b){
	struct inout *aa = (struct inout *)a;
	struct inout *bb = (struct inout *)b;
	if(aa->t < bb->t)
		return -1;
	if(aa->t > bb->t)
		return 1;
	if(aa->c > 0)
		return -1;
	return 1;
}
#define M (1000002013LL)
int cprice(int dist, int c, int n){
	long long D = dist;
	long long N = n;
	long long o_price = (2LL*N-D+1LL)*D/2LL;
	o_price = o_price % M;
	o_price = (o_price * (long long)(c)) % M;
	return (int)o_price;
}
int main(){
	int cases;
	scanf("%d", &cases);
	int cc;
	for(cc=1;cc<=cases;cc++){
		int n, m;
		scanf("%d%d", &n, &m);
		int i;
		for(i=0;i<m;i++){
			int ss,tt,cc;
			scanf("%d%d%d", &ss, &tt, &cc);
			rec[2*i].t = ss;
			rec[2*i].s = 0;
			rec[2*i].c = cc;
			rec[2*i+1].t = tt;
			rec[2*i+1].s = ss;
			rec[2*i+1].c = -cc;
		}
		qsort(rec, 2*m, sizeof(struct inout), cmp);
		int top=0;
		int fans=0;
		for(i=0;i<2*m;i++){
			if(rec[i].c > 0){
				in_station[top] = rec[i].t;
				in_station_c[top++] = rec[i].c;
			}else{
				int dist = rec[i].t - rec[i].s;
				int o_price = cprice(dist, -rec[i].c, n);
				int tmpc = -rec[i].c;
				int now_price = 0;
				while(tmpc){
					if(tmpc<in_station_c[top-1]){
						in_station_c[top-1] -= tmpc;
						now_price += cprice(rec[i].t - in_station[top-1], tmpc, n);
						now_price %= M;
						break;
					}
					tmpc -= in_station_c[top-1];
					now_price += cprice(rec[i].t - in_station[top-1], in_station_c[top-1], n);
					now_price %= M;
					top--;
				}
				int ans = (o_price - now_price)%M;
				if(ans < 0)
					ans += M;
				fans += ans;
				fans %= M;
			}
		}
		printf("Case #%d: %d\n", cc, fans);
	}
	return 0;
}

