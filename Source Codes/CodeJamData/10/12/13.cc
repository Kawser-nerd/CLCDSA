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

int D, I, M, N;
int pix[200];
int cost[200][300][2];

bool smooth(int x, int y) {
  return x == 256 || y == 256 || abs(x-y) <= M;
}

int Cost(int at, int val, bool insert) {
  if (at < 0) return 0;
  int &res = cost[at][val][insert];
  if (res < 0) {
    res = D + Cost(at-1, val, true);
    for (int v = 0; v < 256; ++v) {
      if (smooth(v, val))
	res = min(res, abs(v-pix[at]) + Cost(at-1, v, true));
      if (insert && M > 0) {
	int c = 1;
	if (!smooth(v, val)) c = (abs(v-val) + M - 1) / M;
	res = min(res, c*I + Cost(at, v, false));
      }
    }
    //    printf("Cost(%d %d %d) = %d\n", at, val, insert, res);
  }
  return res;
}

void solve(int P) {
  scanf("%d%d%d%d", &D, &I, &M, &N);
  for (int i = 0; i < N; ++i) scanf("%d", pix+i);
  memset(cost, -1, sizeof(cost));
  printf("Case #%d: %d\n", P, Cost(N-1, 256, true));
  fprintf(stderr, "Case #%d: %d\n", P, Cost(N-1, 256, true));
}

int main(void) {
  init();
  for (int i = 1; i <= CASES; ++i) solve(i);
  return 0;
}
