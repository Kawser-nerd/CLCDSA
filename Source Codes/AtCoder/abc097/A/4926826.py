A = list(map(int, input().split()))
if (abs(A[0] - A[2]) <= A[3] or ((abs(A[0] - A[1]) <= A[3]) and (abs(A[2] - A[1]) <= A[3]))):
  print('Yes')
else:
  print('No')