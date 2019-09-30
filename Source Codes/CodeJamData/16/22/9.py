memo = {}
bestChoice = {}
A = ''
B = ''
N = 0

def rec(i, stay, sgn):
  global memo, bestChoice
  if i == N:
    return 0

  if (i, stay, sgn) in memo:
    return memo[(i, stay, sgn)]
  else:
    cA = A[i]
    cB = B[i]

    choicesA = [int(cA)] if cA != '?' else range(0, 10)
    choicesB = [int(cB)] if cB != '?' else range(0, 10)

    ans = 10000000000000000000
    bc = None
    for chA in choicesA:
      for chB in choicesB:
        if (chA > chB):
          if (stay != '<'):
            xx = sgn * (chA - chB) * (10**(N-i-1)) + rec(i + 1, '?', sgn)
            if xx < ans:
              ans = xx
              bc = (chA, chB)
        elif (chA < chB):
          if (stay != '>'):
            xx = sgn * (chA - chB) * (10**(N-i-1)) + rec(i + 1, '?', sgn)
            if xx < ans:
              ans = xx
              bc = (chA, chB)
        else: # chA == chB
          xx = rec(i + 1, stay, sgn)
          if xx < ans:
            ans = xx
            bc = (chA, chB)
    memo[(i, stay, sgn)] = ans
    bestChoice[(i, stay, sgn)] = bc
    return ans

def solveCase(a, b, stay, sgn):
  global A, B, N, memo
  assert len(A) == len(B)
  A = a
  B = b
  N = len(A)
  memo = {}
  bestChoice = {}
  return rec(0, stay, sgn)

def rebuild(stay, sgn):
  sA = ''
  sB = ''

  for i in xrange(N):
    bc = bestChoice[(i, stay, sgn)]
    sA += str(bc[0])
    sB += str(bc[1])
    if (bc[0] != bc[1]):
      stay = '?'
  return (sA, sB)

def solve():
  A, B = raw_input().strip().split()
  caseAB = solveCase(A, B, '<', -1)
  caseBA = solveCase(A, B, '>', 1)

  #print caseAB, caseBA

  if caseAB < caseBA:
    solAB = rebuild('<', -1)
    return '%s %s' % solAB
  elif caseBA < caseAB:
    solBA = rebuild('>', 1)
    return '%s %s' % solBA
  else:
    solAB = rebuild('<', -1)
    solBA = rebuild('>', 1)
    return '%s %s' % min(solAB, solBA)

T = input()
for i in xrange(T):
  print 'Case #%d: %s' % (i + 1, solve())
