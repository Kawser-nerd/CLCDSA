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
    char c;
    int v;
};

bool operator<(const Data &lhs, const Data &rhs)
{
    return lhs.v < rhs.v;
}

int main()
{
    int counter[26];
    memset( counter, 0, 26 * 4 );
    // get a integer
    string S;
    cin >> S;
    for (auto&& c : S) {
        counter[ c - 'a' ] += 1;
    }
    /* map<char> dict; */
    /* set<Data> sorted_list; */
    int supply = 0;
    int odds_count = 0;
    for (auto&& co : counter) {
        supply += co / 2;
        /* supply += co; */
        if( co % 2 == 1 )
        {
            odds_count++;
        }
    }

    /* cout << odds_count << endl; */
    /* cout << supply << endl; */
    if( odds_count == 0 )
    {
        cout << supply * 2 << endl;
    }
    else if( odds_count > supply )
    {
        cout << 1 << endl;
    }
    else
    {
        cout << ( supply / odds_count ) * 2 + 1 << endl;
    }


}