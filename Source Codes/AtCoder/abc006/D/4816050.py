from bisect import bisect_left
N = int(input())
C = [int(input()) for _ in range(N)]
S = [0]
for c in C:
    i = bisect_left(S, c)
    if len(S) == i:
        S += [c]
    else:
        S[i] = c
print(N - len(S) + 1)