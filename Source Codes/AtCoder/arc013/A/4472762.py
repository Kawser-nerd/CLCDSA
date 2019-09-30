def ans():
  N, M, L = map(int,input().split())
  P, Q, R = map(int,input().split())
  res = 0
  for a, b, c in [[P,Q,R],[P,R,Q],[Q,P,R],[Q,R,P],[R,P,Q],[R,Q,P]]:
    res = max(res, (N//a)*(M//b)*(L//c))
  print(res)
ans()