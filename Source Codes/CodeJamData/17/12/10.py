import math

for tc in range(int(input())):
    N, P = map(int, input().split())
    R = list(map(int, input().split()))
    Q = []
    for i in range(N):
        for t in map(int, input().split()):
            t /= R[i]
            s = max(1, math.ceil(t / 1.1))
            r = math.floor(t / 0.9)
            if r < s:
                continue
            Q.append((s, -1, i))
            Q.append((r, 1, i))
    Q.sort()
    C = [0] * N
    U = [0] * N
    r = 0
    for i, j, k in Q:
        #print(i, j, k)
        if j == -1:
            C[k] += 1
            if all(C):
                for l in range(N):
                    C[l] -= 1
                    U[l] += 1
                r += 1
        else:
            if U[k] != 0:
                U[k] -= 1
            else:
                C[k] -= 1
        #print(C, U)
    print("Case #{}: {}".format(tc + 1, r))
