def zeroOr9(bigger, current):
  if bigger == current:
    return "0"
  else:
    return "9"

def can_match(ints, strs):
  s = str(ints).zfill(len(strs))
  for i in xrange(len(strs)):
    if strs[i] !="?" and strs[i] != s[i]:
      return False
  return True

#(int,str)->(c,j)
#3 goals: maxC, maxJ or equal
#N = len(C)=len(J)
cache = dict()
def do_dynamic(C,J,N,start,goal):
  if start == N:
    return ("","")
  cached = cache.get((start,goal),None)
  if cached is not None:
    return cached
  if goal == "maxC":
    if C[start] == "?":
      c = "9"
    else:
      c = C[start]
    if J[start] == "?":
      j = "0"
    else:
      j = J[start]
    (cs, js) = do_dynamic(C,J,N,start+1,goal)
    return (c+cs, j+js)
  elif goal == "maxJ":
    if C[start] == "?":
      c = "0"
    else:
      c = C[start]
    if J[start] == "?":
      j = "9"
    else:
      j = J[start]
    (cs, js) = do_dynamic(C,J,N,start+1,goal)
    cache[(start, goal)] = (c+cs, j+js)
    return (c+cs, j+js)
  else:
    rngi = xrange(0,10)
    if C[start] != "?":
      rngi = [int(C[start])]
    rngj = xrange(0,10)
    if J[start] != "?":
      rngj = [int(J[start])]
    bestAbs = None
    bestC = None
    bestJ = None
    #limit to nearby
    for c in rngi:
      for j in rngj:
        if (len(rngi) > 1 or len(rngj) > 1) and abs(c-j)>1:
          continue
        if c > j:
          cs, js = do_dynamic(C,J,N,start+1,"maxJ")
        elif c < j:
          cs, js = do_dynamic(C,J,N,start+1,"maxC")
        else:
          cs, js = do_dynamic(C,J,N,start+1,"equal")
        ccs = str(c)+cs
        jjs = str(j)+js
        absx = abs(int(ccs)-int(jjs))
        if bestAbs is None or absx < bestAbs:
          bestAbs = absx
          bestC = ccs
          bestJ = jjs
    cache[(start, goal)] = (bestC, bestJ)
    return (bestC, bestJ)
def do_brute(C,J):
  bestC = None
  bestJ = None
  bestAbs = None
  for c in xrange(0,10**len(C)):
    for j in xrange(0,10**len(J)):
      if can_match(c,C) and can_match(j,J):
        absx = abs(c-j)
        if bestAbs is None or absx < bestAbs or (absx == bestAbs and c < bestC) or (absx == bestAbs and c == bestC and j < bestJ):
          bestAbs = absx
          bestC = c
          bestJ = j
          if bestAbs == 0:
            return (str(bestC), str(bestJ))
  return (str(bestC).zfill(len(c)), str(bestJ).zfill(len(j)))
        
def do_case(C,J):
  N = len(C)
  foundDifference = None # or "C" or "J" indicating which is bigger
  outC = ""
  outJ = ""
  for i in xrange(N):
    if foundDifference is None:
      if C[i] == J[i]:
        if C[i] == "?":
          outC+="0"
          outJ+="0"
        else:
          outC+=C[i]
          outJ+=J[i]
      elif C[i] == "?":
        outC+=J[i]
        outJ+=J[i]
      elif J[i] == "?":
        outC+=C[i]
        outJ+=C[i]
      elif int(C[i])>int(J[i]):
        foundDifference = "C"
        outC+=C[i]
        outJ+=J[i]
      else:
        foundDifference = "J"
        outC+=C[i]
        outJ+=J[i]
    else:
      if C[i] == "?":
        outC+=zeroOr9(foundDifference,"C")
      else:
        outC+=C[i]
      if J[i] == "?":
        outJ+=zeroOr9(foundDifference,"J")
      else:
        outJ+=J[i]
  return (outC, outJ)

f = open("B-large.in").read()
lines = f.split("\n")
T = int(lines[0])
i=1
out=""
for line in lines[1:]:
  if len(line) > 0:
    parts = line.split(" ")
    cache = dict()
    res = do_dynamic(parts[0],parts[1],len(parts[0]), 0, "equal")
    out+="Case #%d: %s %s\n" % (i, res[0], res[1])
    #print("Case #%d: %s %s\n" % (i, res[0], res[1]))
    i+=1
  
open("B-large.out","w").write(out)
