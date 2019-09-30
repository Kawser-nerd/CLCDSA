#AGC030 B - Powers of two
import collections
import math
N=int(input())
A=list(map(int,input().split()))
A.sort(reverse=True)
cnter=collections.Counter(A)
ans=0
for a in A:
    inv=2**(int(math.log2(a))+1)
    if cnter[a]==0:
        continue
    if inv==2*a and cnter[inv-a]<=1:
      	continue
    if cnter[inv-a]>0:
        cnter[inv-a]=cnter[inv-a]-1
        cnter[a]=cnter[a]-1
        ans=ans+1
print(ans)