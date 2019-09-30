n = int(input())
res = []
for i in range(n):
  a,b,c,d,e = map(int,input().split())
  res.append(a+b+c+d+e*110/900)
print(max(res))