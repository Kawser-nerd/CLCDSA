n,m=map(int,input().split())
e=[]
for _ in range(m):
    a,b,c=map(int,input().split())
    e.append([a-1,b-1,-c])
M=10**18
d=[0]+[M]*~-n
k=0
v=0
while k<n*2:
    k+=1
    if k==n:v=d[-1]
    f=0
    for a,b,c in e:
        if d[b]>d[a]+c:
            d[b]=d[a]+c
            f=1
    if not f:
        break
if not v or v==d[-1]:
    print(-d[-1])
else:
    print('inf')