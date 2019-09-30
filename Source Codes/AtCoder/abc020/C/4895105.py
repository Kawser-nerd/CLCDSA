import heapq


h,w,t= (int(i) for i in input().split())
maze = [input() for _ in range(h)]
  
for i,s in enumerate(maze):
 for j ,ss in enumerate(s):
     if ss == 'S':
      start = (i,j)
     elif ss == 'G':
      goal = (i,j)
  #print(start,goal)
def solve(n):
  v = [[False for _ in range(w)] for _ in range(h)]
  q = [(0,start)]
  dx = [(0,1),(1,0),(-1,0),(0,-1)]
  while q:
   c,(i,j) = heapq.heappop(q)
   for di,dj in dx:
    ni,nj = i+di, j+dj
  
    if ni < 0 or ni >= h or nj<0 or nj >= w:
     continue
    if v[ni][nj] :
     continue   
    else:
     v[ni][nj] = True
    #print(ni,nj)
    nc = c + (n if maze[ni][nj] == '#' else 1)
    if ((ni,nj) == goal):
     return nc<=t
    heapq.heappush(q,(nc,(ni,nj)))
  return False
low,high = 1,t
while low +1 < high:
                  mid = (low+high)//2
                  if solve(mid):
                   low = mid
                  else:
                   high = mid
print(low)