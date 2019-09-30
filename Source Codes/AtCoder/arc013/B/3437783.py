n = int(input())
lis = [sorted(list(map(int,input().split()))) for i in range(n)]
a = 0
b = 0
c = 0
for x,y,z in lis:
  a = max(a,x)
  b = max(b,y)
  c = max(c,z)
print(a * b * c)