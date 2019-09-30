from collections import deque

N, M = list(map(int, input().split()))

memo = {}

for _ in range(M):
  u,v = list(map(int, input().split()))
  memo.setdefault(u, set()).add(v)
  memo.setdefault(v, set()).add(u)
 
to_visit= set([i for i in range(1,N+1)])
visited = set([])

answer =0

while to_visit:
  v = to_visit.pop()
  visited.add(v)
  
  dq = deque([(v, None)])
  is_tree = 1

  while dq:
    v, frm = dq.pop()
    for u in memo.get(v,[]):
      if u==frm:
          continue
      if u in visited:
        is_tree = 0
      else:
        visited.add(u)
        to_visit.remove(u)
        dq.append((u, v))
        
  if is_tree:
    answer +=1
    
print(answer)