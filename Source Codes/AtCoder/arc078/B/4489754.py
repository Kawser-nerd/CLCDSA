from collections import*
input=open(0).readline
n=int(input())
e=[[]for _ in range(n)]
for _ in range(n-1):
    a,b=map(int,input().split())
    e[a-1].append(b-1)
    e[b-1].append(a-1)
f=[0]*n
v=[1]+[0]*~-n
q=deque([(0,0)])
while q:
    t,c=q.pop()
    v[t]=1
    f[t]=c
    for i in e[t]:
        if not v[i]:
            q.append((i,c+1))
s=[0]*n
v=[0]*~-n+[1]
q=deque([(n-1,0)])
while q:
    t,c=q.pop()
    v[t]=1
    s[t]=c
    for i in e[t]:
        if not v[i]:
            q.append((i,c+1))
a=b=0
for i,j in zip(f,s):
    if i<=j:
        a+=1
    else:
        b+=1
if a>b:
    print('Fennec')
else:
    print('Snuke')