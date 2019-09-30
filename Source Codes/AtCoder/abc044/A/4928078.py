N = int(input())
K = int(input())
X = int(input())
Y = int(input())

if N < K:
  print(int(N*X))
else:
  print(int(K*X+(N-K)*Y))