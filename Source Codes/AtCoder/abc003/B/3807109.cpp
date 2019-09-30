#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	string a,b;
	char s[7] = {'a','t','c','o','d','e','r'};
	cin >> a >> b;
	for(int i=0;i<a.size();i++){
		if(a[i] != b[i]){
			if((a[i] != '@' && b[i] != '@') || (a[i] == '@' && b[i] != 'a' && b[i] != 't' && b[i] != 'c' && b[i] != 'o' && b[i] != 'd' &&b[i]!= 'e' && b[i] != 'r') || (b[i] == '@' && a[i] != 'a' && a[i] != 't' && a[i] != 'c' && a[i] != 'o' && a[i] != 'd' && a[i]!= 'e' && a[i] != 'r')){
				cout << "You will lose" << endl;
				return 0;
			}
		}
		//cout << a[i] << ' ' << b[i] << endl;
	}
		
	cout << "You can win" << endl;
	return 0;
}