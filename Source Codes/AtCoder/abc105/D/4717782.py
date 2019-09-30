n, m = [int(item) for item in input().split()]
a = [int(item) for item in input().split()]

cumsum = [0] * n
for i in range(n):
  if i == 0:
    cumsum[i] = a[i] % m
  else:
    cumsum[i] = (cumsum[i-1] + a[i]) % m

cumsum = sorted(cumsum)
variation = {}

for i in cumsum:
  if i in variation:
    variation[i] += 1
  else:
    variation[i] = 1

ans = 0
for key in variation:
  if key == 0:
    ans += variation[key]
  ans += variation[key] * (variation[key]-1) // 2
  
print(ans)