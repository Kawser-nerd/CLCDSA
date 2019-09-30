N,K=map(int,input().split(' '))
D=list(map(str,input().split(' ')))
ans=N
while True:
  judge=True
  m=len(str(ans))
  for i in range(m):
    if str(ans)[i] in D:
      judge=False
      break
    else:
      continue
  if judge==False:
    ans+=1
    continue
  else:
    break
print(ans)