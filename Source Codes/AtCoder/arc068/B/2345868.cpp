#include <iostream>
#include <iterator>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    int n, a;
    cin >> n;
    set<int> card;
    for(int i = 0; i < n; i++){
        cin >> a;
        card.insert(a);
    }

    cout << (card.size() % 2 == 0 ? card.size() - 1 : card.size()) << endl;
    return 0;
}