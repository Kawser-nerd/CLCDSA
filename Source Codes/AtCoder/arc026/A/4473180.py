def ans():
  N, A, B = map(int,input().split())
  if(N <= 5):
    print(N*B)
  else:
    print((N-5)*A + B*5)
ans()