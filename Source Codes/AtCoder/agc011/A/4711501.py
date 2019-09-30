N,C,K=map(int, input().split())
l = []
ans = 0
for i in range(N):
    l.append(int(input()))
l.sort()
l.append(float("INF"))
l = l[::-1]
while len(l)>1:
  h=l.pop()
  i=h
  j=1
  while len(l)>1 and j<C and h+K>=l[-1]:
    i=l.pop()
    j+=1
  ans+=1
print(ans)