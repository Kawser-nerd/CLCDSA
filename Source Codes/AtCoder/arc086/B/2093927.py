N=int(input())
A=[int(x) for x in input().split()]

mi=100000000
ma=-100000000
mi_n=0
ma_n=0
for i in range(N):
  if A[i]>ma:
    ma=A[i]
    ma_n=i+1
  if A[i]<mi:
    mi=A[i]
    mi_n=i+1

if mi>=0:
  print(N-1)
  for i in range(N-1):
    print(i+1,i+2)
elif ma<=0:
  print(N-1)
  for i in range(N-1):
    print(N-i,N-i-1)
else:
  print(N+N-1)
  if abs(ma)>abs(mi):
    for i in range(N):
      print(ma_n,i+1)
    for j in range(N-1):
      print(j+1,j+2)
  else:
    for i in range(N):
      print(mi_n,i+1)
    for j in range(N-1):
      print(N-j,N-j-1)