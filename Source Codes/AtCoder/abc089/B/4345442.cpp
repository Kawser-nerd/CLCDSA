#include<iostream>
#include<set>

using namespace std;

int main(){
    int N;
    bool flag=false;
    cin >> N;
    set<char> S;
    for(int i = 0; i < N; i++){
        char a;
        cin >> a;
        if(a=='Y')flag=true;
    }
    if(flag){
        cout << "Four" << endl;
    }else{
        cout << "Three" << endl;
    }
}