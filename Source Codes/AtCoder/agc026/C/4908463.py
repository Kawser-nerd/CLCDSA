import itertools as it
from collections import Counter as c
n=int(input())
a=c()
b=c()
s=input()
q=s[:n]
r=s[n:][::-1]
for i in it.product([0,1],repeat=n):
    d,e,f,g="","","",""
    for j in range(n):
        if i[j]==1:
            d+=q[j]
            f+=r[j]
        else:
            e+=q[j]
            g+=r[j]
    a[d,e]+=1
    b[f,g]+=1
print(sum(a[i]*b[i] for i in a.keys()))