n,k = map(int, input().split())
a = list(map(int, input().split()))
tot = 0
for i in range(1,n):
  if a[i-1] + a[i] > k:
    c = min(a[i],a[i]+a[i-1]-k)
    tot += c
    a[i] -= c
    if a[i-1]+a[i] > k:
      d = a[i-1]-k
      tot += d
      a[i-1] -= d
print(tot)