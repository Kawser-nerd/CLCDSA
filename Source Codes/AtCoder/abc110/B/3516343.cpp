#include <iostream>
#include <algorithm>
#include <vector>

int main(){
	int N,M,X,Y;
	std::vector<int> x, y;

	std::cin >> N >> M >>X >> Y;
	for( int _,i= 0; i<N; ++i ){
		std::cin >> _; x.push_back( _ );
	}
	for( int _,i=0; i<M; ++i ){
		std::cin >>_; y.push_back( _ );
	}
	x.push_back( X );
	y.push_back( Y );

	if( *std::max_element( x.begin(), x.end() ) >= *std::min_element( y.begin(), y.end() ) ){
		std::cout << "War" << std::endl;
		return 0;
	}
	std::cout << "No War" << std::endl;
	return 0;
}