import sys
from collections import Counter
inp = sys.stdin.readline

N, K = map(int,inp().split())
S = inp().replace("\n","")
sort_S = sorted(S)
T = ""
cnt = 0
for i in range(N):
  count = Counter(S[:i+1]) - Counter(list(T))
  sum_ = sum(count.values())
  for ss in sort_S:
    if(ss != S[i]):
      miss = cnt + 1
    else:
      miss = cnt
    if(count[ss] > 0):
      dif = sum_ - 1
    else:
      dif = sum_
    if(miss+dif <= K):
      T += ss
      sort_S.remove(ss)
      cnt = miss
      break
print(T)