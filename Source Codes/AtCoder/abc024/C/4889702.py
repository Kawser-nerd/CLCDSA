n,d,k=map(int,input().split())
move=[]
for i in range(d):
  x=list(map(int,input().split()))
  move.append(x)
for i in range(k):
  s,t=map(int,input().split())
  start=s
  end=s
  if s<t:
    for j in range(len(move)):
      if move[j][0]<=start:
        end=max(end,move[j][1])
        start=end
      if end>=t:
        print(j+1)
        break
  else:
    for j in range(len(move)):
      if move[j][1]>=start:
        end=min(end,move[j][0])
        start=end
      if end<=t:
        print(j+1)
        break