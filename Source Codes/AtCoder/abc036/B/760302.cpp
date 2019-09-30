#include <iostream>

int main(void){
	int N;
	char s[60][60];

	std::cin>>N;

	for(int i=0; i<N; i++)std::cin>>s[i];

	for(int i=0; i<N; i++){
		for(int j=N-1; j>=0; j--)std::cout<<s[j][i];
			std::cout<<std::endl;
	}
	
	
}