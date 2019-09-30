#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if(n==0000){
        cout << "SAME" <<'\n';
    }else if(n%1111 == 0){
        cout <<"SAME" << '\n';
    }
    else if(n/1000 == 0){
        cout<<"DIFFERENT" << '\n';
    }
    else{
        cout <<"DIFFERENT"<< '\n';
    }

}