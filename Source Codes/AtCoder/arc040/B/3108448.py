# -*- coding: utf-8 -*-
def inpl(): return list(map(int, input().split()))
N, R = inpl()
S = [s=="o" for s in input()]
ans = 0
for i in range(N):
    if all(S[i:]):
        break
    if S[i]:
        ans += 1
        if all(S[i+R:]):
            break
    else:
        S[i:i+R] = [True]*R
        ans += 1
        if all(S[i+R:]):
            break
        ans += 1
print(ans)