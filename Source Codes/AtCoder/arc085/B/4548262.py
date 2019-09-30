N, Z, W = map(int, input().split())
a = list(map(int, input().split()))
ans = abs(a[N-1]-W)
if N > 1:
  ans = max(ans,abs(a[N-2]-a[N-1]))
print(ans)