import sys
import array

iFName = "d:\\projekty\\google-jam\\runda-1-b\\c\\C-small-attempt0.in"
outFN = "d:\\projekty\\google-jam\\runda-1-b\\c\\out-small0.txt"

iFile = open(iFName, "r")
outF =  open(outFN, "w")

verbose = False

#how many cases?
N = int( iFile.readline())
for case in range(N) :
    if verbose:
        print case
    S = iFile.readline()
    S = S.split()
    if verbose:
        print S
    n = int(S[0])
    m = int(S[1])
    X = int(S[2])
    Y = int(S[3])
    Z = int(S[4])
    if verbose :
        print n, m, X, Y, Z
    A = array.array('i')
    for j in range(m):
        A.append(int(iFile.readline()))
    if verbose:
        print A
    #generowanie spedL
    SL = array.array('i')
    for i in range (n):
        SL.append (A[i % m])
        A[i % m] = (X * A[i % m] + Y * (i + 1)) % Z
    if verbose:
        print "SL", SL
    CNT = array.array('i', SL)
    for i in range(n):
        CNT[i]= 1
    start = n - 2
    while start >= 0:
        next = start + 1
        while next < n:
            if SL[next] > SL[start]:
              CNT[start] = CNT [start] + CNT[next]
              if CNT[start] > 1000000007 :
                 CNT[start] = CNT[start] % 1000000007
            next = next + 1
        start = start - 1
    hm = 0
    for c in CNT:
        hm = (hm + c ) % 1000000007
    print >> outF , "Case #%(c)d: %(cnt)d" % {'c' : case + 1, 'cnt' : hm}
iFile.close()
outF.close()
