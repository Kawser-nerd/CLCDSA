#!/usr/bin/env python3

def main():
    n = int(input())
    hn = [int(input()) for i in range(n)]

    end_loc = []
    for i in range(n):
        if i in [0, n - 1]:
            end_loc.append(i)
        elif hn[i - 1] > hn[i] < hn[i + 1]:
            end_loc.append(i)
    ma = 1
    for i in range(len(end_loc)):
        if i == 0:
            continue
        ma = max(ma, end_loc[i] - end_loc[i - 1] + 1)
    print(ma)

main()