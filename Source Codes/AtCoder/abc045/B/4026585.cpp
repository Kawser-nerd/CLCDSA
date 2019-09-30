#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string sa, sb, sc;
    cin >> sa >> sb >> sc;

    const char* p[3] = {sa.c_str(), sb.c_str(), sc.c_str()};
    char n = 'a';
    while(1)
    {
        int i = n - 'a';
        if(!*p[i])
            break;
        n = *p[i];
        ++(p[i]);
    }
    cout << char('A' + (n - 'a')) << endl;
    return 0;
}