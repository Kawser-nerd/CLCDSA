K=int(input())
N=int(input())
A=[0]*N
D=[0]*N
for i in range(N):
    A[i], D[i] = map(int,(input().split()))

def get(M):
  res = 0
  for i in range(N):
    if M >= A[i]:
      res += 1 + (M-A[i])//D[i]
  return res

lo = 0
hi = pow(10, 15)
while hi - lo > 1:
  mid = (hi + lo) // 2
  if get(mid) >= K:
    hi = mid
  else:
    lo = mid

M = hi
k = 0
ans = 0
for i in range(N):
  if M >= A[i]:
    n = (M - A[i]) // D[i]
    ans += (n+1)*A[i]
    ans += D[i]*(n+1)*n//2
    k += n+1
    if (k >= K) :
      ans -= (k - K) * M
      k = K
print(ans)