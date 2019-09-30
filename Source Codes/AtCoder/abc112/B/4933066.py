n, t_limit = map(int, input().split())
cts = [list(map(int, input().split())) for _ in range(n)]
min_c = 10000
for c, t in cts:
    if t <= t_limit and c < min_c:
        min_c = c
if min_c == 10000:
    print('TLE')
else:
    print(min_c)