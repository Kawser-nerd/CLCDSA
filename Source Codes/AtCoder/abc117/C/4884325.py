N,M = map(int, input().split())
Xkari = list(map(int, input().split()))
X = sorted(Xkari)

if N >= M:
  print(0)
else:
  D = []
  for i in range(M - 1):
    D.append(X[i + 1] - X[i])
  D = sorted(D)[::-1]
  D = D[:N-1]
  ans = X[M - 1] - X[0] - sum(D)
  print(ans)