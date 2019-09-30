#!/usr/bin/env python

fin = open("1.in", "r")
fout = open("1.out", "w")

T = int(fin.readline())
for u in range(T):
    print str(u+1)
    N, P = map(int, fin.readline().split())
    H = map(lambda x: x % P, map(int, fin.readline().split()))
    G = [0 for i in range(P)]
    for h in H:
        G[h] += 1
    ans = 0
    if sum(H) % P != 0:
        ans += 1
    ans += G[0]
    if P == 2:
        ans += G[1] / 2
    elif P == 3:
        ans += min(G[1], G[2])
        ans += (max(G[1], G[2]) - min(G[1], G[2])) / 3
    elif P == 4:
        ans += G[2] / 2
        G[2] %= 2
        t = min(G[1], G[3])
        G[1] -= t
        G[3] -= t
        ans += t
        if G[3] > 0:
            G[1] = G[3]
            G[3] = 0
        if G[2] == 1 and G[1] >= 2:
            ans += 1
            G[2] = 0
            G[1] -= 2
        ans += G[1] / 4

    fout.write("Case #" + str(u+1) + ": " + str(ans) + "\n")
