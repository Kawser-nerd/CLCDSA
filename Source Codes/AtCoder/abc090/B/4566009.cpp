#include <iostream>
#include <sstream>

int main(){
    long a, b;
    std::cin >> a >> b;

    std::string valRev;
    long counter = 0;
    for(long i = a; i <= b; ++i){
        std::stringstream ss;
        ss << i;
        valRev = ss.str();
        std::reverse(valRev.begin(), valRev.end());
        // std::cout << "valRev: " << valRev << std::endl;
        if(valRev == ss.str()){
            ++counter;
        }
    }

    std::cout << counter << std::endl;

    return 0;
}