N,M=map(int,input().split())
TOT=[0]*M
for i in range(N):
  List=[int(i) for i in input().split()]
  List.pop(0)
  List_N=[]
  for j in range (M):    
    if j+1 in List:
      List_N.append(1)
    else:
      List_N.append(0)
  TOTAL=[]
  for k in range(M):
    TOTAL.append(TOT[k]+List_N[k])
  TOT=TOTAL
print(TOT.count(N))