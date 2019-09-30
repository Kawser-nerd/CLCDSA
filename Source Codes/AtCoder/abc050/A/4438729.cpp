#include <iostream>

int main(){
    int a, b;
    char op;
    int ans;
    std::cin >> a >> op >> b;

    switch(op){
        case '+':
            ans = a + b;
            break;
        case '-':
            ans = a - b;
            break;
    }

    std::cout << ans << std::endl;

    return 0;
}