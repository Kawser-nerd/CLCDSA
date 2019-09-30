import numpy as np

minDis = np.zeros((10,10),dtype = int)
minDis.fill(10**18)

edge = np.zeros((10,10),dtype = int)
for i in range(10):
    minDis[i][i] = 0

h,w = map(int,input().split())
mat = np.zeros((h,w),dtype = int)
for i in range(10):
    edge[i] = list(map(int,input().split()))
for i in range(h):
    mat[i] = list(map(int,input().split()))

for start in range(10):
    #shortest path
    dis = [10**18] *10
    points = set(range(10))
    dis[start] = 0
    
    while points:
        #find point with min dis
        md = 10**18+1
        idx = start
        for point in points:
            if dis[point] <md:
                md = dis[point]
                idx = point
        points.remove(idx)
        for neighbour in range(10):
            if neighbour == idx:
                continue
            dis[neighbour] = min(dis[neighbour],dis[idx]+edge[idx][neighbour])
    minDis[start] = dis
#print(minDis) 
res = 0
for i in range(h):
    for j in range(w):
        if mat[i][j] == -1:
            continue
        res += minDis[mat[i][j]][1]
print(res)