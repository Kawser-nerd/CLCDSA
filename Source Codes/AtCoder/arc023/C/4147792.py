# -*- coding: utf-8 -*-
def  inpl(): return list(map(int, input().split()))

MOD = 10**9 + 7
def make_inv(N, MOD=10**9 + 7):
    inv = [0]*(N+1)
    inv[1] = 1
    for i in range(2, N+1):
        inv[i] = inv[MOD%i] * (MOD - MOD // i)%MOD
    return inv

inv = make_inv(2000)

N = int(input())
A = inpl()
mins = []
maxs = []
streaks = []

min_ = 0
max_ = 1e9 + 1
streak = 0
for i in range(N):
    if A[i] != -1:
        min_ = max(min_, A[i])
    mins.append(min_)

for i in range(N-1, -1, -1):
    if A[i] != -1:
        max_ = min(max_, A[i])
    maxs.append(max_)
maxs = maxs[::-1]

for i in range(N):
    streak = (streak + (A[i] == -1))*(A[i] == -1)
    streaks.append(streak)

ans = 1
S = 1
for i in range(N):
    if A[i] != -1:
        ans = (ans*S)%MOD
        S = 1
    else:
        d = maxs[i] - mins[i] + 1
        S = (S * (d-1+streaks[i]) * inv[streaks[i]])%MOD
print(ans)