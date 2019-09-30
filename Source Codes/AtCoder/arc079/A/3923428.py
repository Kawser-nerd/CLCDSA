N, M = map(int, input().split())
X = [[-1]*2 for i in range(N)]
for _ in range(M):
    a, b = sorted(map(int, input().split()))
    if a == 1:
        if X[b][1] > 0:
            print("POSSIBLE")
            break
        else:
            X[b][0] = 1
    if b == N:
        if X[a][0] > 0:
            print("POSSIBLE")
            break
        else:
            X[a][1] = 1
else:
  print("IMPOSSIBLE")