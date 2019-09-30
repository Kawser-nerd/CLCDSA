n = int(input())
a = []
for _ in [0]*n:
  a.append(int(input()))
a.sort()
s = 0
m = 1
c = 1
for i in range(n):
  if i>0:
    if a[i-1] == a[i]:
      c += 1
      m = m*c%1000000007
    else:
      c = 1   
  s += (n-i)*a[i]
print(s)
print(m)