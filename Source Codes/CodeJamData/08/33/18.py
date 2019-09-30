#!/usr/bin/python
import sys



c = int(sys.stdin.readline())
for cnt in range(1, c + 1):
    n, m, X, Y , Z = map(int, sys.stdin.readline().split())
    A = [0]*m
    for p in range(0, m):
        A[p] = int(sys.stdin.readline())

    speeds = []
    for i in range(0,n):
      #print A[i % m]
      speeds.append(A[i%m])
      A[i % m] = (X * A[i % m] + Y * (i + 1)) % Z
    #print speeds
    totals = [0] *  n 
    res = 0 
    for x in range(n - 1, -1, -1):
        #print "Checking " + `x`
        total = 1
        for y in range(x + 1, n):
            #print ("Comapring " + `speeds[x]` + ">" + `speeds[y]`)
            #print `x` + ", y = " + `y` 
            if speeds[x] < speeds[y]:
                total += totals[y]
        res += total
        totals[x] = total
        #print "Result (" + `x` +") " + `speeds[x]` +  "= " + `total`

    print "Case #%d: %d" %(cnt, res % 1000000007) 




