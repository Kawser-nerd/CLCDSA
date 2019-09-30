#!/usr/bin/python3

T = int(input())

for C in range(1, T + 1):
  D, I, M, N = input().split(' ')
  D, I, M, N = int(D), int(I), int(M), int(N)

  x = input().split(' ')
  r = [0] * 256

  for q in x:
    nr = list(map(lambda i: i + D, r))
    q = int(q)

    if M == 0:
      for i in range(256):
        nr[i] = min(nr[i], r[i] + abs(q - i))
    else:
      for i in range(256):
        for j in range(256):
          nr[j] = min(nr[j], r[i] + abs(q - j) + (max(0, abs(i - j) - 1) // M) * I)

    r = nr

  print('Case #%d: %s' % (C, min(r)))
