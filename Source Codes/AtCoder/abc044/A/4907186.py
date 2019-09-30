N, K, X, Y = map(int, open(0).read().split()) 
if N <= K:
  a = N * X
  print(a)
else:
  a = K * X + (N - K) * Y
  print(a)