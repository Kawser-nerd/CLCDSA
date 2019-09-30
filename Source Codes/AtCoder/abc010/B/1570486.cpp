#include <iostream>
using namespace std;

 
int main() {
	int n,a,counter=0;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a;
		while(true){
			if(a%2==0||a%3==2){
                      counter++;
                   }
			else{
                             break;
                           }
			a--;
		}
	}
	cout << counter << "\n";
	return 0;
}