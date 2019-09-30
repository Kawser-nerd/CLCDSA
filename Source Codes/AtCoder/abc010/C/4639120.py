sx,sy,gx,gy,t,v = map(int,input().split())
n = int(input())

for i in range(n):
    x,y = map(int,input().split())
    if ((x-sx)**2+(y-sy)**2)**0.5+((x-gx)**2+(y-gy)**2)**0.5 <= t*v:
        print("YES")
        exit()
print("NO")