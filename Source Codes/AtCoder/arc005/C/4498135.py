from  collections import deque
H,W=map(int,input().split())
c=[]
for i in range(H):
    ci=input()
    c.append(ci)
reached=[["A" for i in range(W)] for j in range(H)]
queue=deque()

for j in range(H):
    for i in range(W):
        if c[j][i]=="s":
            sy=j
            sx=i
        elif c[j][i]=="g":
            gy=j
            gx=i

queue.append([sy,sx])
reached[sy][sx]=0
dx=[1,-1,0,0]
dy=[0,0,1,-1]
while(queue):
    p=queue.pop()
    for i in range(4):
        y=p[0]+dy[i]
        x=p[1]+dx[i]
        if y==gy and x==gx:
            reached[y][x]=reached[p[0]][p[1]]
            queue=[]
            break
        if x<0 or x>=W or y<0 or y>=H:
            continue
        if not(reached[y][x]=="A"):
            continue
            
        if c[y][x]=="#":
            if reached[p[0]][p[1]]==2:
                continue
            queue.appendleft([y,x])
            reached[y][x]=reached[p[0]][p[1]]+1
        else:
            queue.append([y,x])
            reached[y][x]=reached[p[0]][p[1]]


if reached[gy][gx]=="A":
    print("NO")
else:
    print("YES")