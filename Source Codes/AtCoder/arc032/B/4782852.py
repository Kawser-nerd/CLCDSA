N,M=map(int,input().split())

L=[i for i in range(N+1)]
size=[1 for i in range(N+1)]

def find(n):
    if n==L[n]:
        return n
    else:
        return find(L[n])
        
def union(x,y):
    if size[find(x)]>size[find(y)]:
        L[y]=L[x]
        size[find(x)]+=size[find(y)]
    elif  size[find(y)]>size[find(x)]:
        L[x]=L[y]
        size[find(y)]+=size[find(x)]
    elif size[find(x)]==size[find(y)]:
        L[y]=L[x]
        size[find(x)]+=1

for i in range(M):
    a,b=map(int,input().split())
    if find(a)==find(b):
        pass
    else:
        union(find(a),find(b))
        
ans=[]

for i in range(1,len(L)):
    ans.append(find(i))
ans=set(ans)
print(len(ans)-1)