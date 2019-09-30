#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int countt(int a[],int b,int c){
    int p = 0;
    for(int i = 0;i<b;i++){
        if(a[i] == c){
            p++;
        }
    }
    return p;
}
int main(){
    int n,m,k;
    cin >> n >> m;
    int check[m];
    int tem[m];
    for (int i = 0;i<m;i++){
        check[i] = 0;
        tem[i] = 0;
    }
    for(int i = 0;i<n;i++){
        cin >> k;
        for(int j = 0;j<k;j++){
            cin >> tem[j];
        }
        for(int j = 0;j<m;j++){
            check[j] = check[j] + countt(tem,m,j+1);
        }
        for(int j = 0;j<m;j++){
            tem[j] = 0;
        }
    }
    cout << countt(check,m,n) << endl;
}