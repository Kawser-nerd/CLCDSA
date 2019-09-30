N = int(input())

A = []
B = []

for i in range(N):
  Data = list(map(int, input().split()))
  A.append(Data[0])
  B.append(Data[1])
  
ma = 10e10
for i in range(N):
  if A[i] > B[i]:
    if B[i] < ma:
      ma = B[i]

if ma == 10e10:
  print(0)
else:
  print(sum(A) - ma)