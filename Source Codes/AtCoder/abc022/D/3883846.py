n = int(input())
a = [0]*n
b = [0]*n
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
  a[i],b[i] = map(int,input().split())
k = sum(a)/n
l = sum(b)/n
t = 0
for x in a:
  t += (x-k)**2
for x in b:
  t += (x-l)**2
print((t/s)**0.5)