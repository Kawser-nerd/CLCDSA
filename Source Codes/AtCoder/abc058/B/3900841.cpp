#include <iostream>

using namespace std;

int main(void)
{
    string O, E;
    cin >> O >> E;

    int le = E.size();
    for(int i = 0; i < le; ++i)
        cout << O[i] << E[i];

    if(O.size() - le)
        cout << *O.rbegin();

    cout << endl;
    return 0;
}