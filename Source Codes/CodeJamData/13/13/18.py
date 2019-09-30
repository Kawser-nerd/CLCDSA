from collections import Counter
T = int(raw_input())

def tobin(n):
  bn = []
  while n > 0:
    if n%2:
      bn.append(1)
    else:
      bn.append(0)
    n = n / 2
  return bn

def pdprob(st):
  pb = {}
  totp = 2**len(st)
  probone = 1.0/totp
  for i in range(totp):
    bn = tobin(i)
    pd = 1
    for j in range(len(bn)):
      if bn[j]==1:
        pd = pd * st[j]
    if pd in pb:
      pb[pd] = pb[pd] + probone
    else:
      pb[pd] = probone
  return pb
  
R, N, M, K = map(int, raw_input().split())

#small testcase
psets = {}
pdp = {}
nposs = (M-1)**3
for p1 in range(2,M+1):
  for p2 in range(p1,M+1):
    for p3 in range(p2,M+1):
      st = (p1,p2,p3)
      psets[st] = [1,3,6][len(Counter(st))-1]*1.0/nposs
      pdp[st] = pdprob(st)

print 'Case #1: '
for i in range(R):
  p = map(int, raw_input().split())
  probs = psets.values()
  sets = psets.keys()
  for j in range(K):
    for k in range(len(sets)):
      if p[j] in pdp[sets[k]]:
        probs[k] = probs[k] * pdp[sets[k]][p[j]]
      else:
        probs[k] = 0
    sp = sum(probs)
    for k in range(len(sets)):
      probs[k] = probs[k] / sp
  ind = probs.index(max(probs))
  print str(''.join(map(str,sets[ind])))