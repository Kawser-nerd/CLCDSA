n, x = map(int, input().split())
alist = list(map(int, input().split()))
blist = alist[:]

ans = None
for i in range(n):
  for j in range(n):
    blist[j] = min(blist[j], alist[j-i])
  if ans is None:
    ans = i * x + sum(blist)
  else:
    ans = min(ans, i * x + sum(blist))
print(ans)