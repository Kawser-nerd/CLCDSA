#include <iostream>
using namespace std;

int main(void){
	int N,S,T;
	cin >> N >> S >> T;
	int i=0;
	int sum = 0;
	int count = 0;
	while(i < N){
		int x;
		cin >> x;
		if(i==0){
			sum = x;
		}else{
			sum += x;
		}
		if(S <= sum && sum <= T){
			count++;
		}
		i++;
	}
	cout << count << endl;
	return 0;
}