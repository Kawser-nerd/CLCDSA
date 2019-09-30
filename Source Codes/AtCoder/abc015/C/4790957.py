n,k=map(int,input().split())
tAll=[]
for i in range(n):
  tmp=list(map(int,input().split()))
  tAll.append(tmp)


for i in range(5-n):
  tAll.append([0]*k)

ans="Nothing"
for a in range(k):
  for b in range(k):
    for c in range(k):
      for d in range(k):
        for e in range(k):
          if tAll[0][a]^tAll[1][b]^tAll[2][c]^tAll[3][d]^tAll[4][e]==0:
            ans="Found"
print(ans)