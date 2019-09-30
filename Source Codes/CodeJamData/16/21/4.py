#!/usr/bin/python3

'''
Z → 0 ZERO
W → 2 TWO
G → 8 EIGHT
X → 6 SIX
U → 4 FOUR
F → 5 FIVE
V → 7 SEVEN
R → 3 THREE
I → 9 NINE
O → 1 ONE
'''

def solve():
  s = input()
  cnt = {}
  for c in 'QWERTYUIOPASDFGHJKLZXCVBNM':
    cnt[c] = 0
  for a in s:
    cnt[a] += 1
  a = ['ZERO', 'TWO', 'EIGHT', 'SIX', 'FOUR', 'FIVE', 'SEVEN', 'THREE', 'NINE', 'ONE']
  b = [   'Z',   'W',     'G',   'X',    'U',    'F',     'V',     'R',    'I',   'O']
  d = [   '0',   '2',     '8',   '6',    '4',    '5',     '7',     '3',    '9',   '1']
  res = []
  for i in range(10):
    x = cnt[b[i]]
    for c in a[i]:
      cnt[c] -= x
    for j in range(x):
      res.append(d[i])
  res.sort()
  ans = ''
  for d in res:
    ans += str(d)
  return ans

nt = int(input())
for tt in range(nt):
  print('Case #' + str(tt + 1) + ': ' + str(solve()))
