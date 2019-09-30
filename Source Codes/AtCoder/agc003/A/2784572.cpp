#include <iostream>
#include <set>
using namespace std;

int main(){
	cin.tie(0);ios::sync_with_stdio(0);
	string S;
	
	cin >> S;
	
	set<char> conj;
	for( int i = 0; i < S.size(); i++ ){
		conj.insert( S[i] );
	}
	
	bool band = true;
	for( int i = 0; i < S.size(); i++ ){
		if( S[i] == 'N' && !conj.count( 'S' ) )
			band = false;
		if( S[i] == 'S' && !conj.count( 'N' ) )
			band = false;
		if( S[i] == 'W' && !conj.count( 'E' ) )
			band = false;
		if( S[i] == 'E' && !conj.count( 'W' ) )
			band = false;
	}
	
	if( band )
		cout << "Yes\n";
	else
		cout << "No\n";
	
	
	return 0;
}