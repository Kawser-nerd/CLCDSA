from heapq import (heappop,heappush)

T=int(input())
for j in range(T):
    H,N,M = [int(x) for x in input().split()]
    fh = []
    ch = []
    dirs = [(1,0),(-1,0),(0,1),(0,-1)]
    for i in range(N):
        ch.append([int(x) for x in input().split()])
    for i in range(N):
        fh.append([int(x) for x in input().split()])
    heap = [(0.0,(0,0))]
    done = [[0]*M for i in range(N)]
    while heap:
#        print(heap)
        (t,(x,y)) = heappop(heap)
        if (x,y) == (N-1,M-1):
            ans = t
            break
        if done[x][y]:
            continue
        done[x][y] = 1
        for (dx,dy) in dirs:
                nx,ny = x+dx,y+dy
                if not((0<=nx<N) and (0<=ny<M)):
                    continue
                ceil = ch[nx][ny]
                flor = fh[nx][ny]
                if ((ceil<flor+50) or (ch[x][y]<flor+50) or (ceil<fh[x][y]+50)) :
                    continue
                st = max(t,(H-ceil+50)/10)
                dt = st-t
                if st:
                    if H-10*st>=fh[x][y]+20:
                        dt+= 1
                    else:
                        dt+= 10
                heappush(heap,(t+dt,(nx,ny)))
                
    print('Case #',j+1,': ',ans,sep = '')
