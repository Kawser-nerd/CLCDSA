
C = 0
D = 0
V = 0
h = []

def solve():
  r = raw_input().split()
  C = int(r[0])
  D = int(r[1])
  V = int(r[2])
  h = raw_input().split()
  for i in range(len(h)):
    h[i] = int(h[i])
  h = sorted(h)
  q = 1
  summ = 0
  i = 0
  ret = 0
  while(q <= V):  
    if(i<D and h[i]<=q):
      summ = summ + C*h[i]
      i = i + 1
      q = summ + 1
    else:
      ret = ret + 1
      summ = summ + C*q
      q = summ + 1
  return ret

TTT = int(input())
for ttt in range(1,TTT+1):
  print('Case #{}: {}'.format(ttt,solve()))
