import sys
input = sys.stdin.readline

n,m = map(int,input().split())

#Union Find
par = [] #?
rank = [] #????

#???
for i in range(n):
    #par[i]:i rank[i]:0
    par.append(i)
    rank.append(0)

#???????
def find(x,par):
    if par[x] == x:
        return x
    else:
        return find(par[x],par)

#x?y?????????
def unite(x,y,par,rank):
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

for i in range(m):
    a,b = map(lambda x:int(x)-1,input().split())
    unite(a,b,par,rank)

res = -1
for i in range(n):
    if par[i] == i:
        res += 1
print(res)