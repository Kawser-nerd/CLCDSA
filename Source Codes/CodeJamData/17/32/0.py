#!/usr/bin/env python

fin = open("2.in", "r")
fout = open("2.out", "w")

day = 24 * 60

T = int(fin.readline())
for test in range(T):
    print str(test+1)
    C, J = map(int, fin.readline().split())
    fixed = [0 for i in range(day)]
    for c in range(C):
        start, end = map(int, fin.readline().split())
        for t in range(start, end):
            fixed[t] = 1 # Cameron is busy, must be Jamie
    for j in range(J):
        start, end = map(int, fin.readline().split())
        for t in range(start, end):
            fixed[t] = 2 # Jamie is busy, must be Cameron

    # Compute F[T][C][X] by dynamic programming, which is the minimal number of swaps needed for:
    # Deciding who does each of first T times
    # C <= T of that time goes to Cameron
    # X = 0 if Cameron does the last slot
    # X = 1 if Jamie does the last slot
    F = [[[day + 1, day + 1] for c in range(day/2 + 1)] for t in range(day + 1)]
    F[0][0][0] = 0
    F[0][0][1] = 0
    for t in range(1, day + 1):
        for c in range(day/2 + 1):
            if fixed[t-1] != 1: # Cameron is free for this minute
                F[t][c][0] = min(F[t-1][c-1][1] + 1, F[t-1][c-1][0])
            if fixed[t-1] != 2: # Jamie is free for this minute
                F[t][c][1] = min(F[t-1][c][1], F[t-1][c][0] + 1)

    ans = min(F[day][day/2][0], F[day][day/2][1])
    if ans % 2 == 1:
        ans += 1
    fout.write("Case #" + str(test+1) + ": " + str(ans) + "\n")
