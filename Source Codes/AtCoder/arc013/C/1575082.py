N = int(input())
nim = 0
for i in range(N):
    x,y,z = map(int,input().split())
    xmin,ymin,zmin = x,y,z
    xmax = ymax = zmax = 0
    m = int(input())
    for j in range(m):
        xj,yj,zj = map(int,input().split())
        xmin = min(xj,xmin)
        ymin = min(yj,ymin)
        zmin = min(zj,zmin)
        xmax = max(xj,xmax)
        ymax = max(yj,ymax)
        zmax = max(zj,zmax)
    nim ^= xmin
    nim ^= ymin
    nim ^= zmin
    nim ^= (x - xmax - 1)
    nim ^= (y - ymax - 1)
    nim ^= (z - zmax - 1)
print('LOSE' if nim == 0 else 'WIN')