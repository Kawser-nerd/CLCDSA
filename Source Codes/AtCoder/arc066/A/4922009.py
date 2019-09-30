import collections
mod=10**9+7
p=int(input())
a=[int(i) for i in input().split()]
diff=collections.Counter(a)
def modpower(n):
    ret=1
    for k in range(n):
        ret=(2*ret)%mod
    return(ret)
if p==1:#one
    ans=1-bool(a[0])
elif p%2:#odd
    if all([diff[i]==2 for i in range(2,p,2)]) and diff[0]==1:
        ans=modpower(p//2)
    else:ans=0
else:#even
    if all([diff[i]==2 for i in range(1,p+1,2)]):
        ans=modpower(p//2)
    else:ans=0
print(ans)