N, T = map(int, input().split())
clist = []
for _ in range(N):
    c, t = map(int, input().split())
    if t <= T:
        clist.append(c)

if len(clist) == 0:
    print('TLE')
else:
    print(min(clist))