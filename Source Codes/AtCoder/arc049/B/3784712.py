iipt=lambda:int(input())
miipt=lambda:list(map(int,input().split(" ")))

n=iipt()
x=[0]*1123
y=[0]*1123
c=[0]*1123
for i in range(n):
    x[i],y[i],c[i]=miipt()
tx=ty=0
p=0
q=212345678
for _ in range(64):
    r=(p+q)/2
    x1=-112345
    x2=112345
    y1=-112345
    y2=112345
    for i in range(n):
        x1=max(x1, x[i]-r/c[i])
        x2=min(x2, x[i]+r/c[i])
        y1=max(y1, y[i]-r/c[i])
        y2=min(y2, y[i]+r/c[i])
    if x1<x2 and y1<y2:
        q=r
    else:
        p=r
print(r)