#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char a[51],b[51],c[102];
int main(){
    while(cin>>a>>b){
        if(strlen(a)-strlen(b)==1||strlen(a)-strlen(b)==0)
        {int t=0;
            for(int i=0;i<strlen(a);i++)
            {
                c[t]=a[i];
                t=t+2;
            }
            t=1;
            for(int i=0;i<strlen(b);i++)
            {
                c[t]=b[i];
                t=t+2;
            }cout<<c<<endl;

        }            else
                break;

    }

    }