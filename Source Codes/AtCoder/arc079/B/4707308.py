k = int(input())
n = 50
tmp = k // 50
a = [49 + tmp for _ in range(n)]
k %= 50
for i in range(k):
  m = min(a)
  isp = True
  for j in range(n):
    if a[j] == m and isp:
      a[j] += n
      isp = False
    else:
      a[j] -= 1
print(n)
print(*a, sep=' ')