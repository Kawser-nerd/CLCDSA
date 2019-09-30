import math
for case in range(input()):
    n, m, X, Y, Z = map(int, raw_input().split(' '))
    A = []
    for i in range(m):
        A.append(int(raw_input()))
    L = []
    for i in range(n):
        L.append(int(A[i % m]))
        A[i % m] = (X * A[i % m] + Y * (i + 1)) % Z
    count = 0
    S = [1] * n
    for i in range(n):
        for j in range(i):
            if L[j] < L[i]:
                S[i] += S[j]
        count += S[i]        
    count = count % 1000000007
    print 'Case #%s: %d' % (case + 1, count)
