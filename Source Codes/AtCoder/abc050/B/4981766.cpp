#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> t(n);
    for(int i = 0; i < n; i++){
        std::cin >> t[i];
    }
    int m;
    std::cin >> m;
    std::vector<std::vector<int>> px(m,std::vector<int>(2));
    for(int i = 0; i < m; i++){
        std::cin >> px[i][0] >> px[i][1];
    }
    //n?????t??????????m????????px?????????????????????

    int sum = 0;
    for(int j = 0; j < n; j++){
        sum += t[j];
    }
    for(int j = 0; j < m; j++){
        int tmp = px[j][0];
        int tm2 = t[tmp-1];
        std::cout << sum - tm2 + px[j][1] << std::endl;
    }
    return 0;
}