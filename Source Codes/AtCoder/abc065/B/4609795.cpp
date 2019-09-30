#include <iostream>
#include <cstdio>
#include <vector>

int main(){
    int n;
    scanf("%d", &n);

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }

    bool flg = false;
    int index = 1;
    long count = 0;
    for(int i = 0; i < n; ++i){
        
        ++count;

        index = a.at(index - 1);

        if(2 == index){
            flg = true;
            break;
        }
    }

    if(flg){
        std::cout << count << std::endl;
    }else{
        std::cout << -1 << std::endl;
    }

    return 0;
}