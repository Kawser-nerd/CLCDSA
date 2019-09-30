import json
cache = {}
cache_out = open('cache', 'a', 1)
cache_in = open('cache', 'r', 1)
for line in cache_in.readlines():
    (key, data) = json.loads(line)
    cache[key] = data

def do_md5(s):
  return str(s)

function = type(do_md5)
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

def solve():
    N,M = [int(x) for x in input.readline().split(' ')]
    X = [int(x) for x in input.readline().split(' ')]
    a = [X[2*i] for i in range(N)]
    A = [X[2*i+1] for i in range(N)]
    X = [int(x) for x in input.readline().split(' ')]
    b = [X[2*i] for i in range(M)]
    B = [X[2*i+1] for i in range(M)]
    return do(A, a, B, b)

def top(L):
    return L[len(L)-1]

@memoize2("%s%s%s%s")
def do(A,a,B,b): # A are the types, a are the counts
    if len(A) == 0 or len(B) == 0:
        result = 0
    elif top(A) == top(B):
        A2, a2, B2, b2 = list(A), list(a), list(B), list(b)
        if top(a) == top(b):
            A2.pop()
            a2.pop()
            B2.pop()
            b2.pop()
        elif top(a) <= top(b):
            A2.pop()
            a2.pop()
            b2[len(b2)-1] -= top(a)
        elif top(a) >= top(b):
            B2.pop()
            b2.pop()
            a2[len(a2)-1] -= top(b)
        result = do(A2, a2, B2, b2) + min(top(a), top(b))
    else:
        A2, a2, B2, b2 = list(A), list(a), list(B), list(b)
        A3, a3, B3, b3 = list(A), list(a), list(B), list(b)
        A2.pop()
        a2.pop()
        B3.pop()
        b3.pop()
        result = max(do(A2, a2, B2, b2), do(A3, a3, B3, b3))
    return result
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
    result = solve()
    print "Case #%d: %s \t %s" % (i, result, now())
    output.write("Case #%d: %s\n" % (i, result))
