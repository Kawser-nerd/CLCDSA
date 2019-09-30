import sys
from numpy import *

def get_nums(n):
  nums = []
  tot = 0
  while tot < n:
    next = [ long(x) for x in (raw_input()).split(' ') ]
    tot += len(next)
    nums.extend(next)

  return nums

def get_int():
  return int(raw_input())
    
def main():
  nt = int(raw_input())

  for test_idx in range(1,nt+1):

    rowa = get_int()
    arows = zeros((4,4), int)
    for idx in range(0,4):
      arows[idx,] = get_nums(4)

    rowb = get_int()
    brows = zeros((4,4), int)
    for idx in range(0,4):
      brows[idx] = get_nums(4)

    left = filter((lambda g: g in arows[rowa-1]), brows[rowb-1])

    #print left
    if len(left) == 0:
      result = "Volunteer cheated!"
    elif len(left) == 1:
      result = left[0]
    else:
      result = "Bad Magician!"
    print 'Case #%d: %s' % (test_idx, str(result))


if __name__ == '__main__':
  main()
  
