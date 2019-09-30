def ans():
  N = int(input())
  num = sum(range(1,N+1))
  f = True
  if(num <= 1):
    f = False
  i = 2
  while i*i <= num:
    if(num%i == 0):
      f = False
    i += 1
  if(not f):
    print("BOWWOW")
  else:
    print("WANWAN")
ans()