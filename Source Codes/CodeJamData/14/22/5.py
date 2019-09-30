def getints():
  return [int(x.strip()) for x in raw_input().split(' ')]

memo = {}

def f(A,B,K,n):
  if A>B: A,B=B,A
  if n==-1:
    return 1
  if (A,B,K) in memo:
    return memo[(A,B,K)]
  m = 2**n
  bA = A<=m
  bB = B<=m
  bK = K<=m
  if bA and bB and bK:
    res = f(A,B,K,n-1)
  elif bA and not bB and bK:
    res = f(A,m,K,n-1) + f(A,B-m,K,n-1)
  elif not bA and not bB and bK:
    res = f(m,m,K,n-1) + f(m,B-m,K,n-1) + f(A-m,m,K,n-1)
  elif bA and bB and not bK:
    res = A*B
  elif bA and not bB and not bK:
    res = A*B
  elif not bA and not bB and not bK:
    res = A*B - (A-m)*(B-m) + f(A-m,B-m,K-m,n-1)
  else:
    raise Exception('wtf')
  memo[(A,B,K)] = res
  return res

cases = input()
for case in range(cases):
  A, B, K = getints()
  n = -1
  while A>2**(n+1) or B>2**(n+1) or K>2**(n+1):
    n+=1
  print "Case #" + str(case+1) + ":", f(A,B,K,n)
