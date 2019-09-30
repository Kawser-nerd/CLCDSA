import itertools
n=int(input())
s='S'+input()
rr=list(itertools.product(['A', 'B', 'X', 'Y'], repeat=2))
ll=list(itertools.product(['A', 'B', 'X', 'Y'], repeat=2))
def count(l, r):
    k=[0]*(n+1)
    for i in range(1, n+1):
        if (s[i-1]==l[0] and s[i]==l[1]) or (s[i-1]==r[0] and s[i]==r[1]):
            k[i]=min(k[i-1]+1, k[i-2]+1)
        else:
            k[i]=k[i-1]+1
    return k[n]
ans=10**10
for ri in rr:
    for li in ll:
        ans = min(ans, count(li, ri)) 
print(ans)