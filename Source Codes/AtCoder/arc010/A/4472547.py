def ans():
  N, M, A, B = map(int,input().split())
  for i in range(M):
    c = int(input())
    if(N <= A):
      N += B
    N -= c
    if(N < 0):
      print(i+1)
      break
  else:
    print("complete")
ans()