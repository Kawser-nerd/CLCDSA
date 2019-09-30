N,M=map(int,input().split())
big=10**13
data=[-1*float('inf')]*(N+1)
from collections import defaultdict
branch=defaultdict(set)
for i in range(M):
    a,b,c=map(int,input().split())
    branch[a]|={(b,c),}
from collections import deque
check=deque()
check.append((1,0,set()))
data[1]=0
while len(check)>0:
    now=check.popleft()
    for b,c in branch[now[0]]:
        if now[1]+c>data[b]:
            if data[b]>big:continue
            if b in now[2]:
                data[b]=float('inf')
                check.append((now[0],float('inf'),now[2]|{now[0],b}))
                check.append((b,float('inf'),now[2]|{now[0],b}))
            else:
                data[b]=now[1]+c
                check.append((b,now[1]+c,now[2]|{now[0],}))
if data[N]>big:print('inf')
else:print(data[N])