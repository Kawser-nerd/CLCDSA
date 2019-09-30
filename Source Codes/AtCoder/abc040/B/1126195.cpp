# include <iostream>
using namespace std;

int main() {
	int n,m,min,x;
	cin >> n;
	for(int i=0;n>=i*i;++i) {
		m=i;
	}
	if(n==m*m) {
		cout << "0" << endl;
	} else {
		for(int j=1;j<=n;++j) {
			if(j>=(n/j) && (j-(n/j))+(n%j)<min) {
				min=((j-(n/j))+(n%j));
				x=j;
			}
		}
		cout << min << endl;
	}
	return 0;
}