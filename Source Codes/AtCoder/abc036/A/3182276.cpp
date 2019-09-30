#include<iostream>
 
int main(){
    std::size_t A{}, B{};
    std::cin >> A >> B ;
    std::cout << (B/A + (B%A==0?0:1))<<"\n";
	return 0;
}