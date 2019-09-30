#!/usr/bin/python

mod = 100003

nx =  500 
C = [[1]  ]
for n in range(1, nx + 1):
    C.append( [] )
    C[n].append( 1 )
    for k in range(1, n):
        C[n].append( (C[n-1][k-1] + C[n-1][k]) % mod  )
    C[n].append( 1 )

Tot = [ 0 ]
T = [ [0] ]
for n in range(1, nx + 1):
    T.append( [] )
    T[n].append( 0 )
    T[n].append( 1 )

    for k in range(2, n):
        T[n].append( sum( T[k][l]*C[n-1-k][k-1-l] for l in range(1, k) if k - 1 - l <= n - 1 - k) % mod)

    Tot.append( sum( T[n][k] for k in range(1, n) ) % mod )
    #print n,'->', Tot[n]

t = input()
for i in range(t):
    n = input()
    print 'Case #' + str(i+1) + ': ' + str(Tot[n])

