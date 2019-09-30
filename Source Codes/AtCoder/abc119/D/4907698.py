import bisect

A, B, Q = map(int, input().split())

INF = 10**11

s = [-INF] + [int(input()) for _ in range(A)] + [INF]
t = [-INF] + [int(input()) for _ in range(B)] + [INF]



for i in range(Q):
    _min = INF
    
    x = int(input())
    b, d = bisect.bisect_left(s, x), bisect.bisect_left(t, x)
    for S in [s[b-1], s[b]]:
        for T in [t[d-1], t[d]]:
            _min =  min(abs(S - x) + abs(T - S), abs(T - x) + abs(S - T), _min)

    print(_min)