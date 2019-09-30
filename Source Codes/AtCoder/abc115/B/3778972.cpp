#include <iostream>
using namespace std;
int main()
{
	int n,max=0,tmp,sum=0;
	cin >> n;
	int p[n];
	for(int i=0;i<n;i++){
		cin >> p[i];
	}
	
	for(int j=0;j<n;j++){
		if(p[j] > max){
			max = p[j];
			tmp = j;
		}
	}
	
	for(int k=0;k<n;k++){
		if(k == tmp){sum += max/2;}
		else{sum += p[k];}
	}
	
	cout << sum <<endl;
	return 0;
}