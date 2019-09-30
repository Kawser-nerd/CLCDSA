n=int(input())
d=[list(map(int, input().split())) for _ in range(n)]
q=int(input())
p=[int(input()) for _ in range(q)]
value=[[0]*n for _ in range(n)]
for i in range(n):
    for j in range(n):
        if j>0:
            value[j][i]=value[j-1][i]+sum(d[j][:i+1])
        else:
            value[j][i]=sum(d[j][:i+1])
def calc(x0, y0, x1, y1):
    if x0==-1:
       if y0==-1:
           return value[x1][y1]
       else:
           return value[x1][y1]-value[x1][y0]
    else:
        if y0==-1:
            return value[x1][y1]-value[x0][y1]
        else:
            return value[x1][y1]-value[x1][y0]-value[x0][y1]+value[x0][y0]
ans=[0]*(n**2+1)
for x1 in range(n):
    for y1 in range(n):
        for x0 in range(-1, x1):
            for y0 in range(-1, y1):
                ans[(x1-x0)*(y1-y0)]=max(ans[(x1-x0)*(y1-y0)], calc(x0, y0, x1, y1))
m=0
for i in range(n**2+1):
    if m<ans[i]:
        m=ans[i]
    else:
        ans[i]=m
for pi in p:
  print(ans[pi])