def ans():
  N = int(input())
  q = int(N**0.5)
  f = 1
  for i in range(2, q+1):
    if(N%i == 0):
      f = 0
      break
  if(f):
    print("YES")
  else:
    print("NO")
ans()