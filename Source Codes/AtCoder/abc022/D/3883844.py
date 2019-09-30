n = int(input())
a = [0]*n
b = [0]*n
c = [0]*n
d = [0]*n
for i in range(n):
  a[i],b[i] = map(int,input().split())
k = sum(a)/n
l = sum(b)/n
s = 0
for x in a:
  s += (x-k)**2
for x in b:
  s += (x-l)**2
  
for i in range(n):
  c[i],d[i] = map(int,input().split())
k = sum(c)/n
l = sum(d)/n
t = 0
for x in c:
  t += (x-k)**2
for x in d:
  t += (x-l)**2
print((t/s)**0.5)