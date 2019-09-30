import bisect
n,k = map(int,input().split())
x = list(map(int,input().split()))
for i in range(n):
  x[i] = [x[i],i]
a = sorted(x[:k])
# print(a)
print(a[-1][1]+1)

for i in range(k,n):
  bisect.insort(a, x[i])
  a.pop(-1)
  print(a[-1][1]+1)