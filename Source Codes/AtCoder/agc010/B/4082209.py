N = int(input())
A = [int(i) for i in input().split()]

P = "possible"

Nsum = N *(N+1)//2
if sum(A) % Nsum == 0:
  K = sum(A) // Nsum
  for i in range(N):
    A[i] -= K * (i + 1)
  A0 = A[0]
  for i in range(N):
    A[i] -= A0
  B = [0] * N
  for i in range(1, N):
    if (A[i] - A[i-1])%N != 0:
      P = "impossible"
    else:
      B[i] = (A[i-1] - A[i]) // N
  B[0] = K - sum(B)
  for i in range(N):
    if B[i] < 0:
      P = "impossible"
  for i in range(1, N):
    A0 -= B[i] * (N-i)
  if A0 != 0:
    P = "impossible"
else:
  P = "impossible"
  
if P == "impossible":
  print("NO")
else:
  print("YES")