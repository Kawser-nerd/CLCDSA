import sys
input = sys.stdin.readline

n,m = map(int,input().split())

#Union Find
par = [] #?
rank = [0]*n #????
judge = [True]*n

#???
for i in range(n):
    #par[i]:i rank[i]:0
    par.append(i)

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
    if x == y:
        judge[x] = False
    if x != y:
        #x?y?????????????
        if rank[x] < rank[y]:
            if not judge[x]:
                judge[y] = False
            par[x] = y
            judge[x] = False
        else:
            if not judge[y]:
                judge[x] = False
            par[y] = x
            judge[y] = False 
            if rank[x]==rank[y]:
                rank[x] += 1

#x?y?????????????
def same(x,y,par):
    return find(x,par) == find(y,par)

#x?y?????????????
def same(x,y,par):
    return find(x,par) == find(y,par)

for i in range(m):
    u,v = map(int,input().split())
    u,v = u-1,v-1
    unite(u,v,par,rank)
res = 0
for e in judge:
    if e:
        res += 1
print(res)