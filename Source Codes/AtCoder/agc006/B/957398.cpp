#include <iostream>
using namespace std;
int main(){
    int N,x;
    cin>>N>>x;
    if(x==N){
        cout<<"Yes"<<endl;
        for(int i=1;i<2*N;i++) cout<<i<<endl;
    }else if(x==1||x==2*N-1){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
        int minus=x-1, plus=2*N-1-x;
        int m=x-1,p=x+1;
        if(minus==1){
            for(int i=0;i<N-1;i++){
                cout<<p++<<endl;
            }
            cout<<x<<endl;
            cout<<m--<<endl;
            for(int i=0;i<N-2;i++){
                cout<<p++<<endl;
            }
        }else{
            m=x-3,p=x+2;
            for(int i=0;i<N-2;i++){
                if(m>0){
                    cout<<m--<<endl;
                }else{
                    cout<<p++<<endl;
                }
            }
            cout<<x-1<<endl;
            cout<<x<<endl;
            cout<<x+1<<endl;
            cout<<x-2<<endl;
            for(int i=0;i<N-3;i++){
                if(m>0){
                    cout<<m--<<endl;
                }else{
                    cout<<p++<<endl;
                }
            }
        }
    }
    return 0;
}