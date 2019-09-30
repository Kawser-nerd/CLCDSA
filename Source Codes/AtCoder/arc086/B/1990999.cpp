#include<iostream>
#include<vector>
#include<map>

using namespace std;

int N;

int main(void) {
    cin>>N;
    int Max = -1e8,Min = 1e8;
    int Maxindex = -1,Minindex = -1;
    for(int i = 1;i <= N;i++) {
        int temp;
        cin>>temp;
        if(temp > Max) {
            Max = temp;
            Maxindex = i;
        }
        if(temp < Min) {
            Min = temp;
            Minindex = i;
        }
    }

    cout<<2*N-2<<endl;

    if(Max+Min > 0) {
        for(int x = 1;x <= N;x++) {
            if(Maxindex == x)
                continue;
            cout<<Maxindex<<" "<<x<<endl;
        }
        for(int x = 1;x <= N-1;x++) {
            int y = x+1;
            cout<<x<<" "<<y<<endl;
        }
    } else {
        for(int x = 1;x <= N;x++ ) {
            if(Minindex == x)
                continue;
            cout<<Minindex<<" "<<x<<endl;
        }
        for(int x = N;x >= 2;x--) {
            int y = x-1;
            cout<<x<<" "<<y<<endl;
        }
    }

    return 0;
}