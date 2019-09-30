A, B, C, K = map(int, input().split())
S, T = map(int, input().split())
tmp = 0

if S+T >= K:
  tmp = - C*(S+T)
print(A*S+B*T+tmp)