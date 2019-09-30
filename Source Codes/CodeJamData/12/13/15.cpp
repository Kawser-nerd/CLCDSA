#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>
#include <cctype>
using namespace std;
#define FOR(i,s,e) for(int i=(s);i<(int)(e);i++)
#define FORS(i,s) for(int i=0;(s)[i];i++)
#define FOE(i,s,e) for(int i=(s);i<=(int)(e);i++)
#define CLR(s) memset(s,0,sizeof(s))
typedef long long LL;
#define PB push_back
#define EPS 1e-11

int n, ns;

char ts[11111];
int s[11111], p[11111], l[11111];
bool fr[11111];

double ep[1111111];
int nep;

bool pos[2][1211111];
bool vl[1211111];

LL sp[2][1211111];
int spv[2][1211111];
int nsp[2];
bool col[555][555];

int main() {

int nt, tt=0; scanf("%d", &nt); while(nt--){
	scanf("%d", &n);
	FOR(i,0,n){
		scanf("%s%d%d", ts, &s[i], &p[i]);
		l[i] = (ts[0]=='L'?0:1);
	}

	nep = 0;
	ep[nep++] = 0.0;

	FOR(i,0,n)FOR(j,0,n) if(s[i]>s[j]){
		double tep;
		tep = -(p[i]-(p[j]-5.0))*1.0/(s[i]-s[j]);
		if(tep > 0.0) ep[nep++] = tep;
		tep = -(p[i]-(p[j]+0.0))*1.0/(s[i]-s[j]);
		if(tep > 0.0) ep[nep++] = tep;
		tep = -(p[i]-(p[j]+5.0))*1.0/(s[i]-s[j]);
		if(tep > 0.0) ep[nep++] = tep;
	}

	sort(ep, ep+nep);
	int onep = nep; nep = 0;
	FOR(i,0,onep) if(nep == 0 || ep[i]-ep[nep-1]>EPS)
		ep[nep++] = ep[i];

	ns = (1<<n);

	int i0=0, i1=1;
	nsp[i0] = 0;
	{
		FOR(i,0,n){
			sp[i0][nsp[i0]] = (1LL << i);
			spv[i0][nsp[i0]] = l[i];
			nsp[i0]++;
		}
	}

#define COL(x,y) (fabs((x)-(y))<5.0-EPS)
#define DI(x,i) (((x)>>(i)) & 1LL)
#define LS(x) ((x) & ~((x)-1))

	double t = 0.0;
	double ans = 0.0;

	bool bad = false;

	FOR(ti,0,nep){

		t = ep[ti];
		
		nsp[i1] = nsp[i0];
		FOR(i,0,nsp[i1]){
			sp[i1][i] = sp[i0][i];
			spv[i1][i] = spv[i0][i];
		}

		FOR(i,0,n)fr[i] = true;
		FOR(i,0,n){
			double ix = p[i] + t*s[i];
			FOR(j,i+1,n){
				double jx = p[j] + t*s[j];
				if(COL(ix, jx)){
					fr[i] = fr[j] = false;
				}
			}
		}

		FOR(k,0,nsp[i1]) FOR(i,0,n) if(fr[i] && DI(sp[i1][k], i)){
			bool good = false;
			FOR(k2,0,nsp[i1]) if(sp[i1][k] != sp[i1][k2] && DI(sp[i1][k2],i)){
				sp[i1][k] ^= sp[i1][k2];
				spv[i1][k] ^= spv[i1][k2];
				good = true;
				break;
			}
			if(!good){
				nsp[i1]--;
				FOR(k2,k,nsp[i1]){
					sp[i1][k2] = sp[i1][k2+1];
					spv[i1][k2] = spv[i1][k2+1];
				}
			}
		}

		FOR(i,0,n){
			double ix = p[i] + t*s[i];
			FOR(j,i+1,n){
				double jx = p[j] + t*s[j];
				if(COL(ix, jx)){
					sp[i1][nsp[i1]] = (1LL << i) + (1LL << j);
					spv[i1][nsp[i1]] = 1;
					nsp[i1]++;
				}
			}
		}

		//printf("%.3f :\n", t);
		//FOR(k,0,nsp[i1]) printf("  %I64d,%d", sp[i1][k], spv[i1][k]); printf("\n");
		
		bad = false;

		FOR(k,0,nsp[i1]){
			{
				int mk = k;
				FOR(z,k+1,nsp[i1]) if(sp[i1][mk]==0 || (sp[i1][z]!=0 && LS(sp[i1][z]) < LS(sp[i1][mk]))){
					mk = z;
				}
				swap(sp[i1][k], sp[i1][mk]);
				swap(spv[i1][k], spv[i1][mk]);
			}
			if(sp[i1][k] == 0){
				//{FOR(k,0,nsp[i1]) printf("  %I64d,%d", sp[i1][k], spv[i1][k]); printf("\n");}
				FOR(z,k,nsp[i1]) if(spv[i1][z] != 0) bad = true;
				nsp[i1] = k;
				break;
			}
			FOR(z,k+1,nsp[i1]) if(LS(sp[i1][z]) == LS(sp[i1][k])){
				sp[i1][z] ^= sp[i1][k];
				spv[i1][z] ^= spv[i1][k];
			}
		}
		//FOR(k,0,nsp[i1]) printf("  %I64d,%d", sp[i1][k], spv[i1][k]); printf("\n");
		//if(bad)printf("BASDDFAS\n");

		if(bad)break;
		ans = t;
		swap(i0, i1);
	}

	printf("Case #%d: ", ++tt);

	if(bad) printf("%.8f\n", ans); else printf("Possible\n");
}
	return 0;
}


