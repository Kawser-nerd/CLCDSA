N = int(input())
st, sx, sy = 0, 0, 0
for _ in range(N):
    t, x, y = map(int, input().split())
    dt = t - st
    dr = abs(x - sx) + abs(y - sy)
    if not (dt >= dr and (dt - dr) % 2 == 0):
        print('No')
        break
else:
    print('Yes')