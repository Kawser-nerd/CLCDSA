N,M=map(int,input().split(' '))
route={ int(i):[] for i in range(N) }
for i in range(M):
  a,b=map(int,input().split(' '))
  route[a-1].append(b-1)
  route[b-1].append(a-1)
ans='IMPOSSIBLE'
for island in route[0]:
  if N-1 in route[island]:
    ans='POSSIBLE'
    break
print(ans)