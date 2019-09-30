#!/usr/bin/env python3

def main():
    n = int(input())
    rn = []
    hn = []
    for i in range(n):
        r, h = map(int, input().split())
        rn.append(r)
        hn.append(h)

    hand_count = [[0, 0, 0] for r in range(100000 + 1)]
    for i in range(n):
        r = rn[i]
        h = hn[i]
        hand_count[r][h - 1] += 1


    acc_count = [0 for r in range(100000 + 1)]
    for r in range(1, 100000 + 1):
        acc_count[r] = acc_count[r - 1]
        for h0 in range(3):
            acc_count[r] += hand_count[r][h0]

    for i in range(n):
        r = rn[i]
        h = hn[i]
        n_win = acc_count[r - 1] + hand_count[r][hand_loses(h) - 1]
        n_even = hand_count[r][h - 1] - 1
        n_lose = n - acc_count[r] + hand_count[r][hand_wins(h) - 1]
        print(n_win, n_lose, n_even)

def hand_loses(h1):
    di = {1:2, 2:3, 3:1}
    return di[h1]

def hand_wins(h1):
    di = {1:3, 2:1, 3:2}
    return di[h1]

main()