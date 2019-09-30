# -*- coding: utf-8 -*-
N = int(input())
a, b = map(int, input().split())
K = int(input())
P = list(map(int, input().split()))

i = 0
while i < K:
    if P[i] == a or P[i] == b:
        print('NO')
        break
    else:
        i += 1
        if i == K:
            if len(list(set(P))) == K:
                print('YES')
            else:
                print('NO')