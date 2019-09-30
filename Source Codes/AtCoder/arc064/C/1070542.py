from heapq import *
from math import sqrt

def finddist(a,b):
    x1,y1,r1=a
    x2,y2,r2=b
    dx = x1 - x2
    dy = y1 - y2
    d = sqrt(dx*dx + dy*dy)
    return max(0, d - r1 -r2)


def dijkstra(c,s,t):
    found = set([(s,0)])
    dist ={s:0}
    notfound=set(c[1:])
    edgesinheap=[]
    newvert = s
    while notfound:
        if newvert == t:
            return dist[t]

        for x in notfound:
            heappush(edgesinheap, (dist[newvert]+finddist(newvert ,x), x, newvert))

        nextvertexfound = False
        while not nextvertexfound:
            d,nextvert, priv = heappop(edgesinheap)
            if nextvert not in found:
                nextvertexfound = True
                dist[nextvert] = d
                found.add(nextvert)
                notfound.remove(nextvert)
                newvert = nextvert

    return dist[t]





if __name__=="__main__":
    xs,ys,xt,yt=list(map(int,input().split()))
    N = int(input())
    circles = [(xs,ys,0), (xt,yt,0)]
    for _  in range(N):
        c=tuple(map(int, input().split()))
        circles.append(c)

    edges = []

    print(dijkstra(circles,circles[0],circles[1]))