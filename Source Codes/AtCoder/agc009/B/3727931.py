import sys
sys.setrecursionlimit(2000000)
n = int(input())
a=[[]for i in range(n)]
for i in range(n-1):
  x = int(input())
  x-=1
  a[x].append(i+1)
  
dp=[0]*n
ya = [[0,i] for i in range(n)]
def dfs(x,y):
  ya[x][0]=y
  for i in a[x]:
    dfs(i,y+1)
dfs(0,0)
ya.sort(key=lambda x:-x[0])
tmp=[]
for i in range(n):
  bb=ya[i][1]
  for j in a[bb]:
    tmp.append(dp[j])
  tmp.sort(key=lambda x:-x)
  dai =0
  for j in range(len(tmp),0,-1):
    cc=tmp.pop()
    cc+=j
    dai=max(dai,cc)
  dp[bb]=dai
print(dp[0])