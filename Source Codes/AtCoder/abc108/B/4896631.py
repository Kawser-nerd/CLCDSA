import heapq
def solve():
  x1,y1,x2,y2 = (int(i) for i in input().split())
  x = x2-x1
  y = y2-y1
  print(x2-y,y2+x,x1-y,y1+x)
 	
solve()