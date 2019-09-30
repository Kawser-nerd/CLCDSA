import queue
h,w = map(int,input().split())
s = [list(input()) for i in range(h)]
q = queue.Queue()
ma = [[0]*w for i in range(h)]
dyx = [[0,1],[0,-1],[1,0],[-1,0]]
white = 0
black = 0
for i in range(h):
    white += s[i].count(".")
black = h*w - white
q.put([0,0])
s[0][0] = "#"
flag = True
while flag:
    newq = queue.Queue()
    while not q.empty():
        y,x = q.get()
        for dy,dx in dyx:
            if 0 <= y + dy< h and 0 <= x +dx <w and s[y+dy][x+dx] != "#":
                s[y+dy][x+dx] = "#"
                newq.put([y+dy,x+dx])
                ma[y+dy][x+dx] = ma[y][x] +1
            if y+dy == h-1 and x+dx == w-1:
                flag = False
    q = newq
    if q.empty():
        break
if ma[h-1][w-1] == 0:
    print(-1)
else:print(white - ma[h-1][w-1]-1)