#include <iostream>
#include <string>
using namespace std;
int main(){
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	string s;
	for(int i=0; i<2; i++){
	int max=i;
		for(int j=i+1; j<3; j++){
			if(a[max]<a[j]) max=j;
		}
		int temp=a[max];
		a[max]=a[i];
		a[i] = temp;
	}
	
	s = to_string(a[0]) + to_string(a[1]);
    int i = stoi(s);
    int sum = i + a[2];
    cout << sum << endl;
    
    return 0;
}