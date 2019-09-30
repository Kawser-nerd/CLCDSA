#include <iostream>		
		
int main(){		
	int h1, w1, h2, w2;	
	std::cin >> h1 >> w1 >> h2 >> w2;	
		
	bool flg = false;	
	if(h1 == h2 || w1 == h2){	
		flg = true;
	}else if(h1 == w2 || w1 == w2){	
		flg = true;
	}	
		
	if(flg){	
		std::cout << "YES" << std::endl;
	}else{	
		std::cout << "NO" << std::endl;
	}	
		
	return 0;	
}