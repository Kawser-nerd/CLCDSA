#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

int N;
string S;
typedef long long ll;
int P[] = {2, 3, 5, 7, -6, -10, -14, -15, -21, -35, 30, 42, 70, 105, -210};
ll F[50][220];

int main(){
	ifstream cin("b2.in");
	ofstream cout("b2.out");
	
	cin>>N;
	for (int Case=1; Case<=N; ++Case){
		cin>>S;
		
		ll ans = 0;
		for (int k=0;k<15;++k){
			int p = abs(P[k]);
			
			memset(F, 0, sizeof(F));			
			for (int i=0;i<S.size();++i){
				int ret = 0;
				int base = 1;
				for (int j=i;j>=0;--j){
					ret = (ret+(S[j]-'0')*base)% p;
					base = (base * 10) % p;
					
					for (int lef=0;lef<p;++lef){
						int _mod = (lef - ret + p)% p;
						
						if (j>0)
							F[i][lef] += F[j-1][_mod];
						else
							F[i][lef] += (_mod==0);
						
						if (j>0){
							_mod = (lef + ret) % p;
							F[i][lef] += F[j-1][_mod];
						}
					}
				}
			}
			
			if (P[k] > 0){
				ans += F[S.size()-1][0];
			}
			else{
				ans -= F[S.size()-1][0];
			}
		}
		
		cout<<"Case #"<<Case<<": "<<ans<<endl;
	}
	
	return 0;	
}
