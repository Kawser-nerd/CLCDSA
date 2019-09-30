import queue

h,w = map(int, input().split())
s = [input() for i in range(h)]

white = 0

for i in range(h):
    for j in range(w):
        if s[i][j]=='.':
            white += 1

q = queue.Queue()

move = [[0,1],[0,-1],[1,0],[-1,0]]

q.put([0,0])

inf = float('inf')
d = [[inf for i in range(w)] for j in range(h)]
d[0][0] = 0

while not q.empty():
    p = q.get()
    for m in move:
        if 0<=p[0]+m[0]<h and 0<=p[1]+m[1]<w and d[p[0]+m[0]][p[1]+m[1]] == inf and s[p[0]+m[0]][p[1]+m[1]] != '#':
            d[p[0]+m[0]][p[1]+m[1]] = d[p[0]][p[1]]+1
            q.put([p[0]+m[0], p[1]+m[1]])

if d[h-1][w-1] ==inf:
    print(-1)
else:
    print(white-d[h-1][w-1]-1)