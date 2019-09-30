A, B, C, K = map(int, input().split())
S, T = map(int, input().split())

amount = S*A + T*B
if (S+T) >= K:
  amount -= C*(S+T)
print(amount)