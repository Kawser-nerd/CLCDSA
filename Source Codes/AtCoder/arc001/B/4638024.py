from collections import deque
import math
def bfs(a,b):
    queue = deque([[a,0]])
    while queue:
        a,d = queue.popleft()#?????pop????????
        #print(a,d)
        if a == b:
            return d #??????
        for i in (1,-1,5,-5,10,-10):
            new_a = a + i
            new_d = d +1
            queue.append([new_a,new_d])
            
  
if __name__ == "__main__":
    a,b = map(int, input().split())

    print(bfs(a,b))