def solve():
    from collections import deque
    def outRange(h,w,y,x):
        return y<0 or x<0 or y>=h or x>=w
    h,w=map(int,input().split())
    maze=[[3*(i=='g')or 2*(i=='#')or i=='.'for i in input()]for _ in range(h)]
    d=((1,0),(-1,0),(0,1),(0,-1))
    for i in range(h):
        for j in range(w):
            if maze[i][j]==0:
                sy,sx=i,j
            if maze[i][j]==3:
                gy,gx=i,j
    visited0=[[False]*w for i in range(h)]
    visited1=[[False]*w for i in range(h)]
    visited2=[[False]*w for i in range(h)]
    queue=deque([[sy,sx,0]])
    visited0[sy][sx]=0
    while queue:
        y,x,i=queue.pop()
        if y==gy and x==gx:
            print('YES')
            break
        if i==0:
            for j,k in d:
                new_y,new_x=y+j,x+k
                if outRange(h,w,new_y,new_x):continue
                if maze[new_y][new_x]!=2and not visited0[new_y][new_x]:
                    visited0[new_y][new_x]=True
                    queue.append([new_y,new_x,i])
                elif not visited0[new_y][new_x]and not visited1[new_y][new_x]:
                    visited1[new_y][new_x]=True
                    queue.append([new_y,new_x,i+1])
        elif i==1:
            for j,k in d:
                new_y,new_x=y+j,x+k
                if outRange(h,w,new_y,new_x):continue
                if maze[new_y][new_x]!=2and not visited1[new_y][new_x]:
                    visited1[new_y][new_x]=True
                    queue.append([new_y,new_x,i])
                elif not visited0[new_y][new_x]and not visited1[new_y][new_x]and not visited2[new_y][new_x]:
                    visited2[new_y][new_x]=True
                    queue.append([new_y,new_x,i+1])
        else:
            for j,k in d:
                new_y,new_x=y+j,x+k
                if outRange(h,w,new_y,new_x):continue
                if maze[new_y][new_x]!=2and not visited2[new_y][new_x]:
                    visited2[new_y][new_x]=True
                    queue.append([new_y,new_x,i])
    else:print('NO')
if __name__=='__main__':
    solve()