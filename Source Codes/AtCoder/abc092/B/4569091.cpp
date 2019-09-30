#include <iostream>
#include <vector>

int main(){
    int n, d, x;
    std::cin >> n >> d >> x;

    int a;
    int j;
    int count = 0;
    for(int i = 0; i < n; ++i){
        std::cin >> a;
        j = 1;
        while(j <= d){
            ++count;
            j += a;
        }
    }
    
    std::cout << count + x << std::endl;

    return 0;
}