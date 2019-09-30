import math

input = open('date.in', 'r')
output = open('date.out', 'w')

T = int(input.readline())
for t in range(T):
    print t
    N = int(input.readline())
    S = []
    for i in range(N):
        S.append(input.readline().strip())

    F = []
    for i in range(N):
        C = []
        L = len(S[i])
        cnt = 0
        for j in range(L):
            if j > 0 and S[i][j] != S[i][j - 1]:
                C.append( (S[i][j - 1], cnt) )
                cnt = 1
            else:
                cnt = cnt + 1
        C.append((S[i][L - 1], cnt))
        F.append(C)

    output.write('Case #{}: '.format(t + 1))

    ok = True
    for i in range(1, N):
        if len(F[i]) != len(F[i - 1]):
            ok = False
            break

    if not ok:
        output.write('Fegla Won\n')
        continue

    M = len(F[0])
    ans = 0
    same = True
    for j in range(M):
        for i in range(1, N):
            if F[i][j][0] != F[i - 1][j][0]:
                same = False
                break
        if not same:
            break

        f = []
        for i in range(N):
            f.append(F[i][j][1])
        f.sort()

        vmin = 100000000
        L = [ 0 for i in range(N) ]
        R = [ 0 for i in range(N) ]
        L[0] = f[0]
        for i in range(1, N):
            L[i] = L[i - 1] + f[i]
        R[N - 1] = f[N - 1]
        for i in range(N - 2, -1, -1):
            R[i] = R[i + 1] + f[i]

        for i in range(N):
            crt = 0
            if i > 0:
                crt += f[i] * i - L[i - 1]
            if i + 1 < N:
                crt += R[i + 1] - f[i] * (N - 1 - i)
            vmin = min(vmin, crt)

        ans += vmin

    if not same:
        output.write('Fegla Won\n')
        continue

    output.write('{}\n'.format(ans))

input.close()
output.close()