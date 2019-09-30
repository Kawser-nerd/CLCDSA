N,M=[int(i) for i in input().split()]
bridge=[]
for i in range(M):
  bridge.append([int(i)-1 for i in input().split()])
nod=[[i,[i]] for i in range(N)]
e=0
totale=int(N*(N-1)/2)


def joint(a,b,e):
  na=nod[a][0]
  nb=nod[b][0]
  if na==nb:
    return e
  else:
    e+=len(nod[na][1])*len(nod[nb][1])
    if na<nb:
      nod[na][1].extend(nod[nb][1])
      for i in nod[nb][1]:
        nod[i][0]=na
    else:
      nod[nb][1].extend(nod[na][1])
      for i in nod[na][1]:
        nod[i][0]=nb
    return e
  


ans=[]
for i in range(M-1,-1,-1):
  ans.append(totale-e)
  e=joint(bridge[i][0],bridge[i][1],e)
  
for i in range(M-1,-1,-1):
  print(ans[i])