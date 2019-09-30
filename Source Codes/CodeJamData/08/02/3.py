#!/usr/bin/python

import os
import sys
import heapq

class event(object):
  __slots__ = ['type', 'st_time', 'end_time', 'station']
  def __init__(self, type, station, st_time, end_time=-1):
    self.type = type
    self.st_time = st_time
    self.end_time = end_time
    self.station = station

  def __cmp__(self, other):
    d = cmp(self.st_time, other.st_time)
    if d == 0:
      if self.type == 'T' and other.type == 'S':
        return -1
      elif self.type == 'S' and other.type == 'T':
        return 1
    return d

  
  def __str__(self):
    if self.type == 'T':
      return 'train ready at %s at %02d:%02d' % (self.station, 
          self.st_time//60, self.st_time%60)
    else:
      return 'scheduled trip from %s (%02d:%02d - %02d:%02d)' % (self.station,
          self.st_time//60, self.st_time%60,
          self.end_time//60, self.end_time%60)

def simulate(inf):
  T = int(inf.readline().strip())
  (NA, NB) = [int(x) for x in inf.readline().strip().split()]
  Q = list()
  for ev in xrange(NA):
    (start, end) = inf.readline().strip().split()
    start = [int(x) for x in start.split(':')]
    start = 60*start[0] + start[1]
    end = [int(x) for x in end.split(':')]
    end = 60*end[0] + end[1]
    heapq.heappush(Q, event('S', 'A', start, end))
  for ev in xrange(NB):
    (start, end) = inf.readline().strip().split()
    start = [int(x) for x in start.split(':')]
    start = 60*start[0] + start[1]
    end = [int(x) for x in end.split(':')]
    end = 60*end[0] + end[1]
    heapq.heappush(Q, event('S', 'B', start, end))
  init_A = init_B = 0
  cur_A = cur_B = 0
  while Q:
    ev = heapq.heappop(Q)
    if ev.type == 'S':
      if ev.station == 'A':
        if cur_A > 0:
          cur_A -= 1
        else:
          init_A += 1
        heapq.heappush(Q, event('T', 'B', ev.end_time + T))
      else:
        if cur_B > 0:
          cur_B -= 1
        else:
          init_B += 1
        heapq.heappush(Q, event('T', 'A', ev.end_time + T))
    else:
      if ev.station == 'A':
        cur_A += 1
      else:
        cur_B += 1
  return (init_A, init_B)


N = int(sys.stdin.readline().strip())
for nc in xrange(1, N + 1):
  (NA, NB) = simulate(sys.stdin)
  print 'Case #%d: %d %d' % (nc, NA, NB)
  nc += 1
