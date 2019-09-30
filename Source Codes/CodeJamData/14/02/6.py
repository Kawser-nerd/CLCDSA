import sys

      
def get_nums(n):
  nums = []
  tot = 0
  while tot < n:
    next = [ float(x) for x in (raw_input()).split(' ') ]
    tot += len(next)
    nums.extend(next)

  return nums
  
    
def main():
  nt = int(raw_input())

  for test_idx in range(1,nt+1):
    C,F,X = get_nums(3)

    R = max(int( (X*F - 2*C + 1e-9)/(C*F)),0)
    total = 0.0
    for idx in range(0, R):
      total += ( C/(2.0+F*idx) )
      #print total
    total += ( X/(2.0+F*R))
      
    print 'Case #%d: %.7f' % (test_idx, total)


if __name__ == '__main__':
  main()
  
