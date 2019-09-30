#include <iostream>
using namespace std;

int n;
int h[105];
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> h[i];
	}
	int tot = 0;
	bool put = 0;
	for (int w = 1; w <= 100; w++){
		for (int i = 1; i <= n; i++){
			if (h[i]){
				put = 1;
				--h[i];
			} else {
				if (put) tot++;
				put = 0;
			}
		}
		if (put) tot++;
		put = 0;
	}
	cout << tot << '\n';
	return 0;
}