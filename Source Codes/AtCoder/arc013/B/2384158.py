N = int(input())
n = m = l = 0
for i in range(N):
  a = list(map(int, input().split()))
  a.sort()
  n = max(n, a[0])
  m = max(m, a[1])
  l = max(l, a[2])
print(n * m * l)