#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
#include <map>

using namespace std;

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

string S;
int T;

int main(){
	cin.tie(0);                       
   	ios::sync_with_stdio(false);
   	cin >> S;
   	cin >> T;
   	int x = 0;
   	int y = 0;
   	int maxv = -1;
   	int count = 0;
   	for(int i = 0;i < S.length();i++){
   		if(S[i] == 'U'){
   			y = y + 1;
   		}else if(S[i] == 'D'){
   			y = y - 1;
   		}else if(S[i] == 'L'){
   			x = x - 1;
   		}else if(S[i] == 'R'){
   			x = x + 1;
   		}else if(S[i] == '?'){
   			count += 1;
   		}
   	}

   	if(T == 1){
	   	maxv = abs(x) + abs(y) + count;
	}else if(T == 2){
		maxv = abs(x) + abs(y) - count;
		if(maxv < 0){
			if(abs(maxv) % 2 == 0){
				maxv = 0;
			}else{
				maxv = 1;
			}
		}
	}
   	cout << maxv << endl;
   	return 0;
}