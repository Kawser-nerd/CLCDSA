#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int H, W;
	cin >> H >> W;
	printf("%d\n",(W - 1) * H + (H - 1) * W);
	return 0;
}