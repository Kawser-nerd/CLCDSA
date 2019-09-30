N,K = map(int, input().strip().split())
S = input().strip()
 
def ctoi(c):
  return ord(c) - ord('a')
 
def solve():
  if K*2 > N: return False
  ctr = [0 for i in range(26)]
  hs = {}
  for i in range(N):
    ctr[ctoi(S[i])] += 1
    if i < K-1: continue
    if i >= K:
      ctr[ctoi(S[i-K])] -= 1
    h = tuple(ctr)
    st = i-K+1
    #h = hash(tuple(ctr))
    if h in hs:
      if hs[h] + K <= st:
        return True
    else:
      hs[h] = st
  return False

if solve():
  print('YES')
else:
  print('NO')