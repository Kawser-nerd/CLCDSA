int main(){
	int T,t,N,S,p,x,y,n,i,ans,r,ws,wos;
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		scanf("%d",&N);
		scanf("%d",&S);
		scanf("%d",&p);
		ans = 0;
		x = 0;
		y = 0;
		for(i=0;i<N;i++){
			scanf("%d",&n);
			if(n == 0) {
				if(p <= 0) ans++;
			} else if(n == 1){
				if(p <= 1) ans++;
			} else if(n == 29 || n == 30){
				if(p <= 10) ans++;
			} else {
				r = n%3;
				if(r == 0){
					ws = n/3 + 1;
					wos = n/3;
				} else if(r == 1){
					ws = n/3 + 1;
					wos = ws;
				} else {
					ws = n/3 + 2;
					wos = n/3 + 1;
				}
				
				if(wos >= p) {
					y++;
				} else if(ws >= p){
					x++;
				}
			}
		}
		ans = ans + y + ((S < x) ? S : x);
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}