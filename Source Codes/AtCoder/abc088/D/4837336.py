import queue
h, w = map(int, input().split())
d=[(0, 1), (1, 0), (0, -1), (-1, 0)]
s=[list(input()) for i in range(h)]
m=[[-1]*w for i in range(h)]
m[0][0]=1
q = queue.Queue()
q.put((0, 0))
while not q.empty():
    p=q.get()
    for i in range(4):
        x=p[0]+d[i][0]
        y=p[1]+d[i][1]
        if 0<=x<h and 0<=y<w and m[x][y]<0 and s[x][y]=='.':
            q.put((x, y))
            m[x][y]=m[p[0]][p[1]]+1
dis=m[h-1][w-1]
c=sum(si.count('.') for si in s)
print(c-dis if dis>0 else -1)