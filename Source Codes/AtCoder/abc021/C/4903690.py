N= int(input())
a,b = list(map(int, input().split()))
M=int(input())
XY = [list(map(int, input().split())) for _ in range(M)]

mod = int(1e9+7)

edges_from={}
for x, y in XY:
  edges_from.setdefault(x, set()).add(y)
  edges_from.setdefault(y, set()).add(x)

to_visit=set([a])
visited=set([a])

nums=[0]*(N+1)
nums[a]=1

while True:
  #print(to_visit)
  
  next_visit=set()
  for v in to_visit:
    for u in edges_from[v]:
      if u not in visited:
        next_visit.add(u)
        nums[u]=(nums[u]+nums[v])%mod
  #print(nums)
        
  if nums[b]:
    print(nums[b])
    break
    
  to_visit = next_visit
  visited = visited | to_visit