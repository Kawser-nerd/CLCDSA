N = int(input())
X = list(map(int, input().split()))

Y = sorted(X)
a1 = Y[N//2 - 1]
a2 = Y[N//2]

for i in range(N):
  if X[i] <= a1:
    print(a2)
  else:
    print(a1)