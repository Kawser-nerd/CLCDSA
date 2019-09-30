#include <iostream>			
#include <vector>			
			
int main(){			
	int n, q;		
	std::cin >> n >> q;		
	std::vector<int> a(n, 0);		
			
	int l, r, t;		
	for(int i = 0; i < q; ++i){		
		std::cin >> l >> r >> t;	
		for(int j = l - 1; j < r; ++j){	
			a.at(j) = t;
		}	
	}		
			
	for(int i = 0; i < n; ++i){		
		std::cout << a.at(i) << std::endl;	
	}		
			
	return 0;		
}