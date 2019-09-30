from collections import deque
n=int(input())
l=[0]*n
d={}
for i in range(n-1):
    a,b,c=map(int,input().split())
    a-=1
    b-=1
    if a in d:
        d[a].add((b,c))
    else:
        d[a]={(b,c)}
    if b in d:
        d[b].add((a,c))
    else:
        d[b]={(a,c)}
q,k=map(int,input().split())
k-=1
p=deque([k])
while len(p):
    w=p.popleft()
    for i in d[w]:
        if (l[i[0]]==0 and i[0]!=k) or (l[i[0]]!=0 and l[i[0]]>l[w]+i[1]):
            l[i[0]]=l[w]+i[1]
            p.append(i[0])

for i in range(q):
    x,y=map(int,input().split())
    print(l[x-1]+l[y-1])