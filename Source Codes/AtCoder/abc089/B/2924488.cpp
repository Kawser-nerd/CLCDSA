#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n; cin >> n;
    map<char, int> hinaArare;
    hinaArare['P'] = 0;
    hinaArare['W'] = 0;
    hinaArare['G'] = 0;
    hinaArare['Y'] = 0;

    for (int i = 0; i < n; i++) {
        char x; cin >> x; hinaArare[x]++;
    }

    if (hinaArare['P'] == 0 || hinaArare['W'] == 0 || hinaArare['G'] == 0 || hinaArare['Y'] == 0) {
        cout << "Three" << endl;
    } else {
        cout << "Four" << endl;
    }
    
    return 0;
}