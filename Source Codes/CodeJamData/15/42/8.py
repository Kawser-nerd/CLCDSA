#!/usr/bin/env python3

# Google Code Jam Round 2 2015
# Problem B. Kiddie Pool
# Solution in Python
# By Smithers

for x in range(1, int(input()) + 1):
    N, V, X = input().split()
    N = int(N)
    V = float(V)
    X = float(X)
    
    sources = [tuple(map(float, input().split())) for i in range(N)]
    R = [x[0] for x in sources]
    C = [x[1] for x in sources]
    
    if N == 1:
        if X != C[0]:
            y = 'IMPOSSIBLE'
        else:
            y = V / R[0]
    elif N == 2:
        if C[0] > C[1]:
            R[0], R[1] = R[1], R[0]
            C[0], C[1] = C[1], C[0]
        
        if C[0] <= X <= C[1]:
            if C[0] == C[1]:
                y = V / (R[0] + R[1])
            elif C[0] == X:
                y = V / R[0]
            elif C[1] == X:
                y = V / R[1]
            else:
                a0 = V * (C[1]-X) / (C[1]-C[0])
                a1 = V * (X-C[0]) / (C[1]-C[0])
                y = max(a0 / R[0], a1 / R[1])
        else:
            y = 'IMPOSSIBLE'
    else:
        y = '?'
    
    print('Case #' + str(x) + ':', y)
