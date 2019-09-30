#include <iostream>

using namespace std;

int main()
{
long n, tn[100001], sumt=0, m, pm, xm ,result[100001];
cin>>n; for (int i=0 ; i<n; i++){cin >>tn[i];sumt+=tn[i];}
cin >>m;
for (int i=0 ; i<m; i++){
cin>>pm >>xm;
result [i]= sumt -tn[pm-1]+xm;
}
for (int i=0 ; i<m; i++)cout <<result[i]<<endl;
    return 0;
}