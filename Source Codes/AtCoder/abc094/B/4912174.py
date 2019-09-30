N, M, X = map(int, input().split())

A = list(map(int, input().split()))

ans = []

c = 0

for i in range(N):
  if i == X:
    ans.append(c)
    c = 0
    continue
  if i in A:
    c += 1
  if i == N-1:
    ans.append(c)
print(min(ans))