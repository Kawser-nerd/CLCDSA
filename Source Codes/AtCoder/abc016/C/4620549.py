N,M = map(int,input().split())
Friend = []
ans = []


for i in range(N):
  a = [0]*N
  ans.append(0)
  Friend.append(a)

for i in range(M):
  a,b = map(int,input().split())
  Friend[a-1][b-1] += 1
  Friend[b-1][a-1] += 1
  
for i in range(N):
  research = []
  judge = [] #???????????????
  for j in range(N):
    judge.append(0)
    if(Friend[i][j] == 1):
      research.append(j)

  for p in range(len(research)):
   for q in range(N):
     if(q != i):
      if( (Friend[research[p]][q] == 1 )and(q not in research)and(judge[q] == 0)):
        judge[q] += 1
        ans[i] += 1
     
for i in range(N):
  print(ans[i])