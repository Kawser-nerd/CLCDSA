#include<iostream>

using namespace std;

int main(void) {
    int N;
    cin>>N;
    int x,y,t;

    x = y = 0;
    t = 0;

    for(int i = 0;i < N;i++) {
        int c,a,b;
        cin>>c>>a>>b;

        if(((abs(x-a)+abs(y-b)) % 2 == (c-t) % 2) && abs(x-a)+abs(y-b) <= (c-t)) {
            
        } else {
            cout<<"No"<<endl;

            return 0;
        }

        x = a;
        y = b;
        t = c;
    }

    cout<<"Yes"<<endl;

    return 0;
}