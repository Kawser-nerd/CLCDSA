#include <iostream>
using namespace std;

int main(){
   int A, B, total;
   
   cin >> A >> B;
   
   total = A +  B;
   if(total < 10) cout << total << endl;
   else if(total >= 10) cout << "error" << endl;

}