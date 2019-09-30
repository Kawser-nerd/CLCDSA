#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <boost/lexical_cast.hpp>

int main(){
    long long n;
    std::cin >> n;

    std::vector<long long> vec;
    std::string a, b;
    long aDigit, bDigit;
    for(long i = 1; i <= std::sqrt(n); ++i){
        if(0 == n % i){
            a = boost::lexical_cast<std::string>(i);
            b = boost::lexical_cast<std::string>(n / i);
//            std::cout << "a: " << a << std::endl;
//            std::cout << "b: " << b << std::endl;
            
            if(a.size() < b.size()){
                vec.push_back(b.size());
            }else{
                vec.push_back(a.size());
            }
        }
    }

    std::cout << *min_element(vec.begin(), vec.end()) << std::endl;

    return 0;
}