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
#include <map>
#include <string>
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

int n, k;
char input[100][100];
char output[100][100];

void rotate() {
  memset(output, '.', sizeof(output));
  for (int i = 0; i < n; ++i)
    for (int j = n-1, k = n-1; j >= 0; --j)
      if (input[i][j] != '.')
	output[i][k--] = input[i][j];
}

int count(char c) {
  int r = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      for (int di = 0; di <= 1; ++di)
	for (int dj = -1; dj <= 1; ++dj) {
	  if (!di && !dj) continue;
	  int cnt = 0, ni = i, nj = j;
	  while (ni < n && nj >= 0 && nj < n && output[ni][nj] == c)
	    ++cnt, ni += di, nj += dj;
	  if (cnt > r) r = cnt;
	}
  return r;
}
  
const char *msg[4] = {"Neither", "Red", "Blue", "Both"};

void solve(int P) {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i)
    scanf("%s", input[i]);
  rotate();
  int r = count('R') >= k, b = count('B') >= k;
  printf("Case #%d: %s\n", P, msg[2*b+r]);
}

int main(void) {
  init();
  for (int i = 1; i <= CASES; ++i) solve(i);
  return 0;
}
