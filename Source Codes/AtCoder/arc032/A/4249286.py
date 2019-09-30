import math
n = int(input())
k = n*(n+1)//2
flag = False
if n == 1:
  print('BOWWOW')
else:
  for i in range(2,math.ceil(math.sqrt(((n+1)**2)/2))):
    if k%i == 0:
      flag = True
      break
    else:
      None
  if flag:
    print('BOWWOW')
  else:
    print('WANWAN')