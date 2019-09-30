#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int n;
long long t[1100];

bool read(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%I64d", &t[i]);
}

int caso = 1;
void process(){
	printf("Case #%d:", caso++);
	long long div;
	
	for(int j = 1; j < n; j++)
		if(t[0] != t[j]){
			div = t[0]-t[j];
			if(div < 0)
				div = -div;
			break;
		}
	
	long long T = -1;
	for(long long i = 1; i*i <= div; i++){
		bool pode = true;
		if(div%i == 0){
			for(int j = 0; j < n; j++)
				for(int k = j+1; k < n; k++){
					if((t[k]-t[j])%i != 0){
						pode = false;
					}
				}
			if(pode && i > T){
				T = i;
			}
			pode = true;
			for(int j = 0; j < n; j++)
				for(int k = j+1; k < n; k++){
					if((t[k]-t[j])%(div/i) != 0){
						pode = false;
					}
				}
			if(pode && (div/i) > T){
				T = div/i;
			}
		}
	}
	long long y = t[0]%T;
	if(y > 0)
		y = T - y;
	printf(" %I64d\n", y); 
}

int main(){
	int casos;
	scanf("%d", &casos);
	while(casos--){
		read();
		process();
	}
	
	return 0;
}