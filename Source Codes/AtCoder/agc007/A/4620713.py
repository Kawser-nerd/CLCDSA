from collections import deque
h,w=[int(i) for i in input().split()]
a=[[i for i in input()] for _ in range(h)]
right_count=sum([sum([1 for j in range(w) if a[i][j]=="#"]) for i in range(h)])
pattern=[(1,0),(0,1)]
queue=deque([(0,0)])
def bfs():
    cnt=1
    while queue:
        (x,y)=queue.popleft()
        if (x,y)==(w-1,h-1):
            return cnt
        around=False
        for i,j in pattern:
            if y+i<h and x+j<w:
                if a[y+i][x+j]=="#":
                    queue.append((x+j,y+i))
                    around=True
                    cnt+=1
        if around==False:
            return False
print("Possible" if bfs()==right_count else "Impossible")