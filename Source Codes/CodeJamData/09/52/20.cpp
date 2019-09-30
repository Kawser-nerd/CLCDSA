// =====================================================================================
//   [ Filename    ]  pbsmall.cpp
//   [ Description ]  
//   [ Created     ]  10/11/2009 12:04:46 AM CST
//   [ Author      ]  Jiunru Yang , yangjiunru [at] gmail.com, NTUEE
// =====================================================================================

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Sol
{
   public:
      void read()
      {
         cin >> _expr;
         cin >> _k;
         int n;
         cin >> n;
         _dict.resize(n);
         for (int i = 0; i < n; ++i)
            cin >> _dict[i];
      }

      unsigned evaluate(const vector<unsigned>& f) 
      {
         unsigned r = 0;
         unsigned t = 1;
         for (int i = 0; i < _expr.length(); ++i) {
            if (_expr[i] == '+') {
               r += t;
               r %= 10009;
               t = 1;
            }
            else {
               t *= f[_expr[i] - 'a'];
               t %= 10009;
            }
         }
         r += t;
         r %= 10009;
         return r;
      }

      void countDict()
      {
         _dictCnt.resize(_dict.size(), vector<unsigned>(26));
         for (int i = 0; i < _dict.size(); ++i) {
            for (int j = 0; j < _dict[i].length(); ++j)
               ++_dictCnt[i][_dict[i][j]-'a'];
         }
      }

      unsigned compute(unsigned K)
      {
         vector<unsigned> cur(26, 0);
         return computeRecur(K, cur);
      }

      unsigned computeRecur(unsigned K, vector<unsigned>& cur)
      {
         if (K == 0)
            return evaluate(cur);
         unsigned sum = 0;
         for (unsigned i = 0; i < _dict.size(); ++i) {
            for (unsigned j = 0; j < 26; ++j)
               cur[j] += _dictCnt[i][j];
            sum += computeRecur(K-1, cur);
            sum %= 10009;
            for (unsigned j = 0; j < 26; ++j)
               cur[j] -= _dictCnt[i][j];
         }
         return sum;
      }

      void solve(int caseNo)
      {
         read();
         countDict();
         cout << "Case #" << caseNo << ": ";
         for (unsigned i = 1; i <= _k; ++i)
            cout << compute(i) << " ";
         cout << endl;
      }

      unsigned _k;
      vector<string> _dict;
      vector<vector<unsigned> > _dictCnt;
      string _expr;
};

int main()
{
   int T;
   cin >> T;
   for (int t = 1; t <= T; ++t) {
      Sol s;
      s.solve(t);
   }
   return 0;
}
