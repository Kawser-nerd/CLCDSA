from math import factorial
n,m,d=map(int,input().split())

amd={i:i for i in range(1,n+1)}
for i in map(int,input().split()):
  amd[i],amd[i+1]=amd[i+1],amd[i]

cv={j:i for i,j in amd.items()}
ans={i:i for i in range(1,n+1)}

while d:
  if d%2:
    ans={i:cv[ans[i]] for i in range(1,n+1)}
  cv={i:cv[cv[i]] for i in range(1,n+1)}
  d>>=1

print(*ans.values(),sep="\n")