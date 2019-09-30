n,m = map(int,input().split())
ans = 10 ** 9
lis = [list(map(int,input().split())) for i in range(n)]
for i in range(m):
  num = [0 for i in range(m)]
  for j in range(n):num[lis[j][0]-1] += 1
  ans = min(max(num),ans)
  for k in range(n):lis[k].remove(num.index(max(num))+1)
print(ans)