# -*- coding: utf-8 -*-
from collections import defaultdict
def inpl(): return map(int, input().split())

N, K = inpl()
S = input()

vec = [0]*26
D = defaultdict(list)

for i in range(K):
    vec[ord(S[i])-97] += 1

D[tuple(vec)].append(0)

for i in range(N-K):
    vec[ord(S[i])-97] -= 1
    vec[ord(S[i+K])-97] += 1
    D[tuple(vec)].append(i+1)

for k, v in D.items():
    if v[-1] - v[0] >= K:
        print("YES")
        break
else:
    print("NO")