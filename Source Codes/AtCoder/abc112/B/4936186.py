n, t = map(int, input().split())
ct = [list(map(int, input().split())) for i in range(n)]
under_t = []
for i in range(n):
    if ct[i][1] <= t:
        under_t.append(ct[i][0])
if len(under_t) == 0:
    print('TLE')
else:
    print(min(under_t))