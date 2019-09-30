#include <iostream>

using namespace std;

const int MAX_N = 105;

int slimes[MAX_N];

int main() {
	
	int N, spells = 0; 
	scanf("%d", &N);

	for(int i = 0; i < N; ++i) {
		scanf("%d", &slimes[i+1]);
	}

	for(int i = 1; i < N; ++i) {
		//adjacent equal slimes
		if(slimes[i] == slimes[i+1]) {
			if(slimes[i+2] != 1 && slimes[i] != 1) {
				slimes[i+1] = 1;
			} else if(slimes[i+2] != 2 && slimes[i] != 2) {
				slimes[i+1] = 2;
			} else if(slimes[i+2] != 3 && slimes[i] != 3) {
				slimes[i+1] = 3;
			}

			spells++;
		}
	}

	cout << spells << endl;

	return 0;
}