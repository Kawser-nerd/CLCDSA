import sys

iFName = "d:\\projekty\\google-jam\\runda-1-b\\a\\A-large.in"
outFN = "d:\\projekty\\google-jam\\runda-1-b\\a\\out-large.txt"

verbose = False
iFile = open(iFName, "r")
outF =  open(outFN, "w")

#how many cases?
N = int( iFile.readline())
for i in range(N) :
    if verbose:
        print i
    #parameters
    S = iFile.readline()
    S = S.split()
    P = int(S[0])
    K = int(S[1])
    L = int(S[2])
    if verbose:
        print P, K, L
    S = iFile.readline()
    if P * K < L :
        totalCnt = -1
    else:
      S = S.split()
      #konwersja na long
      for j in range(len(S)):
          S[j] = long(S[j])
      if verbose:
          print S
      S.sort(reverse = True)
      if verbose:
          print S
      currCost = 1
      totalCnt = 0
      keysLeft = K
      for s in S:
          if keysLeft == 0 :
              currCost = currCost + 1
              keysLeft = K
          totalCnt = totalCnt + s * currCost
          keysLeft = keysLeft - 1
    if totalCnt == -1 :
      print >> outF , "Case #%(c)d: Impossible" % {'c' : i + 1}
    else:
      print >> outF , "Case #%(c)d: %(cnt)d" % {'c' : i + 1, 'cnt' : totalCnt}
iFile.close()
outF.close()
