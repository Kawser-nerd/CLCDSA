import json
cache = {}
cache_out = open('cache', 'a', 1)
cache_in = open('cache', 'r', 1)
for line in cache_in.readlines():
    (key, data) = json.loads(line)
    cache[key] = data

def do_md5(s): return str(s)
def memoize2(keyformat="%s", filesystem=False):
  def decorator(fxn):
    def wrapper(*args, **kwargs):
      global cache
      if isinstance(keyformat, str):
        key = do_md5(keyformat % args[0:keyformat.count('%')])
      elif isinstance(keyformat, function):
        key = do_md5(keyformat(*args, **kwargs))
      else:
        raise TypeError("Memoize keyformat must be a function or string")
      if key in cache: return cache[key]
      data = fxn(*args, **kwargs)
      cache[key] = data
      if filesystem:
          cache_out.write("%s\n" % json.dumps([key, data]))
      return data
    return wrapper
  return decorator

################################################################
def solve(prob):
    def ok(i1,j1,i2,j2):
        try:
            x=rows[i1][j1]
            y=rows[i2][j2]
        except:
            return True
        return x==" " or y==" " or x==y
    # @memoize2(str(prob) + "h: %d")
    def hsym(s):
        for i in range(0,s+1):
            for j in range(0,2*k-1):
                if not ok(s-i,j,s+i,j): return False
        return True
    # @memoize2(str(prob) + "v: %d")
    def vsym(s):
        for j in range(0,s+1):
            for i in range(0,2*k-1):
                if not ok(i,s-j,i,s+j): return False
        return True
    k = int(input.readline())
    rows = range(0,2*k-1)
    for i in range (0,2*k-1):
        rows[i] = input.readline()[:-1]
    cost = 999999999999999
    for i in range(0,2*k-1):
        for j in range(0,2*k-1):
            if hsym(i) and vsym(j):
                c = abs(i+1-k) + abs(j+1-k)
                c = (k+c)**2
                if c<cost:
                    mini = i
                    minj = j
                    cost = c
    return cost - k**2
################################################################

from datetime import datetime
time_start = datetime.today()
def now(): return datetime.today() - time_start 

import sys
infilename = sys.argv[1]
outfilename = infilename.replace('.in','.out')

input = open(sys.argv[1], 'r')
output = open(sys.argv[1].replace('.in','.out'), 'w')
n = int(input.readline())

for i in range(1,n+1):
    result = solve(i)
    print "Case #%d: %d \t %s" % (i, result, now())
    output.write("Case #%d: %d\n" % (i, result))
