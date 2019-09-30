#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
int main() {
    int n;
    long hp,r=0;
    cin >> n >> hp;
    vector<long> a(n),b(n);
    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i];
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int lastI;
    for(int i=n-1; i>=0; i--){
        if(b[i] < a[n-1]){
            lastI = i + 1;
            break;
        }
    }

    int j = n-1;
    while(hp > 0){
        hp -= b[j];
        r++;
        if(j == lastI){
            if (hp <= 0) break;
            r += hp / a[n-1];
            if (hp % a[n-1] != 0) r++;
            break;
        }
        j--;
    }

    cout << r << endl;
}