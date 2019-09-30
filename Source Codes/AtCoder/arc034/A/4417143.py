n = int(input())
m = 0
for _ in range(n):
  l = list(map(int,input().split()))
  l[4] *= 110/900
  s = sum(l)
  if m < s:
    m = s
print(m)