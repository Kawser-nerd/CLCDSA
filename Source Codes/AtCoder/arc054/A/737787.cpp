#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

int main() {
    double l, x, y, s, d;
    
    std::cin >> l >> x >> y >> s >> d;
    
    auto dist = [&](double i) {
        return (i < 0 ? i + l : i);
    };
    
    auto rt = dist(d - s) / (x + y);
    auto lt = std::abs(dist(s - d) / (y - x));
    
    std::cout << std::fixed << std::setprecision(10);
    if (y > x) {
        std::cout << std::min(lt, rt) << std::endl;
    }else {
        std::cout << rt << std::endl;
    }
}