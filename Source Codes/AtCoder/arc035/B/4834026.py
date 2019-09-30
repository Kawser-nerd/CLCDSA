import math
N = int(input())
L = []
for i in range(N):
  L.append(int(input()))
L.sort()
L.append(0)
cnt = 1
ans = 1
time = [L[0]]
cur = L[0]
for i in range(1,N+1):
  if L[i] == cur:
    cnt += 1
  else:
    ans *= math.factorial(cnt)
    ans %= (10**9+7)
    cur = L[i]
    cnt = 1
  if i != N:
    time.append(time[i-1]+L[i])
print(sum(time))
print(ans)