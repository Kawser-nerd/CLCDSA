# coding: utf-8
import sys
import heapq
import bisect
import operator
from itertools import *

def read():
  return int(input())

def reads():
  return [int(s) for s in input().split()]

T = read()

def ch(w, i, c):
  # print(w, type(i), c)
  return w[:i] + c + w[i+1:]

def maximize(w):
  return w.replace("?", "9")

def minimize(w):
  return w.replace("?", "0")

def prv(c):
  return str(max(int(c) - 1, 0))

def nxt(c):
  return str(min(int(c) + 1, 9))


def solve(C, J):
  assert (len(C) == len(J))
  if not "?" in (C + J):
    return (abs(int(J) - int(C)), C, J)
  else:
    i = min(i for i in range(len(C)) if C[i] == "?" or J[i] == "?")
    if i > 0 and int(C[:i]) < int(J[:i]):
      C = maximize(C)
      J = minimize(J)
      return (abs(int(J) - int(C)), C, J)
    elif i > 0 and int(C[:i]) > int(J[:i]):
      C = minimize(C)
      J = maximize(J)
      return (abs(int(J) - int(C)), C, J)

    if C[i] != "?":
      c = C[i]
      return min(solve(C, ch(J, i, prv(c))),
                 solve(C, ch(J, i, c)),
                 solve(C, ch(J, i, nxt(c))))
    elif J[i] != "?":
      c = J[i]
      return min(solve(ch(C, i, prv(c)), J),
                 solve(ch(C, i, c),      J),
                 solve(ch(C, i, nxt(c)), J))
    else:
      return min(solve(ch(C, i, "0"), ch(J, i, "0")),
                 solve(ch(C, i, "0"), ch(J, i, "1")),
                 solve(ch(C, i, "1"), ch(J, i, "0")))


for case in range(1, T+1):
  print("case = {0}".format(case), file = sys.stderr)
  (C, J) = input().split()
  (_, c, j) = solve(C, J)

  print("Case #{0}: {1} {2}".format(case, c, j))
