n,m = map(int,input().split())
par , rank = [],[] 

for i in range(n): 
    par.append(i)
    rank.append(0)

def find(x):
    if par[x] == x : return x
    else:
        par[x] = find(par[x])
        return par[x]

def unite(x,y): 
    x = find(x)
    y = find(y)
    if (x != y):
        if rank[x] < rank[y]:
            par[x] = y
        else :
            par[y] = x
            if (rank[x] == rank[y]) : rank[x] += 1

def same(x,y):
    return (find(x) == find(y)) 

    
p = list(map(int,input().split()))

for i in range(m):
    x,y = map(int,input().split())
    unite(x-1,y-1)

dic = {}

for i in range(n):
    i1 = find(i)
    if i1 in dic:
        dic[i1].append(i)
    else:
        dic[i1] = [i]
        

cnt = 0
for pp in list(dic):
    l = dic[pp]
    ll = []
    for i in l:
        ll.append(p[i]-1)
    for q in ll:
        if(par[q] == pp):cnt += 1
    
print(cnt)