#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import math, os, sys, random
from multiprocessing import Process, BoundedSemaphore, Value, Array

INBUF = []
sem = BoundedSemaphore(8)


def calculate_profit(data, c, level, b, s):
  profit = 0
  for t in range(c - 1):
    if level * c - s + t > b: break
    tp = 0
    for i in range(c - t): tp += (level - data[i])
    tp = (tp * 36.0 / (c - t)) - (level * c - s + t)
    if tp > profit: profit = tp
  return profit


def single_test(INBUF, INDEX):
  sem.acquire()
  
  b, data = INBUF[INDEX]
  while len(data) < 37: data.append(0)
  data.sort()
  
  data.append(max(data[-1], b) + 1)
  
  result = 0
  log = ''
  s = 0
  for i in range(37):
    m = data[i]
    s += m
    if data[i + 1] == m: continue
    c = i + 1
    if m * c - s > b: break
    
    # Approach 1: minimal
    level = m
    profit = calculate_profit(data, c, level, b, s)
    if profit > result: result = profit
    log += 'Trying %d fields with %d\n' % (c, level)
      
    
    # Approach 2: almost-maximal
    level = min(data[i + 1] - 1, int((b + s) / c) - 1)
    if level > m:
      profit = calculate_profit(data, c, level, b, s)
      if profit > result: result = profit
      log += 'Trying %d fields with %d\n' % (c, level)
      
    
    # Approach 2: maximal
    level = min(data[i + 1] - 1, int((b + s) / c))
    if level > m:
      profit = calculate_profit(data, c, level, b, s)
      if profit > result: result = profit
      log += 'Trying %d fields with %d\n' % (c, level)
    
  
  # result = int(result * 1000000.0 + 0.5) * 0.000001
  result = '%.10f' % result
  push_output(INDEX, str(result))
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
  B, N = map(int, IN.readline().split())
  data = list(map(int, IN.readline().split()))
  INBUF.append((B, data))


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

