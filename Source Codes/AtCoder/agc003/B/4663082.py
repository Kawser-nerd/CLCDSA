n = int(input())
a = [int(input()) for _ in range(n)]
pairs = 0
for i in range(n-1):
  pairs += a[i]//2
  a[i] %= 2
  if a[i]:
    syu = min(a[i],a[i+1])
    a[i+1] -= syu
    pairs += syu
pairs += a[-1]//2
print(pairs)