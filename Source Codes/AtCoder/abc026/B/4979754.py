import math
n=int(input())
r=[int(input()) for i in range(n)]
r.sort(reverse=True)
S=0
for i in range(n):
  if i%2==0:
    S+=r[i]**2
  else:
    S-=r[i]**2
print(S*math.pi)