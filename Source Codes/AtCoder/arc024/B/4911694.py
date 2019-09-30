n=int(input())
d=[int(input())for i in range(n)]
d=2*d
e=0
f=d[0]
g=0
for i in range(2*n):
    if f==d[i]:
        g+=1
    else:
        e=max(g,e)
        g=1
        f=d[i]
e=max(g,e)
if e==2*n:
    print(-1)
else:
    print((e-1)//2+1)