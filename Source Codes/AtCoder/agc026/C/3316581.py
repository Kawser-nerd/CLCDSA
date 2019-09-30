import itertools as I
from collections import Counter as C
n=int(input());s=input();l=s[:n];r=s[n:][::-1];a=C();b=C()
for i in I.product([0,1],repeat=n):
 t=u=v=w=''
 for j in range(n):
  if i[j]:t+=l[j];u+=r[j]
  else:v+=l[j];w+=r[j]
 a[t,v]+=1
 b[u,w]+=1
print(sum(a[i]*b[i]for i in a.keys()))