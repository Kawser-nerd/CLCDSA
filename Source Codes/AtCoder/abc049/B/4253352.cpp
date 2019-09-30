#include <iostream>
using namespace std;
#include <algorithm>
#include <string>
#include <vector>
struct s1
{
    char name[100];
};
int main()
{

    int w,h;
    cin>>h>>w;
    s1 s[h];
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>s[i].name[j];
        }
    }
    for(int i=0;i<h*2;i++)
    {
        for(int j=0;j<w;j++)
        {
            cout<<s[i/2].name[j];
        }
        cout<<endl;
    }
    return 0;
}