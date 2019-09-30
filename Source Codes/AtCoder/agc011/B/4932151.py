n =int(input())
a = list(map(int,input().split()))
a.sort()
l,r=0,n
while l != r - 1:
  t = (l + r) // 2
  s = sum(a[:t])
  for m in a[t:]:
    if s * 2 < m:
      l = t
      break
    s += m
  else:
    r = t
print(n - l)