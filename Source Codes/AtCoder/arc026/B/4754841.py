import math
N = int(input())
sub = 0
if math.sqrt(N) != int(math.sqrt(N)):
  for i in range(1,int(math.sqrt(N))+1):
    if N%i == 0:
      sub += i+N//i
  if sub/2 == N:
    print('Perfect')
  elif sub/2 > N:
    print('Abundant')
  else:
    print('Deficient')
else:
  for i in range(1,int(math.sqrt(N))+1):
    if N%i == 0:
      sub += i+N//i
  sub -= N**0.5
  sub -= N
  if sub == N:
    print('Perfect')
  elif sub > N:
    print('Abundant')
  else:
    print('Deficient')