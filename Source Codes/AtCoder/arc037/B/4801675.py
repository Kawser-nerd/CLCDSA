N,M=map(int,input().split())

P=[i for i in range(N+1)]
size=[1 for i in range(N+1)]

def find(x):
    if P[x]==x:
        return x
    else:
        return find(P[x])
        
def union(a,b):
    a=find(a)
    b=find(b)
    if size[a]>size[b]:
        size[a]+=size[b]
        P[b]=P[a]
    elif size[b]>size[a]:
        size[b]+=size[a]
        P[a]=P[b]
    elif size[a]==size[b]:
        size[a]+=size[b]
        P[b]=P[a]
        
L=[]
for i in range(M):
    u,v=map(int,input().split())
    L.append(u)
    if find(u)==find(v):
        pass
    else:
        union(u,v)
        
NO=[0 for i in range(N+1)]

for i in range(len(L)):
    NO[P[find(L[i])]]+=1
    
#print(P)
#print(size)
#print(NO)
ans=0
for i in range(len(P)):
    if i==P[i] and size[i]-NO[i]==1:
        ans+=1
print(ans-1)