A=[int(input()) for i in range(3)]
M=max(A)
m=min(A)
for i in range(3):
  print(1 if A[i]==M else 3 if A[i]==m else 2)