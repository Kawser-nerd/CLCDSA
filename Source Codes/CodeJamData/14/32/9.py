def uniq(x):
  un = x[0]
  for i in range(len(x)-1):
    if (x[i]!=x[i+1]):
      un+=x[i+1]
  return un
  
def fact(x):
  if x==0:
    return 1
  return fact(x-1)*x

def isValid(car):
  car = uniq(car)
  for i in car:
    if car.count(i)>1:
      return False
  return True
  
T = int(raw_input())
for t in range(T):
  ans = 0
  n = int(raw_input())
  cars = map(uniq,raw_input().split())
  allsame = {}
  diffs = []
  starts = []
  ends = []
  mult = 1
  for i in cars:
    c = i[0]
    if i.count(c)==len(i):
      if c not in allsame:
        allsame[c] = 1
      else:
        allsame[c]+=1
    else:
      diffs.append(i)
      starts.append(i[0])
      ends.append(i[-1])
  for i in allsame:
    mult *= fact(allsame[i])
#  print allsame
#  print diffs
  good = True
  for i in cars:
    if not isValid(i):
      good = False
    for j in i[1:-1]:
      for k in cars:
        if k!=i:
          if j in k:
            good = False
  pairs = [''.join(x) for x in zip(starts,ends)]
  noreppairs = [i for i in pairs if i[0]!=i[1]]
  for i in range(len(noreppairs)):
    for j in range(len(noreppairs)):
      if (i!=j):
        if noreppairs[i][0]==noreppairs[j][0]:
          good=False
        if noreppairs[i][1]==noreppairs[j][1]:
          good=False
          
#  print pairs
  
#  print good
#  print mult
  #print noreppairs
  for i in range(n*5+10):
    unused = set(noreppairs)
    used = set()
    chains = []
    for i in noreppairs:
      if i in used:
        continue
      k = i
      unused.remove(i)
      used.add(i)
      chains.append(k)
      while True:
        for j in unused:
          if j[0]==k[-1]:
            chains[-1]+=j
            unused.remove(j)
            used.add(j)
            k = j
            break
        else:
          break
    
    noreppairs = chains[::-1]
  for i in chains:
    if not isValid(i):
      good = False
  #print allsame
  freechoice = {}
  for i in allsame:
    freechoice[i] = True
  for i in freechoice:
    if i in starts:
      freechoice[i] = False
    if i in ends:
      freechoice[i] = False
  #print freechoice
  for i in freechoice:
    if freechoice[i]:
      chains.append(i)
  #print chains
  print "Case #"+str(t+1)+": "+str((good*mult*fact(len(chains))%1000000007))