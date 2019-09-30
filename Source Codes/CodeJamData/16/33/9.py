#! /usr/bin/env python3

# codejam style

T = int(input())

for TT in range(1, T+1):
    J, P, S, K = (int(x) for x in input().split())

    m = min(S, K)
    ans = J * P * m

    print('Case #{}: {}'.format(TT, ans))
    for j in range(J):
        for p in range(P):
            for s in range(m):
                t = (j + p + s) % S
                print(j + 1, p + 1, t + 1)
