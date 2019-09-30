#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

char s[5004];
int cnt[26][26];
int a[52][52];
int in[52], out[52];
int q[52], vis[52];
bool d[26];

int main()
{
  #ifdef __FIO
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  int T;
  scanf("%d", &T);
  d['a'-'a'] = 1;
  d['o'-'a'] = 1;
  d['i'-'a'] = 1;
  d['e'-'a'] = 1;
  d['s'-'a'] = 1;
  d['t'-'a'] = 1;
  d['b'-'a'] = 1;
  d['g'-'a'] = 1;
  for(int i0 = 1; i0 <= T; i0++){
    printf("Case #%d: ", i0);
    int n;
    int i, j;
    int h, t;
    int ans = 0;
    scanf("%*d");
    scanf("%s", s);
    n = strlen(s);
    memset(cnt, 0, sizeof cnt);
    for(i = 0; i < n-1; i++)
      cnt[s[i]-'a'][s[i+1]-'a'] = 1;
    memset(a, 0, sizeof a);
    for(i = 0; i < 26; i++)
      for(j = 0; j < 26; j++){
        if(cnt[i][j]){
          a[i][j] = 1;
          if(d[i])
            a[i+26][j] = 1;
          if(d[j]){
            a[i][j+26] = 1;
            a[i+26][j+26] = d[i];
          }
        }
      }
    memset(in, 0, sizeof in);
    memset(out, 0, sizeof out);
    for(i = 0; i < 52; i++)
      for(j = 0; j < 52; j++)
        if(a[i][j]){
          out[i]++;
          in[j]++;
          ans++;
        }
    memset(vis, 0, sizeof vis);
    for(int k = 0; k < 52; k++){
      h = t = 0;
      if((in[k]||out[k])&&!vis[k]){
        q[t++] = k;
        vis[k] = 1;
        while(h < t){
          i = q[h++];
          for(j = 0; j < 52; j++)
            if((a[i][j] || a[j][i]) && !vis[j]){
              vis[j] = 1;
              q[t++] = j;
            }
        }
        for(i = 0; i < t; i++)
          if(in[q[i]] != out[q[i]])
            break;
        if(i == t)
          ans++;
      }
    }
    for(i = 0; i < 52; i++)
      if(in[i] > out[i])
        ans += in[i]-out[i];
    printf("%d\n", ans);
  }
  return 0;
}
