N, T = map(int, input().split())

cost = 1001
for i in range(N):
    c, t = map(int, input().split())
    if t > T:
        pass
    else:
        if c < cost:
            cost = c

if cost != 1001:
    print(cost)
else:
    print('TLE')