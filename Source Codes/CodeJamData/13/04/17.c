int state[1048576], flag[1048576];
int gk[20][41],gkc[20][201];
int ok[20];
int start_keys[201];
int choice[1048576];
int n;
int search(int s){
	if(flag[s])
		return state[s];
	flag[s]=1;
	int *keys=malloc(sizeof(int)*201);
	memcpy(keys, start_keys, sizeof(start_keys));
	int ts=s;
	int c=0;
	while(ts){
		if(ts&1){
			keys[ok[c]]--;
			int i;
			for(i=1;i<=gk[c][0];i++)
				keys[gk[c][i]]+=gkc[c][gk[c][i]];
		}
		ts>>=1;
		c++;
	}
	int res=0, i;
	for(i=0;i<n;i++){
		if(keys[ok[i]] && !(s&(1<<i)) && search(s+(1<<i))){
			res=1;
			choice[s+(1<<i)]=i;
			break;
		}
	}
	free(keys);
	state[s]=res;
	return res;
}
void print(int s){
	if(!s)return;
	print(s-(1<<choice[s]));
	printf(" %d", choice[s]+1);
}
int main(){
	int cases;
	scanf("%d", &cases);
	int cc;
	for(cc=1;cc<=cases;cc++){
		memset(flag, 0, sizeof(flag));
		memset(state, 0, sizeof(state));
		memset(start_keys, 0, sizeof(start_keys));
		memset(gkc, 0, sizeof(gkc));
		int k;
		scanf("%d %d", &k, &n);
		int i;
		flag[(1<<n)-1]=1;
		state[(1<<n)-1]=1;
		for(i=0;i<k;i++){
			int tmp;
			scanf("%d", &tmp);
			start_keys[tmp]++;
		}
		for(i=0;i<n;i++){
			int tt;
			scanf("%d %d", ok+i, &tt);
			int j;
			gk[i][0]=0;
			for(j=1;j<=tt;j++){
				int tmp;
				scanf("%d", &tmp);
				if(!gkc[i][tmp])
					gk[i][++gk[i][0]]=tmp;
				gkc[i][tmp]++;
			}
		}
		printf("Case #%d:", cc);
		if(search(0))
			print((1<<n)-1);
		else
			printf(" IMPOSSIBLE");
		printf("\n");
	}
}


