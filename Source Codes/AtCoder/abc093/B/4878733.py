A,B,K=map(int,input().split())
L=[]
for i in range(K):
  if A+i<=B:
    L.append(A+i)
  else:
    break
for i in range(1-K,1):
  if B+i>=A and B+i not in L:
    L.append(B+i)
for i in range(len(L)):
  print(L[i])