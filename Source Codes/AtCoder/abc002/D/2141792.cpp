#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
#define MAXN 12

// search tree node
typedef struct snode {
	set<int> having_node;
	snode* root;
	snode* left;
	snode* right;
} snode;

// return max number of nodes
int search( int n, snode* now,  int e[][MAXN]) {
	int ret = now->having_node.size() ;

	//cout << ret << ")";
	//for(auto& no : now->having_node ){ cout << no << " "  ;} ; cout << endl ; 
	// for( int i=0; i <n; i++){
	int starti = now->having_node.size()==0 ? 0 : * ( now->having_node.rbegin() );

	for( int i= starti ; i <n; i++){
		if( now->having_node.find(i) != now->having_node.end() ) continue;
		int can_be_added = 1;
		for(auto& check_node : now->having_node ) {
			//cout << "  check <" << i << "," << check_node << ">is " << e[check_node][i] << endl;
			if( ! e[check_node][ i ] ){ can_be_added = 0; break; }
		}

		if( can_be_added ){
			now->having_node.insert( i );
			int tmpret= search(n,  now, e );
			ret =  ret > tmpret ? ret : tmpret;
			now->having_node.erase( i );
		}


	}	
	return ret;


}

int main(){
	int n, m, x,y;
	scanf("%d %d", &n, &m );
	int arr[MAXN][MAXN] ;
	memset(arr, 0, sizeof(int) *12*12 );
	int greedy[12] = {1, } ;
	while( m-- ){
		scanf("%d %d", &x, &y);
		arr[x-1][y-1] = 1;
		arr[y-1][x-1] = 1;
		//cout << x-1 << y-1 << endl;
	}
	
	snode stree;
	int ret = search( n, &stree,  arr );

	printf("%d\n", ret );


}