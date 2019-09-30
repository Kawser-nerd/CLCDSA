N = int(input())
L = list(map(int,input().split()))
L.sort()
flag = True
if N % 2 == 0:
  for i in range(N//2):
    if L[i*2] == L[i*2+1] == 2*i+1:
      None
    else:
      flag = False
      break
else:
  if L[0] != 0:
    flag = False
  else:
    for i in range(1,N//2+1):
      if L[i*2-1] == L[i*2] == 2*i:
        None
      else:
        flag = False
        break
if flag:
  print(2**(N//2) % (7+10**9))
else:
  print(0)