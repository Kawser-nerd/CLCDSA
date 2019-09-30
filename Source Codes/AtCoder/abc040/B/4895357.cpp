#include <iostream>		
#include <vector>		
#include <cmath>		
#include <algorithm>		
		
int main(){		
	int n;	
	std::cin >> n;	
		
	int a;	
	int max = sqrt(n);	
	std::vector<int> results;	
	for(int b = 1; b <= max; ++b){	
		a = n / b;
		results.push_back(abs(a - b) + n - a * b);
	}	
		
	std::cout << *std::min_element(results.begin(), results.end()) << std::endl;	
		
	return 0;	
}