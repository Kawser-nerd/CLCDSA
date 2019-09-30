A = [int(i) for i in input().split(' ')]
if 2*A[2] < A[0] + A[1]:
  m = min(A[3], A[4])
  print(A[2] * m * 2 + (A[3] - m)*min(A[0],2*A[2]) + (A[4] - m)*min(A[1],2*A[2]) )
else:
  print(A[3] * A[0] + A[4] * A[1])