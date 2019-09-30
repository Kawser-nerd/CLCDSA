import sys
from collections import deque

A,B = map(int,input().split())
ask = lambda x,y: print('?',x,y, flush=True)

if A <= B:
  print('Impossible', flush=True)
  sys.exit()

N = A+B
candidates = deque(range(N), N)

while len(candidates) > 2:
  x,y = candidates.pop(), candidates.pop()
  ask(x,y)
  if input() == 'Y':
    candidates.appendleft(y)

god = candidates[0]
result = []
for i in range(N):
  ask(god,i)
  result.append(input() == 'Y')

print('!', ''.join(str(int(s)) for s in result), flush=True)