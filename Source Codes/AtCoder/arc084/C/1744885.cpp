#include <iostream>
using namespace std;

const int MAXL = 300010;
int str[MAXL],slen;
int k,n;
void goback() {
	static int i = slen-1;
	for ( ; i>=0; i--)
		if (str[i] != 0) {
			str[i]--;
			if (str[i]!=0) {
				for (int j=i+1; j<slen; j++)
					str[j]=k;
				i = slen-1;
			}
			return ;
		}
}
int main() {
	cin>>k>>n;
	if (k%2 == 0) {
		cout<<k/2<<" ";
		for (int i=1;i<n;i++)
			cout<<k<<" ";
		cout<<endl;
	}else {
		cout<<(k+1)/2<<" ";
		int move = (n)/2;
		for (int i=1;i<n;i++)
			str[i-1]=(k+1)/2;
		slen = n-1;
		//cout<<"DEBUG move="<<move<<endl;
		for (int i=0;i<move; i++)
			goback();
		for (int i=0;i<slen && str[i];i++)
			cout<<str[i]<<" ";
		cout<<endl;
	}
	return 0;
}