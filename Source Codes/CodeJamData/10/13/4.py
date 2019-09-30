#!/usr/bin/python3

T = int(input())

def win(x, y):
  if x < y:
    x, y = y, x
  if x == y:
    return False
  if x >= 2 * y:
    return True
  return not win(y, x - y)

for C in range(1, T + 1):
  A1, A2, B1, B2 = input().split(' ')
  A1, A2, B1, B2 = int(A1), int(A2), int(B1), int(B2)

  cnt = 0
  
  for A in range(A1, A2 + 1):
    for B in range(B1, B2 + 1):
      if win(A, B):
        cnt += 1

  print('Case #%d: %s' % (C, cnt))
