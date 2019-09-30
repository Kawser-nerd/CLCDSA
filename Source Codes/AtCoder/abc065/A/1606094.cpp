#include<iostream>
#include<string>
using namespace std;

int main()
{

   long d, a, b;

   cin >> d;
   cin >> a;
   cin >> b;

   if (a >= b)
   {
       cout << "delicious";
   }
   else
   {
        if (b - a <= d)
        {
            cout << "safe";
        }
        else
        {
            cout << "dangerous";
        }
   }

}