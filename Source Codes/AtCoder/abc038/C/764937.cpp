#include <iostream>
#include <vector>

using uli = unsigned long int;

using namespace std;

int main(void)
 {
   int n;
   cin >> n;

   vector<int> vec(n);
   for(int i = 0; i < n; i++)
     cin >> vec[i];

   uli total = n;

   uli b = 0;
   uli i;
   while(b != n){
     for(i = b+1; i < n && vec[i] > vec[i-1] ; i++);
     total += (i-b)*(i-b-1) / 2;
     b = i;
   }

   cout << total << endl;
 }