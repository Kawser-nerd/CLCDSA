N, M = map(int, input().split())
X = sorted(list(map(int, input().split())))

btw = []
for i in range(M):
  if i == M - 1:
    break
  else:
    btw.append(X[i+1] - X[i])
btw = sorted(btw, reverse=True)

ans =0
for e in btw[N-1:]:
  ans += e
 
print(ans)