A = input()
B = input()

if A[0] == B[-1] and A[1] == B[1] and A[-1] == B[0]:
  print("YES")
else:
  print("NO")