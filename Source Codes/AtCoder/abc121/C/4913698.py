N,M=map(int,(input()).split())
List=[]
for i in range(1,N+1):
  AB=[int(j) for j in (input()).split()]
  List.append(AB)
List.sort()
S=0
P=0
k=0
while S<M:
  a=List[k][0]
  b=List[k][1]
  if S+b<=M:
    P=P+a*b
    S=S+b
  else:
    P=P+a*(M-S)
    S=M
  k=k+1
print(P)