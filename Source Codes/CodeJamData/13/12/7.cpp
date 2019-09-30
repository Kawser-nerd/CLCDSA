#include <iostream>
#include <cstdlib>
#include <cmath>
#include <stack>

using namespace std;

typedef long long ll;

ll e, r;
int n;
ll v[1<<15];
ll next[1<<15];

int main(){
	int tt; cin >> tt;
	for (int zz = 1; zz <= tt; zz++){
		cin >> e >> r >> n;
		for (int i = 0; i < n; i++)
			cin >> v[i];
			
		stack<int> st;
		for (int i = 0; i < n; i++){
			next[i] = i;
			while (!st.empty() && v[st.top()] < v[i]){
				next[st.top()] = i;
				st.pop();
			}
			st.push(i);
		}
		/*for (int i = 0; i < n; i++)
			cout << next[i] << " ";
		cout << endl;*/
		ll energy = e;
		ll sum = 0;
		for (int i = 0; i < n; i++){
			if (next[i] == i){
				sum += energy * v[i];
				energy = r;
				if (energy > e) energy = e;
				continue;
			}
			ll need = e - ((ll)(next[i] - i)) * r;
			if (need < 0) need = 0;
			if (energy > need){
				sum += (energy - need) * v[i];
				energy = need + r;
				if (energy > e) energy = e;
			}
			else{
				energy = energy + r;
				if (energy > e) energy = e;
			}
		}
		cout << "Case #" << zz << ": " << sum << endl;
	}
	
	return 0;
}
