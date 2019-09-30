from __future__ import division
import sys
#import psyco
#psyco.full()
range = xrange
from copy import copy

dp = {}

debug = False
def main():
  global infile
  global out_file
  global debug
  global dp
  in_filename = sys.argv[1]
  out_filename = sys.argv[2]
  if len(sys.argv)>=4:
    debug = True
  in_file = open(in_filename, 'r')
  out_file = open(out_filename, 'w')

  t = get_next_int(in_file)

  results = []
  for step in range(int(t)):
    k, n = get_nexts_int(in_file)
    start_keys = get_nexts_int(in_file)
    chests = [Chest(get_nexts_int(in_file)) for i in range(n)]

    answer = solve(k, n , start_keys, chests)
    results.append(str(answer))
  print_out(results, out_file,debug)

class Chest(object):
  def __init__(self, param):
    open_type = param[0]
    t = param[1]
    contain_keys = param[2:]
    self.__dict__.update(locals())

def solve(k, n , start_keys, chests):
  global dp
  dp = {}
  answer = _solve([], start_keys, chests)
  
  if answer == "":
    return "IMPOSSIBLE"
  else:
    return answer
def _solve(routes, own_keys, chests):
  #print routes, own_keys
  if tuple(sorted(routes)) in dp:
    return ""
  for i, chest in enumerate(chests):
    if not i in routes and chest.open_type in own_keys:
      if (len(routes) + 1) == len(chests):
        return str(i+1)
      copy_keys = copy(own_keys)
      copy_keys.remove(chest.open_type)
      answer = _solve(routes + [i],copy_keys+chest.contain_keys,chests)
      if answer != "":
        return str(i+1) + " " + answer
  dp[tuple(sorted(routes))] = ""
  return ""
def get_next(f):
  line = f.readline()
  return line.rstrip('\n')
def get_nexts(f):
  line = f.readline()
  return line.rstrip('\n').split(" ")

def get_next_int(f):
    return int(get_next(f))

def get_nexts_int(f):
    return map(int, get_nexts(f))
def get_nexts_float(f):
    return map(float, get_nexts(f))
    
def get_nexts_digit(f):
    return map(int, list(get_next(f)))

def print_out(results, out_file, debug=False):
  for i, result in enumerate(results):
    num = i + 1
    out_file.write("Case #%d: %s\n" % (num, result ))


if __name__ == '__main__':
  main()
