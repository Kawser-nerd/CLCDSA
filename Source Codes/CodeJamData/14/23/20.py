#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys, os, shutil
import math as m, random as r
import numpy as np
import multiprocessing as mp


def ccheck(start, flightsFrom, visited):
  queued = [False for _ in flightsFrom]
  cl = start[:]
  for v in cl: queued[v] = True
  while cl:
    nl = []
    for v in cl:
      for u in flightsFrom[v]:
        if not queued[u]:
          nl.append(u)
          queued[u] = True
    cl = nl
  for i in range(len(flightsFrom)):
    if not (visited[i] or queued[i]): return False
  return True


def solve_single_test(LOCK, t, data, out):
  LOCK.acquire()
  OUT = open(out, 'wt')
  OUT.write('Case #%d: ' % (t + 1))
  
  scodes, flights = data
  
  codes = [int(sc) for sc in scodes]
  visited = [False for _ in codes]
  
  flightsFrom = [set() for _ in codes]
  for f in flights:
    flightsFrom[f[0]].add(f[1])
    flightsFrom[f[1]].add(f[0])
  
  c = min(enumerate(codes), key=lambda t: (t[1]))[0]
  visited[c] = True
  result = scodes[c]
  todo = len(codes) - 1
  flStack = []
  
  while todo:
    for i in range(len(flightsFrom)):
      flightsFrom[i].discard(c)
    
    choices = []
    for n in flightsFrom[c]:
      if not visited[n]:
        choices.append((codes[n], 0, n))
    
    path = [f[0] for f in flStack] + [c]
    
    for depth in range(1, len(flStack) + 1):
      if ccheck(path[:-depth], flightsFrom, visited):
        tc = path[-depth-1]
        for n in flightsFrom[tc]:
          if not visited[n]:
            choices.append((codes[n], depth, n))
    
    choices.sort()
    
    # Fly back
    for i in range(choices[0][1]):
      c = flStack.pop(-1)[0]
    
    f = c
    t = choices[0][2]
    flStack.append([f, t])
    flightsFrom[f].discard(t)
    flightsFrom[t].discard(f)
    
    c = t
    visited[c] = True
    
    result += scodes[c]
    
    todo -= 1
  
  
  OUT.write('%s\n' % result)
  
  OUT.close()
  LOCK.release()


def get_single_test_data(IN):
  N, M = map(int, IN.readline().split())
  scodes = []
  flights = []
  for c in range(N):
    scodes.append('%.5d' % int(IN.readline()))
  for f in range(M):
    flights.append(list(map(lambda x: int(x)-1, IN.readline().split())))
  return (scodes, flights)


def main():
  assert len(sys.argv) > 1
  in_path = sys.argv[1]
  assert in_path.endswith('.in')
  IN = open(in_path, 'rt')
  os.chdir(os.path.dirname(sys.argv[0]))
  T = int(IN.readline())
  data = []
  for t in range(T): data.append(get_single_test_data(IN))
  IN.close()
  
  out_dirname = in_path[:-3]
  if os.path.exists(out_dirname): shutil.rmtree(out_dirname)
  os.makedirs(out_dirname)
  
  test_filenames = [os.path.join(out_dirname, 'test%.5d.out' % (t + 1)) for t in range(T)]
  
  LOCK = mp.BoundedSemaphore(5)
  processes = []
  for t in range(T): processes.append(mp.Process(target=solve_single_test, args=(LOCK, t, data[t], test_filenames[t])))
  
  for p in processes: p.start()
  for p in processes: p.join()
  
  out_path = '%s.out' % (out_dirname)
  
  FULL_OUT = open(out_path, 'wt')
  
  for t in range(T):
    TEST_RESULT = open(test_filenames[t], 'rt')
    for l in TEST_RESULT:
      FULL_OUT.write(l)
    TEST_RESULT.close()
  
  FULL_OUT.close()

if __name__ == '__main__':
  main()

