#!/usr/bin/env python3
N, R = map(int, input().split())
S = list(input())
ans = -1
for i in range(N):
    ans += 1
    if S.count('o') + len([x for x in S[i:i+R] if x == '.']) == N:
        ans += (S.count('o') != N)
        break
    if S[i] != '.':
        continue
    ans += 1
    for j in range(R):
        S[i + j] = 'o'
print(ans)