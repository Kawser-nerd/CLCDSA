#include <iostream>
        #define endl '\n'
    	#define ll long long
         
        using namespace std;
         
        int main(void)
        {
          cin.tie(NULL); ios_base::sync_with_stdio(false);
          int N; cin >> N;
          ll acc = 0;
          ll temp;
          while(N--)
          {
            cin >> temp;
            acc += temp - 1;
          }
          cout << acc << endl;
          return 0;
        }