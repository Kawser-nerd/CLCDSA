def compute(R, Q):
    N, P = len(R), len(Q[0])
    for q in Q:
        q.sort()

    # m[i][j] and M[i][j] are the miniml and maximal number of
    # servings that Q[i][j] can be used for
    m = [[] for i in range(N)]
    M = [[] for i in range(N)]
    for i in range(N):
        for j in range(P):
            m[i].append( (10*Q[i][j] + 11*R[i] - 1) // (11*R[i]) )
            M[i].append( (10*Q[i][j]) // (9*R[i]) )


    I = [0 for i in range(N)]
    count = 0
    while P not in I:
        least = max( m[k][I[k]] for k in range(N) )
        most = min( M[k][I[k]] for k in range(N) )
        if least <= most:
            count += 1
            #print([ Q[k][I[k]] for k in range(N)], least, most)
            for k in range(N):
                I[k] += 1
        else:        
            for k in range(N):
                while I[k] < P and M[k][I[k]] < least:
                    I[k] += 1

    return count
            
                                    
T = int(input())
for t in range(1,T+1):
    N, P = [int(x) for x in input().split()]
    R = [int(x) for x in input().split()]
    Q = [[int(x) for x in input().split()] for i in range(N)]

    count = compute(R, Q)
    print("Case #%d:"%t, count)

