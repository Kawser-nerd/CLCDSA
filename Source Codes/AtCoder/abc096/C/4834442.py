H,W = map(int,input().split())
S = []

S.append(list('@'*(W+2)))
for i in range(H):
  s = list(input())
  s.insert(0,'@')
  s.append('@')
  S.append(s)
S.append(list('@'*(W+2)))

judge = 1 #1: ?,0:??
count = 0
vy = [0,0,1,-1]
vx = [1,-1,0,0]
for i in range(H+2):
  if(count == 4): break  
  if((i != 0)and(i != H+1)):    
   for j in range(W+2):
    if(count == 4): break  
    if((j != 0)and(j != W+1)):
      if(S[i][j] == '#'):
        count = 0
        for k in range(4):
          if(S[i+vy[k]][j+vx[k]] == '#'): break
          count += 1
        if(count == 4):
          judge = 0
          break

if(judge == 1):
  print('Yes')
else:
  print('No')