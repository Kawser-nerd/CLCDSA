#include <iostream>
#include <vector>

int main(){
    std::vector<int> a(2), b(2), c(2), d(2);
    std::cin >> a.at(0) >> a.at(1) >> b.at(0) >> b.at(1);

    if(0 == b.at(1) - a.at(1)){
        c.at(0) = b.at(0);
        c.at(1) = b.at(1) + (b.at(0) - a.at(0));
        d.at(0) = a.at(0);
        d.at(1) = a.at(1) + (b.at(0) - a.at(0));
    }else if(0 == b.at(0) - a.at(0)){
        c.at(0) = b.at(0) - (b.at(1) - a.at(1));
        c.at(1) = b.at(1);
        d.at(0) = a.at(0) - (b.at(1) - a.at(1));
        d.at(1) = a.at(1);
    }else{
        c.at(0) = b.at(0) - (b.at(1) - a.at(1));
        c.at(1) = b.at(1) + (b.at(0) - a.at(0));
        d.at(0) = a.at(0) - (b.at(1) - a.at(1));
        d.at(1) = a.at(1) + (b.at(0) - a.at(0));
    }

    std::cout << c.at(0) << " " << c.at(1) << " " << d.at(0) << " " <<  d.at(1) << std::endl;

    return 0;
}