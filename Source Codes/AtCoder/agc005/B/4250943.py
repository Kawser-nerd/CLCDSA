#???????
def find(x):
    if par[x] == x:
        return x
    else:
        return find(par[x])

#x?y?????????
def unite(x,y):
    x = find(x)
    y = find(y)
    
    if x != y:
        #x?y?????????????
        if rank[x] < rank[y]:
            par[x] = y
            size[y] += size[x]
        else:
            par[y] = x
            size[x] += size[y]
            if rank[x]==rank[y]:
                rank[x] += 1

#x?y?????????????
def same(x,y):
    return find(x) == find(y)

########################################
n = int(input())
a = list(map(int,input().split()))

par = [0]*n #?
for i in range(n):
    par[i] = i
rank = [1]*n #??
size = [1]*n #size[i]:i?????????????

b = [0]*(n+1) #b[i]:i?a????????
for i in range(n):
    b[a[i]]=i

ans = 0
for i in range(n,0,-1):
    k = b[i]
    left = 0
    right = 0
    if k-1>=0 and a[k-1]>a[k]:
        left =  size[find(k-1)]
        unite(k-1,k)
    if k+1<=n-1 and a[k+1]>a[k]:
        right = size[find(k+1)]
        unite(k+1,k)
    ans += (left+1)*(right+1)*a[k]

print(ans)