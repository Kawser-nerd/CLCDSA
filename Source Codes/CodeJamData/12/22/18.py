from collections import deque

def valid(tup,X,Y):
    (x,y)=tup
    return (x>=0) and (y>=0) and (x<X) and (y<Y)

def run():
    f=open("input.in")
    g=open("out.txt",'w')
    num = int(f.readline())
    for i in range(num):
        g.write("Case #%d: " % (i+1))
        [H,N,M] = map(int,f.readline().split())
        ceils = [map(int,f.readline().split()) for x in range(N)]
        floors = [map(int,f.readline().split()) for x in range(N)]
        times = [[-1.0 for x in range(M)]for y in range(N)]
        visited = [[False for x in range(M)] for y in range(N)]
        times[0][0]=0.0
        tocheck = [(0,0)]
        while True:
            if not tocheck:
                break
            lowCell = tocheck[0]
            lowTime = times[lowCell[0]][lowCell[1]]
            for c in tocheck:
                t = times[c[0]][c[1]]
                if t<lowTime:
                    lowCell = c
                    lowTime = t
            tocheck.remove(lowCell)
            (x,y)=lowCell
            currTime = lowTime
            if visited[x][y]:
                continue
            visited[x][y]=True
            check = [(0,0) for j in range(4)]
            check[0]= (x,y-1)
            check[1] = (x,y+1)
            check[2] =(x-1,y)
            check[3] = (x+1,y)
            for cell in check:
                (u,v) = cell
                if valid(cell,N,M):
                    if not visited[u][v]:
                        if (ceils[u][v]-floors[x][y]>=50) and (ceils[u][v]-floors[u][v]>=50) and (ceils[x][y]-floors[u][v]>=50):
                            airGap = ceils[u][v]-H+currTime*10.0
                            wait = max((50.0-airGap)/10.0,0)
                            level = H-(currTime+wait)*10.0
                            high = (level-floors[x][y]>=20)
                            if wait == 0 and currTime == 0:
                                prosp = 0.0
                            elif high:
                                prosp = currTime+wait+1.0
                            else:
                                prosp = currTime+wait+10.0
                            got = times[u][v]
                            if got<0 or prosp<got:
                                times[u][v]=prosp
                            tocheck.append(cell)
        g.write("%f\n" % times[N-1][M-1])
        continue
    f.close()
    g.close()
    
