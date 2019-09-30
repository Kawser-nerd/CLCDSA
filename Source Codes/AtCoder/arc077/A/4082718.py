n = int(input())
a = list(int(i) for i in input().split())
aodd = []
aeven = []
for i in range(n):
 if i%2 == 1: aodd.append(a[i])
 else: aeven.append(a[i])
ans = []
if n%2 == 0:
  aeven.reverse()
  ans = aeven + aodd
else:
  aodd.reverse()
  ans = aodd+ aeven
ans.reverse()
  
print(*ans)