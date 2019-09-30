N,C=map(int,input().split())
from collections import defaultdict
cannel={i:[] for i in range(1,1+C)}
check=[tuple(map(int,input().split())) for i in range(N)]
check.sort(key=lambda x:x[0])
for x in check:
    s,t,c=x
    if cannel[c]==[]:
        cannel[c].append((max(0,s-1),t))
    elif s-cannel[c][-1][1]<=1:
        cannel[c][-1]=(cannel[c][-1][0],t)
    else:
        cannel[c].append((max(0,s-1),t))
start=defaultdict(int)
end=defaultdict(int)
for c in range(1,1+C):
    for x in cannel[c]:
        start[x[0]]+=1
        end[x[1]]+=1
ans=0
now=0
for i in range(10**5+1):
    now+=start[i]-end[i]
    ans=max(ans,now)
print(ans)