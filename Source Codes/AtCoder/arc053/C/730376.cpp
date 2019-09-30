#include<iostream>
#include<climits>
#include<string>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<algorithm>
#include<math.h>
using namespace std;

struct Data{
    int a;
    int b;
};

// ????????
bool compareUp(const Data &lhs, const Data &rhs)
{
    return lhs.b > rhs.b;
}

bool compareDown(const Data &lhs, const Data &rhs)
{
    return lhs.a < rhs.a;
}


int main()
{
    int N;
    cin >> N;
    vector<Data> datasUp;
    vector<Data> datasDown;
    for (int i = 0; i < N; ++i) {
        Data d;
        scanf( "%d %d", &d.a, &d.b );
        int diff = d.a - d.b;
        if( diff <= 0.0f )
        {
            datasDown.push_back( d );
        }
        else
        {
            datasUp.push_back( d );
        }
    }

    sort( datasDown.begin(), datasDown.end(), compareDown );
    sort( datasUp.begin(), datasUp.end(), compareUp );

    long long X = 0;
    long long maxX = -LONG_MAX;
    for (int i = 0; i < datasDown.size(); ++i) {
        X += datasDown[i].a;
        if( maxX < X )
        {
            maxX = X;
        }
        X -= datasDown[i].b;
    }
    for (int i = 0; i < datasUp.size(); ++i) {
        X += datasUp[i].a;
        if( maxX < X )
        {
            maxX = X;
        }
        X -= datasUp[i].b;
    }

    cout << maxX << endl;

}