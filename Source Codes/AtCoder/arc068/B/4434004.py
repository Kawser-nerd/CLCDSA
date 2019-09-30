N=int(input())
A=list(map(int,input().split()))
from collections import Counter
counter=Counter(A)

odd=0
eve =0

for k  in counter.keys():
  if counter[k]%2==0:
    eve+=1
  else:
    odd+=1
ans=0
if eve%2==0:
  ans=eve+odd
else:
  ans=eve+odd-1
print(ans)