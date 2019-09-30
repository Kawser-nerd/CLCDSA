import itertools

def compute(P):
  K = len(P)
  assert K%2 == 0
  
  # DP[i][k] : probability to have k "Yes" with i people
  DP = [[0.0] * (K + 1) for _ in range(K + 1)]
  DP[0][0] = 1.0

  for i in range(1, K+1):
    for k in range(i+1):
      DP[i][k] = 0.0
      DP[i][k] += DP[i-1][k-1] * PP[i-1]
      DP[i][k] += DP[i-1][k] * (1 - PP[i-1])
  return DP[K][K/2]

_T = int(raw_input())
for _t in range(1, _T+1):
  N, K = map(int, raw_input().split())
  P = map(float, raw_input().split())

  res = 0.0
  P.sort()
  for i in range(K+1):
    PP = P[:i] + P[N-(K-i):]
    res = max(compute(PP), res)


  print 'Case #{}: {}'.format(_t, res)
