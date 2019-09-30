m=[input()for i in range(4)]
for i in range(3,-1,-1):
  ans=""
  for j in range(6,-1,-1):
    ans+=m[i][j]
  print(ans)