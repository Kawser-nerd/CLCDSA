n,A,B,C=map(int,input().split())
l=[int(input()) for _ in range(n)]
t=10**9
def dfs(level,a,b,c):
  if level==n:
    return abs(a-A)+abs(b-B)+abs(c-C)-30 if min(a,b,c)>0 else t
  k1=dfs(level+1,a,b,c)
  k2=dfs(level+1,a+l[level],b,c)+10
  k3=dfs(level+1,a,b+l[level],c)+10
  k4=dfs(level+1,a,b,c+l[level])+10
  return min(k1,k2,k3,k4)
print(dfs(0,0,0,0))