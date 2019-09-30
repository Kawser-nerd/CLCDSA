#include <iostream>
#include <vector>

using namespace std;

int main(){
	int N;
	while(cin >> N){
		vector<int> a(N), b(N);
		for(int i=0;i<N;i++){
			a[i] = i+1;
			b[i] = N-i;
		}
		for(int i=0;i<N;i++){
			int p; cin >> p; --p;
			for(int j=0;j<p;j++) b[j] += N-i;
			for(int j=p+1;j<N;j++) a[j] += N-i;
		}
		for(int i=0;i<N-1;i++) cout << a[i] << " "; cout << a.back() << endl;
		for(int i=0;i<N-1;i++) cout << b[i] << " "; cout << b.back() << endl;
	}
}