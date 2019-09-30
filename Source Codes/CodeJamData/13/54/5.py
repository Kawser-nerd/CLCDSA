#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import math, os, sys, random
from multiprocessing import Process, BoundedSemaphore, Value, Array

INBUF = []
sem = BoundedSemaphore(8)

def fix(d):
  N = len(d)
  s = d[:]
  t = d[:]
  for i in range(1, N):
    t.append(t.pop(0))
    if t < s: s = t[:]
  return s

def num(d):
  m = 1
  r = 0
  for c in d:
    if c: r += m
    m *= 2
  return r

def get_result(d, k, f):
  if f <= 0: return 0
  
  d = fix(d)
  N = len(d)
  h = num(d)
  
  if h in k: return k[h]
  
  dd = d + d
  r = 0
  
  for i in range(N):
    s = i
    while dd[s]: s += 1
    prize = N - (s - i)
    s %= N
    d[s] = True
    r += prize + get_result(d, k, f - 1)
    d[s] = False
  
  r /= float(N)
  
  k[h] = r
  
  return r



def single_test(INBUF, INDEX):
  sem.acquire()
  
  data = INBUF[INDEX]
  data = [c =='X' for c in data]
  N = len(data)
  known = dict()
  result = get_result(data, known, data.count(False))
  
  result = '%.13f' % result
  push_output(INDEX, result)
  sem.release()




def push_output(INDEX, data):
  f = open('tmp-%.3d.buf' % INDEX, 'wt')
  f.write(data)
  f.close()

def fetch_output(INDEX):
  f = open('tmp-%.3d.buf' % INDEX, 'rt')
  data = ''.join([l for l in f.readlines()])
  f.close()
  os.unlink('tmp-%.3d.buf' % INDEX)
  return data

def fetch_input(IN, INBUF):
  data = IN.readline()[:-1]
  INBUF.append(data)


def main(IN, OUT):
  T = int(IN.readline())
  
  for i in range(T):
    fetch_input(IN, INBUF)
  
  processes = []
  
  for i in range(T):
    p = Process(target=single_test, args=(INBUF, i))
    p.start()
    processes.append(p)
  
  for i in range(T):
    processes[i].join()
  
  for i in range(T):
    OUT.write('Case #%d: %s\n' % (i + 1, fetch_output(i)))


if __name__ == '__main__':
  assert len(sys.argv) == 2
  IN = open(sys.argv[1], 'rt')
  OUT = open('%s.out' % sys.argv[1][:-3], 'wt')
  main(IN, OUT)
  OUT.close()
  IN.close()

