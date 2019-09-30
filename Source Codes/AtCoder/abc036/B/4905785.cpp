#include <iostream>			
#include <vector>			
#include <utility>			
			
int main(){			
	int n;		
	std::cin >> n;		
			
	std::vector<std::vector<char>> matrix(n, std::vector<char>(n));		
	for(int i = 0; i < n; ++i){		
		for(int j = 0; j < n; ++j){	
			std::cin >> matrix.at(j).at(n - 1 - i);
		}	
	}		
			
	for(int i = 0; i < n; ++i){		
		for(int j = 0; j < n; ++j){	
			std::cout << matrix.at(i).at(j);
		}	
		std::cout << std::endl;	
	}		
			
	return 0;		
}