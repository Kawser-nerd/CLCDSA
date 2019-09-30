N,K = map(int,input().split())
if N == 1:
  print(1)
elif N == 2:
  print(0.5)
else:
  if K == 1 or K == N:
    print((1+3*(N-1))/(N**3))
  else:
    print((6*(K-1)*(N-K)+3*(N-1)+1)/(N**3))