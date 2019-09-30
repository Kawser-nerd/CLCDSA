//Aho
#include<iostream>
#include<string>
#define rep(i,n) for(int (i)=0; (i)<(n); (i)++)
#define rep2(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define rrep(i,n) for(int (i)=(n-1); (i)>=0; (i)--)
#define rrep2(i,a,b) for(int (i)=(a-1); (i)>=b; (i)--); 
using namespace std;
 
int main(){
       unsigned long long N;
     int i;
	 
	cin >> N;
     
       if(N > 0) cout << 1;
         
	for(i=0;i<N-1;i++)  cout <<  0;
 
	cout <<  7 << endl;
 
	return 0;
}