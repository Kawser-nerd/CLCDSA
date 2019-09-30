n = int(input())

x = [0]*n
y = [0]*n
for i in range(n):
    a,b = map(int,input().split())
    x[i] = a+b
    y[i] = a-b
    
xmax = max(x)
xmin = min(x)
ymax = max(y)
ymin = min(y)

#????
d = max(xmax-xmin,ymax-ymin)


p = [[xmax-d//2,ymax-d//2],
    [xmax-d//2,ymin+d//2],
    [xmin+d//2,ymax-d//2],
    [xmin+d//2,ymin+d//2]]

#??:c=0:ok, c=1;ng
for e in p:
    c = 0
    for i in range(n):
        if c == 0:
            dx = abs(x[i]-e[0])
            dy = abs(y[i]-e[1])
            if max(dx,dy)!=d//2:
                c = 1
    if c == 0:
        print((e[0]+e[1])//2,(e[0]-e[1])//2)
        exit()