n=int(input())
A=list(int(input()) for i in range(n))
B=sorted(list(set(A)))
C={}
for i in range(len(B)):
  C[B[i]]=i
for i in range(len(A)):
  print(C[A[i]])