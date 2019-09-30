#include <iostream>
#include "string.h"
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;
#define output(member) cout << member << endl;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int W,a,b;
	cin >> W >> a >> b;
	int answer = abs(b - a) - W;
	if(answer > 0){
		output(answer);
	}else{
		output(0);
	}
	return 0;
}