#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdlib>
using namespace std;

int main(void){
	int n, a, b;
	cin >> n;
	map<int,int> mp;
	for(int i = 0; i < n; ++i){
			cin >> a >> b;
			b *= -1;
			if(a % 5 != 0){
				a -= a % 5;
			}
			if(b % 5 != 0){
				b += 5 - b % 5;
				if(b-b/100*100==60){
					b+=40;
				}
			}
			if(mp.count(a)==0){
				mp.insert(make_pair(a,b));
			}else{
				if(mp[a]<=b){
					mp[a] = b;
				}
			}

	}

	int f=-1,e=0;
	for( auto i = mp.begin(); i != mp.end() ; ++i ) {
		if(f==-1){
			f = i->first;	e = i->second;
		}else{
			if(i->first > e){
				printf("%04d-%04d\n",f,e);
				f=i->first;	e=i->second;
			}else{
				if(i->second >= e){
					e = i->second;
				}
			}
		}
  	}
  	
  	if(f!=-1){
  		printf("%04d-%04d\n",f,e);
  		//cout << f << "-" << e << endl;
  	}

	return 0;
}