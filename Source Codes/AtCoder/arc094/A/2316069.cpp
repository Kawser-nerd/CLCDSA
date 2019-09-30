#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<algorithm>

#define MOD (1000000007)

using namespace std;

typedef long long int Int;

int main(void) {
    int a,b,c;
    cin>>a>>b>>c;

    int sum = 0;
    while(true) {
    if(a == b && b == c) {
        break;
    }
    if(a < b) {
        swap(a,b);
    }
    if(a < c) {
        swap(a,c);
    }
    if(b < c) {
        swap(c,b);
    }
    if(b == c) {
        sum += a - b;
        b = a;
        c = a;
    } else {
        c += 2;
        sum++;
    }
    
    }

    cout<<sum<<endl;

    return 0;
}