#!/usr/bin/env python

import sys, math

cases = int(sys.stdin.readline())

for case_no in xrange(1, cases + 1):
  min_d = 0.0
  min_t = 0.0

  nflies = int(sys.stdin.readline())
  flies = []
  for i in xrange(nflies):
    vals = [float(num) for num in sys.stdin.readline().strip().split()]
    flies.append(tuple(vals))

  x = 0.0
  vx = 0.0
  y = 0.0
  vy = 0.0
  z = 0.0
  vz = 0.0
  for fly in flies:
    x += fly[0]
    y += fly[1]
    z += fly[2]
    vx += fly[3]
    vy += fly[4]
    vz += fly[5]

  alpha = x*x + y*y + z*z
  beta = 2*x*vx + 2*y*vy + 2*z*vz
  gamma = vx*vx + vy*vy + vz*vz

  init = pow(alpha, 0.5)
  try:
    min_t = -beta / (2 * gamma)
    if min_t < 0.0:
      min_t = 0.0
    if (alpha + min_t * beta + min_t * min_t * gamma) < 0:
      min_d = 0.0
    else:
      min_d = math.pow((alpha + min_t * beta + min_t * min_t * gamma), 0.5)
  except ZeroDivisionError:
    min_t = 0.0
    min_d = init
  
  if init < min_d:
    min_d = init
  if min_t < 1e-30:
    min_t = 0.0
  if min_d < 1e-30:
    min_d = 0.0
  print "Case #%d: %.8f %.8f" % (case_no, min_d / len(flies), min_t)

