#!/usr/bin/env python

fin = open("2.in", "r")
fout = open("2.out", "w")

T = int(fin.readline())
for t in range(T):
    print str(t+1)
    N, C, M = map(int, fin.readline().split())
    P = []
    for i in range(M):
        p, b = map(int, fin.readline().split())
        P.append((p, b))

    # The answer is the max over all i of the answer using only pos <= i
    pos = [0 for i in range(N+1)]
    for (p, b) in P:
        pos[p] += 1
    ans_y = 0
    cur = 0
    for i in range(1, N+1):
        cur += pos[i]
        ans_y = max(ans_y, (cur + i - 1) / i)
    buy = [0 for i in range(C + 1)]
    for (p, b) in P:
        buy[b] += 1
    ans_y = max(ans_y, max(buy))
    ans_z = 0
    for i in range(1, N+1):
        ans_z += max(0, pos[i] - ans_y)

    ans = str(ans_y) + " " + str(ans_z)
    fout.write("Case #" + str(t+1) + ": " + str(ans) + "\n")
