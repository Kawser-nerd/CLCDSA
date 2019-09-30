#!/usr/bin/python

import os
import sys
import math
import array
import collections

class mstate(object):
  __slots__ = ['query', 'engine', 'switches']
  def __init__(self, query, engine, switches=0):
    self.query = query
    self.engine = engine
    self.switches = switches
    
def process_case(inf):
  S = int(inf.readline().strip())
  engines = dict([(y[1], y[0]) for y in enumerate([inf.readline().strip() 
    for x in xrange(S)])])
  Q = int(inf.readline().strip())
  if Q <= 0:
    return 0
  queries = list()
  for q in xrange(Q):
    cur_q = engines.get(inf.readline().strip(), -1)
    queries.append(cur_q)
  M = [array.array('i', (2147483647 for x in xrange(Q))) for y in xrange(S)]
  dq = collections.deque()
  for s in xrange(S):
    dq.append(mstate(0, s))
  while dq:
    st = dq.popleft()
    if st.query >= Q:
      continue
    cur_q = queries[st.query]
    if cur_q == st.engine:
      new_sw = st.switches + 1
    else:
      new_sw = st.switches
    if new_sw >= M[st.engine][st.query]:
      continue
    M[st.engine][st.query] = new_sw
    if cur_q == st.engine:
      for s in xrange(S):
        if s != st.engine:
          new_st = mstate(st.query + 1, s, new_sw)
          dq.append(new_st)
    else:
      new_st = mstate(st.query + 1, st.engine, new_sw)
      dq.append(new_st)
  return min([M[sp][Q - 1] for sp in xrange(S)])


N = int(sys.stdin.readline().strip())
for nc in xrange(1, N + 1):
  ms = process_case(sys.stdin)
  print 'Case #%d: %s' % (nc, ms)
