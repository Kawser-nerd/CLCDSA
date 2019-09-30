#!/usr/bin/env python
# -*- coding: utf-8 -*-


def trace(bits, idx, history):
  if idx == len(bits):
    history.append(bits[:])
  elif idx == len(bits) - 1:
    history.append(bits[:])
    bits[idx] = 1 - bits[idx]
    history.append(bits[:])
  else:
    trace(bits, idx + 1, history)
    bits[idx] = 1 - bits[idx]
    trace(bits, idx + 1, history)


def down(bits, idx, count, history):
  if idx == len(bits):
    history.append(bits[:])
  elif idx == len(bits) - 1:
    history.append(bits[:])
    bits[idx] = 1 - bits[idx]
    history.append(bits[:])
  elif count > 0:
    trace(bits, idx + 2, history)
    bits[idx] = 1 - bits[idx]
    trace(bits, idx + 2, history)
    bits[idx + 1] = 1 - bits[idx + 1]
    trace(bits, idx + 2, history)
    bits[idx] = 1 - bits[idx]
    down(bits, idx + 2, count - 2, history)
  else:
    trace(bits, idx + 2, history)
    bits[idx + 1] = 1 - bits[idx + 1]
    trace(bits, idx + 2, history)
    bits[idx ] = 1 - bits[idx ]
    trace(bits, idx + 2, history)
    bits[idx + 1] = 1 - bits[idx + 1]
    down(bits, idx + 2, count - 2, history)


def main():
  n, a, b = map(int, input().split())
  x = a ^ b
  count = 0
  remain = 0
  mapper = [-1] * n

  for i in range(n):
    if (x >> i) & 0x1 != 0:
      mapper[count] = i
      count += 1
    else:
      remain += 1
      mapper[-remain] = i

  if count % 2 == 0:
    print('NO', flush=True)
    return

  bits = [0] * n
  history = []
  trace(bits, 1, history)
  bits[0] = 1
  down(bits, 1, count - 1, history)

  for i in range(len(history)):
    v = history[i][:]

    for j, m in enumerate(mapper):
      history[i][n - m - 1] = v[j]

  history = [str(a ^ int(''.join(str(v) for v in h), 2)) for h in history]

  print('YES', flush=True)
  print(' '.join(history), flush=True)


if __name__ == '__main__':
  main()