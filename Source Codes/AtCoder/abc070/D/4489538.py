from collections import*
input=open(0).readline
n=int(input())
e=[[]for _ in range(n)]
for _ in range(n-1):
    a,b,c=map(int,input().split())
    e[a-1].append((b-1,c))
    e[b-1].append((a-1,c))
q,k=map(int,input().split())
d=[0]*n
f=[0]*n
f[k-1]=1
s=deque([(k-1,0)])
while s:
    t,c=s.pop()
    f[t]=1
    d[t]=c
    for i,v in e[t]:
        if not f[i]:
            s.append((i,v+c))
for _ in range(q):
    x,y=map(int,input().split())
    print(d[x-1]+d[y-1])