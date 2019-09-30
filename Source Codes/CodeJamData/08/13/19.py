#!/usr/bin/env python
# -*- coding: iso8859-1 -*-
#
# gcj_round1A_C.py
#
# mariopal
# 7-2008
#
# Using Python 2.5.2 in Linux (Debian Sid):
# $ ./gcj_round1A_C.py input.in > output.out
#
"""
Use: python gcj_round1A_C.py input.in > output.out
"""
# ----------------------------------------------------------------------------
import sys
import decimal
decimal.getcontext().prec = 1000
from decimal import Decimal


def out(x):
  sys.stdout.write(str(x))
def out_ln(x):
  sys.stdout.write(str(x) + "\n")
# ----------------------------------------------------------------------------


def test(n):
  base = Decimal("3") + Decimal("5").sqrt()
  A = base**Decimal(n)
  B = int(A)
  R = "000" + str(B)
  return R[-3:]
#test


def main():
  if len(sys.argv) > 1:
    inputfile = sys.argv[1]
  else:
    print __doc__
    return

  ftest = open(inputfile, "rb")
  line = ftest.readline()
  numtests = int(line)
  t = 1
  while t <= numtests:
    line = ftest.readline()
    p = line[:-1].split(" ")
    R = test(p[0])
    out_ln("Case #" + str(t) + ": " + R)
    t += 1
  ftest.close()
#main


if __name__ == '__main__':
  main()
