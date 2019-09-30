#!/usr/bin/env python3

T = int(input())
for case in range(1, T+1):
    N = int(input())
    perm = [int(i) for i in input().split()]
    guess = 'GOOD' if (sum((perm[i] + N - i - 1) % 1000 for i in range(N)) > 485000) else 'BAD'
    print("Case #{}: {}".format(case, guess))

