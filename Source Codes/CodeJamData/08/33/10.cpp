// Jacek Migdal 2008 Google code jam
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

const long long MOD = 1000000007;
const int MAX = 1000000000;
const int CACHE = 5000000*10;
const int MAX_M = 100+28;

typedef long long s64;

class Node {
public:
	Node* left;
	Node* right;
	int value;

	Node() { value = 0; left = 0; right = 0; }
	Node( Node* left, Node* right) { value = 0; this->left = left; this->right = right; }
};

Node cache[CACHE];
int iCache = 0;
Node* root;

Node* addNode() {
	if( iCache==CACHE ) {
		printf( "Error\n" );
	}
	Node* n = &cache[iCache++];
	n->value = 0;
	n->left = n->right = 0;
	return n;
}

void createTree() {
	iCache = 0;
	root = addNode();
}

int quote( int low, int high, int ask, Node* node ) {
	if( node==0 )
		return 0;
	if( ask<low ) {
		return 0;
	}
	if( high<=ask ) {
		return node->value;
	}
	int mid = (low+high)/2;
	return (quote(low,mid,ask,node->left)+quote(mid+1,high,ask,node->right))%MOD;
}

void add( int low, int high, int number, int value, Node* node ) {
	node->value = (node->value+value)%MOD;
	if( low==high )
		return;
	int mid = (low+high)/2;
	if( number<=mid ) {
		if( node->left==0 )
			node->left = addNode();
		add( low, mid, number, value, node->left );
	} else {
		if( node->right==0 )
			node->right = addNode();
		add( mid+1, high, number, value, node->right );
	}
}

void doIt() {
	int n, m;
	s64 X, Y, Z;
	scanf( "%d %d %lld %lld %lld", &n, &m, &X, &Y, &Z );
	static s64 A[MAX_M];
	for( int i = 0 ; i<m ; i++ ) {
		scanf( "%lld", A+i );
	}

	createTree();
	//
	for( int i = 0 ; i<n ; i++ ) {
		int number = A[i%m];

		int value = quote( 0, MAX, number-1, root );
		value = (value+1)%MOD;
		add( 0, MAX, number, value, root );

		A[i%m] = (X*A[i%m] + Y*(i+1))%Z;
	}

	printf( "%d\n", quote( 0, MAX, MAX-1, root ) ); 
}

int main() {
	int nTests;
	scanf( "%d", &nTests);
	for( int i = 0 ; i<nTests ; i++ ) {
		printf("Case  #%d: ", i+1);
		doIt();
	}
	return 0;
}
