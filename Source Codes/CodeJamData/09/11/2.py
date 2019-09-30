file = "A-small-attempt0"
inp = open(file + ".in")

import pdb
def dsum(num, b):
  n = num
  sumd = 0
  while n > 0:
    sumd += (n % b)**2
    n /= b
  return sumd

def happy(num, b, hp):
  if num in hp:
    return hp[num]
  if num == 1:
    return True
  ds = dsum(num,b)
  hp[num] = False
  if happy(ds, b, hp):
    hp[num] = True
  return hp[num]


for it, case in enumerate(list(inp)[1:]):
  bases = map(int, case.split())
  hps=[]
  for i in range(11):
    hps.append({})
  for num in range(2,10000000):
    if all([happy(num, b, hps[b]) for b in bases]):
      break
  print "Case #%d: %d" % (it + 1, num)
