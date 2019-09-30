#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
string a[1024];

void read() {
	char buf[64];
	int i;
	
	scanf ( "%d" , &n );
	for (i = 1; i <= n; i++) {
		scanf ( "%s" , buf );
		a[i] = string ( buf );
	}
}

string del ( string a , string b ) {
	FILE *fout = fopen ( "bau" , "w" );
	fprintf ( fout , "print %s/%s\n" , a.c_str() , b.c_str() );
	fclose ( fout );
	
	system ( "python < bau > ans" );
	
	char buf[1024];
	FILE *fin = fopen ( "ans" , "r" );
	fscanf ( fin , "%s" , buf );
	fclose ( fin );
	
	return string ( buf );
}

string mod ( string a , string b ) {
	FILE *fout = fopen ( "bau" , "w" );
	fprintf ( fout , "print %s%%%s\n" , a.c_str() , b.c_str() );
	fclose ( fout );
	
	system ( "python < bau > ans" );
	
	char buf[1024];
	FILE *fin = fopen ( "ans" , "r" );
	fscanf ( fin , "%s" , buf );
	fclose ( fin );
	
	return string ( buf );
}

string rem ( string a , string b ) {
	FILE *fout = fopen ( "bau" , "w" );
	fprintf ( fout , "print %s-%s\n" , a.c_str() , b.c_str() );
	fclose ( fout );
	
	system ( "python < bau > ans" );
	
	char buf[1024];
	FILE *fin = fopen ( "ans" , "r" );
	fscanf ( fin , "%s" , buf );
	fclose ( fin );
	
	return string ( buf );
}

string gcd ( string a , string b ) {
	if ( b == "0" ) return a;
	return gcd ( b , mod ( a , b ) );
}

int cmp ( string a , string b ) {
	if ( (int)a.size() != (int)b.size() )
		return (int)a.size() < (int)b.size();
	return a < b;
}

void solve() {
	int i;
	
	sort ( a + 1 , a + n + 1 , cmp );
	
	string t = rem ( a[2] , a[1] );
	for (i = 2; i < n; i++) 
		t = gcd ( t , rem ( a[i + 1] , a[i] ) );
	
	if ( mod ( a[1] , t ) == "0" ) 
		t = "0";
	else
		t = rem ( t , mod ( a[1] , t ) );
	printf ( "%s\n" , t.c_str() );
}

void solve2() {
	static long long t[1024];
	int i , j;
	
	for (i = 1; i <= n; i++) {
		istringstream in ( a[i] );
		in >> t[i];
	}
	
	sort ( t + 1 , t + n + 1 );
	long long e = t[2] - t[1];
	
	for (i = 1; i < n; i++)
		for (j = i + 1; j <= n; j++)
			e = __gcd ( e , t[j] - t[i] );
		
	if ( t[2] % e == 0 ) e = 0;
	else e = (e - t[2] % e);
	
	printf ( "%lld\n" , e );
}

int main() {
	int cases;
	int i;
	
	scanf ( "%d" , &cases );
	for (i = 1; i <= cases; i++) {
		printf ( "Case #%d: " , i );
		
		read();
		solve();
		
		fflush ( stdout );
	//	return 0;
	}
	
	return 0;
}