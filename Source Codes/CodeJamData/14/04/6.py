import sys

      
def get_nums(n):
  nums = []
  tot = 0
  while tot < n:
    next = [ float(x) for x in (raw_input()).split(' ') ]
    tot += len(next)
    nums.extend(next)

  return nums


def score_lie(A, B, N):

  lost = 0
  BHIGH = N-1
  BLOW = 0
  for idx in range(0,N):
    if A[idx] < B[BLOW]:
      lost += 1
      BHIGH -=1
    else:
      BLOW += 1

  return N - lost

def score_truth(A,B,N):
  BHIGH = N - 1
  BLOW = 0

  won = 0
  for idx in range(N-1,-1,-1):
    if A[idx] > B[BHIGH]:
      won += 1
      BLOW += 1
    else:
      BHIGH -= 1

  return won
    
def main():
  nt = int(raw_input())

  for test_idx in range(1,nt+1):
    N = int(raw_input())

    naomi = get_nums(N)
    ken = get_nums(N)

    

    naomi.sort()
    ken.sort()

   # print naomi

    truth = score_truth(naomi,ken,N)
    lies = score_lie(naomi,ken,N)
    print 'Case #%d: %d %d' % (test_idx, lies, truth)


if __name__ == '__main__':
  main()
  
