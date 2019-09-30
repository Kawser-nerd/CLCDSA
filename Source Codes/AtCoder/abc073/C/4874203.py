n=int(input())
ans=0
l=[int(input()) for i in range(n)]
from collections import Counter
lst=list(Counter(l).values())
def mod2(n):
  if n%2==1:
    return 1
  else:
    return 0
ans=0
for i in lst:
  ans+=mod2(i)
print(ans)