N,A,B = map(int,input().split())
if N <= 5:
  print(N*B)
else:
  print(5*B+(N-5)*A)