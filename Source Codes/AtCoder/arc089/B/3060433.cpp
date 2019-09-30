extern "C"{
int printf (const char *__restrict __format, ...);
int scanf (const char *__restrict __format, ...) ;
}
int max(int a,int b){
	return a>b?a:b;
}
int x[100000],y[100000],x_mod_k[100000],x_div_k[100000];
char s[100000][2];
int n,k;
 
void add(int*cnt,int x,int t){
	if((x_div_k[x]&1)==0){
		if(t==0){
			cnt[0]++;
			cnt[k-x_mod_k[x]]--;
		}
		else{
			cnt[k-x_mod_k[x]]++;
		}
	}
	else{
		if(t==0){
			cnt[k-x_mod_k[x]]++;
		}
		else{
			cnt[0]++;
			cnt[k-x_mod_k[x]]--;
		}
	}
}
int ans[2000];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d%d%s",&x[i],&y[i],s[i]);
		x_mod_k[i]=y[i]%k;
		x_div_k[i]=y[i]/k;
	}
	int Max=0;
	//~ #pragma omp parallel for num_threads(2)
	for(int i=0;i<k;i++){
		int d=max(n,k);
		int cnt[d];
		for(int j=0;j<d;j++)cnt[j]=0;
		for(int j=0;j<n;j++){
			if(s[j][0]=='B'){
				if(((x[j]+i)/k)%2==0){
					add(cnt,j,0);
				}
				else{
					add(cnt,j,1);
				}
			}
			else{
				if(((x[j]+i)/k)%2==0){
					add(cnt,j,1);
				}
				else{
					add(cnt,j,0);
				}
			}
		}
		for(int j=0;j<k;j++){
			if(j)cnt[j]+=cnt[j-1];
			ans[i]=max(ans[i],max(cnt[j],n-cnt[j]));
		}
	}
	for(int i=0;i<k;i++)Max=max(Max,ans[i]);
	printf("%d\n",Max);
}