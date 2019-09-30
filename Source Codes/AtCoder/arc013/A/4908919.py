from itertools import*
f,g,h,*a,=map(int,open(0).read().split())
ans=1
l=[]
for s,t,r in (permutations(a)):
    ans*=(f//s)*(g//t)*(h//r)
    l.append(ans)
    ans=1
print(max(l))