#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>

#define MOD (1000000007)

using namespace std;

typedef long long int Int;

int main(void) {
    int a,b,c;
    int x,y;
    int sum = 1<<30;

    cin>>a>>b>>c>>x>>y;

    for(int i = 0;i <= 100000;i++) {
        sum = min(i*2*c + max(0,x-i)*a+max(0,y-i)*b,sum);
    }

    cout<<sum<<endl;

    return 0;
}