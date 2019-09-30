#include <iostream>
#include <vector>

int main(){
	int N;
	std::vector<int> hen;	
	int cnt=0;
	std::cin>>N;
	for(int i=0;i<N;++i){
		int temp;
		std::cin>>temp;
		hen.push_back(temp);
		cnt += temp;
	}
	int max = *std::max_element(hen.begin(),hen.end());
	if(max < cnt - max){
		std::cout<<"Yes"<<std::endl;
	}else{
		std::cout<<"No"<<std::endl;
	}
	return 0;
}