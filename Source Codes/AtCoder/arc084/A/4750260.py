from bisect import*
from numpy import*
n=int(input())
a=sorted(map(int,input().split()))
b=sorted(map(int,input().split()))
c=sorted(map(int,input().split()))
#print(a,b,c)
#print([bisect_right(b,t)for t in a])
#print(cumsum([n-bisect_right(c,s)for s in b][::-1])[::-1])
ans=0
x=cumsum([n-bisect_right(c,s)for s in b][::-1])[::-1]
y=[bisect_right(b,t)for t in a]
for i in y:
    if i<n:
        ans+=x[i]
print(ans)