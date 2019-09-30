N = int(input())
L = list(map(int,input().split()))
ans = float('inf')
for j in range(-100,101):
  S = 0
  for i in range(N):
    S += (L[i]-j)**2
  if S <= ans:
    ans = S
print(ans)