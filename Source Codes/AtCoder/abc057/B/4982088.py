n, m = map(int, input().split())
A = []

for i in range(n):
  a,b = map(int, input().split())
  A.append([a,b])
  
C = []
for i in range(m):
  c,d = map(int, input().split())
  C.append([c,d])
  
ans = [0 for i in range(n)]
infinity = float("infinity")
for i in range(n):
  min_length = infinity
  for j  in range(m):
    if abs(A[i][0] - C[j][0]) + abs(A[i][1] - C[j][1]) < min_length:
      min_length = abs(A[i][0] - C[j][0]) + abs(A[i][1] - C[j][1])
      ans[i] = j+1
      
for i in range(len(ans)):
  print(ans[i])