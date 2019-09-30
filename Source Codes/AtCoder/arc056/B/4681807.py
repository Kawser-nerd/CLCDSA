import sys
input = sys.stdin.readline

n,m,s = map(int,input().split())
s -= 1
edge = [[] for i in range(n)]
for i in range(m):
    u,v = map(int,input().split())
    edge[u-1].append(v-1)
    edge[v-1].append(u-1)

#Union Find
par = [i for i in range(n)] #?
rank = [0]*n #????

#???????
def find(x,par):
    if par[x] == x:
        return x
    else:
        return find(par[x],par)

#x?y?????????
def unite(x,y):
    x = find(x,par)
    y = find(y,par)
    
    if x != y:
        #x?y?????????????
        if rank[x] < rank[y]:
            par[x] = y
        else:
            par[y] = x
            if rank[x]==rank[y]:
                rank[x] += 1

#x?y?????????????
def same(x,y,par):
    return find(x,par) == find(y,par)

res = []
for i in range(n-1,-1,-1):
    if i > s:
        for e in edge[i]:
            if e > i:
                unite(e,i)
        continue
    for e in edge[i]:
        if e > i:
            unite(e,i)
    if same(i,s,par):
        res.append(i)

for i in range(len(res)-1,-1,-1):
    print(res[i]+1)