import sys

sys.setrecursionlimit(11000)

#f = open('test', 'r')
f = open('B-large.in', 'r')

T = int(f.readline())

def find_best(values, start, end):
  best = values[start]
  bestI = start
  for i in xrange(start, end):
    if values[i] > best:
      best = values[i]
      bestI = i
  return best, bestI

def solve(E, R, N, values):
  
  def top_to_bottom(start, end):
    if start == end:
      return 0
    best, bestI = find_best(values, start, end)
    
    return top_to_top(start, bestI) + bottom_to_bottom(bestI+1, end) + E*values[bestI]
    
  def top_to_top(start, end):
    if start == end:
      return 0
    best, bestI = find_best(values, start, end)
    
    if R*(end - bestI) >= E:
      return top_to_top(start, bestI) + bottom_to_top(bestI+1, end) + E*values[bestI]
    else:
      return top_to_top(start, bestI) + R*(end - bestI)*values[bestI]
    
  def bottom_to_bottom(start, end):
    if start == end:
      return 0
    best, bestI = find_best(values, start, end)
    
    if R*(bestI-start+1) >= E:
      return bottom_to_top(start, bestI) + bottom_to_bottom(bestI+1, end) + E*values[bestI]
    else:
      return R*(bestI-start+1)*values[bestI] + bottom_to_bottom(bestI+1, end)

  def bottom_to_top(start, end):
    if start == end:
      return 0
    best, bestI = find_best(values, start, end)
    
    ret = 0
    ys = 0
    ye = 0
    
    if R*(bestI - start + 1) >= E:
      ret+= bottom_to_top(start, bestI)
      ys = E
    else:
      ys = R*(bestI - start + 1)
      
    if R*(end - bestI) >= E:
      ret += bottom_to_top(bestI+1, end)
      ye = 0
    else:
      ye = E - R*(end - bestI)
      
    return ret + (ys - ye)*values[bestI]
  
  
  return top_to_bottom(0, N)

for test in range(1, T+1):
  E, R, N = [int(num) for num in f.readline().split()]
  
  values = [int(num) for num in f.readline().split()]
  
  #dp = [[0]*(E+1) for i in xrange(N+1)]
  
  
  #for t in range(N):
    ## process event t
    #for e in range(E+1):
      #for ep in range(e+1):
	#newe = min(e-ep+R, E)
	#dp[t+1][newe] = max(dp[t+1][newe], dp[t][e] + ep*values[t])
  
  #best = max(dp[N])
  
  print 'Case #' + str(test) + ': ' + str(solve(E, R, N, values))
