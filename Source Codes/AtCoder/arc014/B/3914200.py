#!/usr/bin/env python3
N = int(input())
W = [input() for _ in range(N)]
dic = {W[0]: True}
for i in range(len(W))[1:]:
    if W[i][0] != W[i - 1][-1] or W[i] in dic:
        print('WIN' if i % 2 == 1 else 'LOSE')
        break
    dic[W[i]] = True
else:
    print('DRAW')