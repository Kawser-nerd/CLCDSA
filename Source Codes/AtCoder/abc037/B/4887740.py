N, Q = map(int, input().split())
suretsu = []
for i in range(N):
    suretsu.append(0)
for j in range(Q):
    L, R, T = map(int, input().split())
    T_li = [T for i in range(R - L + 1)]
    del suretsu[L - 1:R]
    suretsu[L-1:L-1] = T_li
for k in suretsu:
    print(k)