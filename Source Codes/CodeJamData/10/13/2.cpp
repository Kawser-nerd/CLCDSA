#include<algorithm>
#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;

int L[1000001];
int R[1000001];
double A = (-1.0 + sqrt(5.0)) / 2.0;
double B = (1.0 + sqrt(5.0)) / 2.0;

int main()
{

    freopen("C.in" , "r" , stdin);
    freopen("C.out" , "w" , stdout);
    for(int i = 1 ; i <= 1000000 ; i++)
    {
        L[i] = floor(B * (double)i) - i + 1;
        R[i] = floor(B * (double)i);
    }
    int T;
    cin>>T;
    for(int caseID = 1 ; caseID <= T ; caseID ++)
    {
        int x1 , x2 , y1 , y2;
        long long cnt = 0;
        cin>>x1>>x2>>y1>>y2;
        for(int i = x1 ; i <= x2 ; i++)
        {
            int lef = max(L[i] , y1) , rig = min(R[i] , y2);
            cnt += y2 - y1 + 1;
            if(lef <= rig)
                cnt -= rig - lef + 1;
        }
        cout<<"Case #"<<caseID<<": "<<cnt<<endl;
    }
    return 0;
}
