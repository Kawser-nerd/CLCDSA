import bisect

a, b, q = map(int, input().split())
INF = 3*10**10
S = [int(input()) for _ in range(a)]

S = [-INF] + S[:] + [INF]
T = [int(input()) for _ in range(b)]
T = [-INF] + T[:] + [INF]

for _ in range(q):
    x = int(input())
    i = bisect.bisect_left(S, x) 
    j = bisect.bisect_left(T, x) 
    A = [max(S[i]-x, T[j]-x), max(x-S[i-1], x-T[j-1]), S[i]-T[j-1]+min(S[i]-x, x-T[j-1]), T[j]-S[i-1]+min(x-S[i-1], T[j]-x)]
    print(min(A))