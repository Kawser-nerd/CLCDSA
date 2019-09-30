#include<iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

struct Cone{
    int begin;
    int end;
    double h;
    double V;
};
 
int main()
{
    // get a integer
    int N, Q;
    cin >> N;
    cin >> Q;
    vector<Cone> cones;
    /* double sum_V = 0.0; */
    for ( auto i = 0; i < N; ++i )
    {
        int x, r, h;
        cin >> x;
        cin >> r;
        cin >> h;
        Cone cone;
        cone.begin = x;
        cone.h = (double)h;
        cone.end = x + h;
        cone.V = r * r * M_PI * h / 3.0;
        /* cone.V = r * h / 3.0; */
        cones.push_back( cone );
        /* sum_V += cone.V; */
        /* cout << "sum " << sum_V << endl; */
    }

    for ( auto i = 0; i < Q; ++i )
    {
        int A, B;
        cin >> A;
        cin >> B;
        double sum_V = 0.0;
        for( auto cone : cones )
        {
            if( ( cone.end < A ) || ( B < cone.begin ) )
            {
            }
            else
            {
                /* cout << A << cone.begin << cone.end << B << endl; */
                /* cout << ( A <= cone.begin ) << endl; */
                /* cout << ( cone.end <= B ) << endl; */
                if( ( A <= cone.begin ) && ( cone.end <= B ) )
                {
                    /* cout << "hoge" << endl; */
                    sum_V += cone.V;
                }
                else if( ( A <= cone.begin ) && ( B <= cone.end ) )
                {
                    double rate = ( cone.end - B ) / cone.h;
                    rate = rate * rate * rate;
                    /* cout << "rate : " << rate << endl; */
                    sum_V += cone.V * ( 1.0 - rate );
                }
                else if( ( cone.begin <= A ) && ( cone.end <= B ) )
                {
                    double rate = ( cone.end - A ) / cone.h;
                    /* cout << "rate : " << rate << endl; */
                    rate = rate * rate * rate;
                    sum_V += cone.V * rate;
                }
                else 
                {
                    double rate1 = ( cone.end - B ) / cone.h;
                    double rate2 = ( cone.end - A ) / cone.h;
                    rate1 = rate1 * rate1 * rate1;
                    rate2 = rate2 * rate2 * rate2;
                    /* cout << "rate1 : " << rate1 << endl; */
                    /* cout << "rate2 : " << rate2 << endl; */
                    sum_V += cone.V * ( rate2 - rate1 );
                }
            }
        }
        /* cout << sum_V << endl; */
        printf( "%lf\n", sum_V );
    }


    return 0;
}