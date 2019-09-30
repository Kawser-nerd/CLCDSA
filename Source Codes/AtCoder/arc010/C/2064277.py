n, m, Y, Z = map(int, input().split())
D = {}
C = []; P = []
for i in range(m):
    c, p = input().split()
    C.append(c)
    P.append(int(p))
*B, = map(C.index, input())
ALL = 2**m-1

S = {(0, None): 0}
INF = 10**8
for i in range(n):
    T = {}
    for state, col in S:
        score = S[state, col]
        if (state, col) in T:
            T[state, col] = max(T[state, col], score)
        else:
            T[state, col] = score
        if col == B[i]:
            if (state, col) in T:
                T[state, col] = max(T[state, col], score + Y + P[col])
            else:
                T[state, col] = score + Y + P[col]
        else:
            n_state = state | (1 << B[i])
            if (n_state, B[i]) in T:
                T[n_state, B[i]] = max(T[n_state, B[i]], score + P[B[i]])
            else:
                T[n_state, B[i]] = score + P[B[i]]
    S = T
print(max(S[key] + Z*(key[0] == ALL) for key in S))