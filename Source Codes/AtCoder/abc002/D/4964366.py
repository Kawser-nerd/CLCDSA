n,m=map(int,input().split())
e=[[i==j for j in range(n)]for i in range(n)]
for _ in range(m):
    x,y=map(int,input().split())
    e[x-1][y-1]=1
    e[y-1][x-1]=1
a=0
for i in range(1<<n):
    t=0
    for j in range(n):
        if i>>j&1:
            for k in range(n):
                if i>>k&1:
                    if not e[j][k]:
                        break
            else:
                t+=1
                continue
            break
    else:
        a=max(a,t)
print(a)