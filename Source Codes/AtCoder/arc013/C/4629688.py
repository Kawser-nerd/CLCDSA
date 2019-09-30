import sys
input=sys.stdin.readline
n=int(input())
nim=0
for _ in range(n):
    x,y,z=map(int,input().split())
    m=int(input())
    min_x,min_y,min_z=float('inf'),float('inf'),float('inf')
    max_x,max_y,max_z=0,0,0
    for _ in range(m):
        hx,hy,hz=map(int,input().split())
        min_x,min_y,min_z=min(min_x,hx),min(min_y,hy),min(min_z,hz)
        max_x,max_y,max_z=max(max_x,hx),max(max_y,hy),max(max_z,hz)
    nim^=min_x^min_y^min_z^(x-max_x-1)^(y-max_y-1)^(z-max_z-1)
print('WIN' if nim else 'LOSE')