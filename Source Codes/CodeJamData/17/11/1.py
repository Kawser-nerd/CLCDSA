T = int( input() )
for t in range(1,T+1):
    R, C = [ int(_) for _ in input().split() ]
    A = [ list(input()) for r in range(R) ]
    for c in range(1,C):
        if all( '?' == A[r][c] for r in range(R) ):
            for r in range(R):
                A[r][c] = A[r][c-1]
    for c in range(C-2,-1,-1):
        if all( '?' == A[r][c] for r in range(R) ):
            for r in range(R):
                A[r][c] = A[r][c+1]
    for r in range(1,R):
        for c in range(C):
            if '?' == A[r][c]:
                A[r][c] = A[r-1][c]
    for r in range(R-2,-1,-1):
        for c in range(C):
            if '?' == A[r][c]:
                A[r][c] = A[r+1][c]
    print('Case #{}:'.format(t))
    for r in range(R): print(''.join(A[r]))
