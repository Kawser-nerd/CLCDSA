#include<iostream>
#include<climits>
#include<string>
#include<vector>
#include<list>
#include<math.h>
using namespace std;

/* int a[100001]; */

int main()
{
    // get a integer
    int N;
    cin >> N;
    long long counter = 0;
    int increment = 1;

    int prev = 0;
    int continuity = 1;
    for (int i = 0; i < N; ++i) {
        int a;
        scanf( "%d", &a );
        counter += 1;
        if( i > 0 )
        {
            if( prev < a )
            {
                counter += continuity;
                continuity++;
            }
            else
            {
                continuity = 1;
            }
        }
        prev = a;
    }

    cout << counter << endl;

}