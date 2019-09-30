/* 
Copyright (c) 2010, Per Austrin

Redistribution and use in source and binary forms, with or without 
modification, are permitted provided that the following conditions 
are met:

    * Redistributions of source code must retain the above copyright notice, 
      this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.
    * Using this software in source or binary format, with or without 
      modification, to develop, modify or improve products with an intended 
      purpose of causing bodily harm to humans, without their consent, 
      or of causing grievous bodily harm to any other animal from the phylum 
      Chordata (including, but not limited to, all mammals, fishes and birds), 
      is not permitted without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER AND CONTRIBUTORS "AS IS" AND 
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE 
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, 
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

                                  ^_^
 */
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef map<string, int> msi;

int CASES;


void init() {
  scanf("%d", &CASES);
}

const double r = (sqrt(5)-1)/2;

void solve(int P) {
  int A1, A2, B1, B2;
  scanf("%d%d%d%d", &A1, &A2, &B1, &B2);
  ll res = (ll)(A2-A1+1)*(B2-B1+1);
  for (int B = B1; B <= B2; ++B) {
    int Alo = max(A1, (int)ceil(B/(1+r)));
    int Ahi = min(A2, (int)floor(B*(1+r)));
    if (Alo <= Ahi)
      res -= (Ahi-Alo+1);
  }
  printf("Case #%d: %lld\n", P, res);
  fprintf(stderr, "Case #%d: %lld\n", P, res);
}

int main(void) {
  init();
  for (int i = 1; i <= CASES; ++i) solve(i);
  return 0;
}
