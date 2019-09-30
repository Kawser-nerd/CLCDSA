#!/usr/bin/python

import os
import sys
import math

def integral(R, x1, x2):
  return 0.5*(x2*math.sqrt(R*R - x2*x2) - x1*math.sqrt(R*R - x1*x1) +
      R*R*(math.asin(x2/R) - math.asin(x1/R)))

def pos_area(R, x0, y0, d):
  R2 = R*R
  if x0*x0 + y0*y0 >= R2:
    return 0
  if (x0 + d)**2 + (y0 + d)**2 <= R2:
    return d*d
  if (x0 + d)**2 + y0*y0 <= R2:
    if x0*x0 + (y0 + d)**2 >= R2:
      return integral(R, x0, x0 + d) - d*y0
    else:
      lb = math.sqrt(R2 - (y0 + d)**2)
      return integral(R, lb, x0 + d) - y0*(x0 + d - lb) + d*(lb - x0)
  if x0*x0 + (y0 + d)**2 >= R2:
    ub = math.sqrt(R2 - y0*y0)
    return integral(R, x0, ub) - y0*(ub - x0)
  else:
    lb = math.sqrt(R2 - (y0 + d)**2)
    ub = math.sqrt(R2 - y0*y0)
    return integral(R, lb, ub) - y0*(ub - lb) + d*(lb - x0)


def hole_area(R, g, r):
  tot = 0
  if g <= 0 or R <= 0:
    return 0
  stx = sty = r
  while True:
    x = stx
    y = sty
    ar = pos_area(R, x, y, g)
    if ar == 0:
      break
    tot += ar
    while True:
      x += 2*r + g
      ar = pos_area(R, x, y, g)
      if ar == 0:
        break
      tot += ar
    sty += 2*r + g
  return tot


def fly_area(R, t, g, r, f):
  return hole_area(R - t - f, g - 2*f, r + f)


def prob(R, t, g, r, f):
  return 4*fly_area(R, t, g, r, f)/(math.pi*R*R)


N = int(sys.stdin.readline().strip())
for nc in xrange(1, N + 1):
  (f, R, t, r, g) = [float(x) for x in sys.stdin.readline().strip().split()]
  print 'Case #%d: %s' % (nc, 1 - prob(R, t, g, r, f))
  nc += 1
