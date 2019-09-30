#include<cstdio>
#include<algorithm>
#include<cstdlib>

#define MAXN 1000

using namespace std;

int main() {
	int T, n, v1[MAXN], v2[MAXN];
	FILE *fin = fopen("A.in","r"), *fout = fopen("A.out","w");
	fscanf(fin,"%d",&T);
	for(int k = 1; k<=T; k++) {
		fscanf(fin,"%d",&n);
		for(int i = 0; i<n; i++) {
			fscanf(fin,"%d",&v1[i]);
		}
		for(int i = 0; i<n; i++) {
			fscanf(fin,"%d",&v2[i]);
		}
		sort(v1,v1+n);
		sort(v2,v2+n);
		reverse(v2,v2+n);
		long long ans = 0;
		for(int i = 0; i<n; i++) {
			ans += (long long)v1[i]*v2[i];
		}
		fprintf(fout,"Case #%d: %lld\n",k,ans);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
