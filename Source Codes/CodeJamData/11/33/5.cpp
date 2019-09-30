#include<cstdio>
#include<algorithm>
long long gcd(long long A, long long B){return A % B? gcd(B, A % B): B;}
int T, N;
long long L, R, arr[10001], Max, Min;
long long LCM, GCD, ans;
long long dv[100000];
int cnt;
bool chk(long long K){
	for(int i = 0; i < N; i++)
	    if(arr[i] % K != 0 && K % arr[i] != 0)return false;
	return true;
}
int main(){
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		scanf("%d%I64d%I64d", &N, &L, &R);
		//printf("%I64d %I64d: %I64d %I64d %I64d %I64d\n", L, R, GCD, LCM, Max, Min);
		scanf("%I64d", &arr[0]);
		cnt = 0;
		Max = Min = GCD = LCM = arr[0];
		for(int i = 1; i < N; i++){
			scanf("%I64d", &arr[i]);
			if(arr[i] > Max)Max = arr[i];
			if(arr[i] < Min)Min = arr[i];
			GCD = gcd(GCD, arr[i]);
			if(LCM == -1)continue;
			long long tG = gcd(LCM, arr[i]);
			if(double(arr[i] / tG) * double(LCM) > 1e17)LCM = -1;
			else LCM = LCM * (arr[i] / tG);
		}
		ans = -1;
		//printf("%I64d %I64d: %I64d %I64d %I64d %I64d\n", L, R, GCD, LCM, Max, Min);
		for(long long i = 1; i * i <= GCD; i++){
			if(GCD % i == 0){
				dv[cnt++] = i;
				dv[cnt++] = GCD / i;
			}
		}
		std::sort(dv, dv + cnt);
		for(int i = 0; i < cnt; i++){
			if(dv[i] >= L && dv[i] <= R){
				ans = dv[i];
				break;
			}
		}
		if(ans == -1){
			if(LCM != -1){
				long long Tmp = ((L - 1) / LCM + 1) * LCM;
				if(Tmp <= R && Tmp >= L)ans = Tmp;
			}
			if(Max % Min == 0){
				Max /= Min;
				cnt = 0;
				for(long long i = 1; i * i <= Max; i++){
					if(Max % i == 0){
						dv[cnt++] = i;
						dv[cnt++] = Max / i;
					}
				}
				std::sort(dv, dv + cnt);
				for(int i = 0; i < cnt; i++){
					long long Tmp = Min * dv[i];
					if(Tmp > R || Tmp < L)continue;
					if(chk(Tmp)){
						ans = Tmp;
						break;
					}
				}
			}
		}
		printf("Case #%d: ", t);
		if(ans == -1)puts("NO");
		else printf("%I64d\n", ans);
	}
}
