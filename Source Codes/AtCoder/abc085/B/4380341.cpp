#include <iostream>
#include <vector>
int main(){
	int N;
	std::cin>>N;
	std::vector<int> mochis;

	for(int i=0;i<N;++i){
		int diameter;
		std::cin>>diameter;
		auto itr = std::find(mochis.begin(),mochis.end(),diameter);
		if(itr == mochis.end()){
			mochis.push_back(diameter);
		}
	}
	std::cout<<(mochis.size());
	return 0;
}