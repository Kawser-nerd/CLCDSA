using namespace std;
#include<iostream>

int main()
{
    int a,b;
         cin>>a>>b;
         char arr[a][b];
         for(int i=0;i<a;i++)
         {
             for(int j=0;j<b;j++)
             cin>>arr[i][j];
         }
         for(int x=0;x<b+2;x++)
         cout<<"#";
         cout<<endl;
         for(int y=0;y<a;y++)
         {
             cout<<"#";
             for(int z=0;z<b;z++)
             cout<<arr[y][z];
             cout<<"#"<<endl;
         }
         for(int s=0;s<b+2;s++)
         cout<<"#";
         return 0;
} ./Main.cpp:3:17: warning: using directive refers to implicitly-defined namespace 'std'
using namespace std;
                ^
1 warning generated.