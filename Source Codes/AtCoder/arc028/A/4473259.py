def ans():
  N, A, B = map(int,input().split())
  while True:
    N -= A
    if(N <= 0):
      print("Ant")
      break
    N -= B
    if(N <= 0):
      print("Bug")
      break
ans()