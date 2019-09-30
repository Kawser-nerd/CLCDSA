#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

int main(){
	int N; scanf("%d", &N);
	for(int t=1; t<=N; t++){
		int NA, NB, T;
		scanf("%d", &T);
		scanf("%d %d", &NA, &NB);
		vector<int> departa[24*60], departb[24*60];
		int arrivea[24*60], arriveb[24*60];
		int hh1, mm1, hh2, mm2;
		for(int i=0; i<NA; i++){
			scanf("%d:%d %d:%d", &hh1, &mm1, &hh2, &mm2);
			departa[hh1*60+mm1].push_back(hh2*60+mm2+T);
		}
		for(int i=0; i<NB; i++){
			scanf("%d:%d %d:%d", &hh1, &mm1, &hh2, &mm2);
			departb[hh1*60+mm1].push_back(hh2*60+mm2+T);
		}
		int na=0, nb=0, a=0,b=0;
		memset(arrivea,0,sizeof(arrivea));
		memset(arriveb,0,sizeof(arriveb));
		for(int i=0; i<24*60; i++){
			a+=arrivea[i]; b+=arriveb[i];
			for(int j=0; j<departa[i].size(); j++){
				if(!a)na++;
				else a--;
				if(departa[i][j]<24*60)
					arriveb[departa[i][j]]++;
			}
			for(int j=0; j<departb[i].size(); j++){
				if(!b)nb++;
				else b--;
				if(departb[i][j]<24*60)
					arrivea[departb[i][j]]++;
			}
		}
		printf("Case #%d: %d %d\n", t, na, nb);
	}
}
