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

int a[100000];
int b[100000];

struct Data{
    int a;
    int b;
    int diff;
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
        d.diff = d.a - d.b;
        if( d.diff <= 0.0f )
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
        /* cout << datasDown[i].a << " " << datasDown[i].b << " " << X << endl; */
        /* cout << datasDown[i].a << " " << X << endl; */
        if( maxX < X )
        {
            maxX = X;
        }
        X -= datasDown[i].b;
        /* cout << datasDown[i].b << " " << X << endl; */
    }
    for (int i = 0; i < datasUp.size(); ++i) {
        X += datasUp[i].a;
        /* cout << datasDown[i].a << " " << X << endl; */
        /* cout << datasUp[i].a << " " << datasUp[i].b << " " << X << endl; */
        if( maxX < X )
        {
            maxX = X;
        }
        X -= datasUp[i].b;
        /* cout << datasDown[i].b << " " << X << endl; */
    }



    /* for (int i = 0; i < N; ++i) { */

    /*     /1* if( i != ( N - 1 ) ) *1/ */
    /*     /1* { *1/ */
    /*     /1*     X += datas[i].diff; *1/ */
    /*     /1* } *1/ */
    /*     /1* else *1/ */
    /*     /1* { *1/ */
    /*     /1*     X += datas[i].a; *1/ */
    /*     /1* } *1/ */

    /*     X += datas[i].a; */
    /*     cout << X << endl; */
    /*     X -= datas[i].b; */

    /*     /1* cout << datas[i].diff << endl; *1/ */
    /*     /1* cout << a[i] << " " << b[i] << endl; *1/ */
    /* } */

    cout << maxX << endl;

}