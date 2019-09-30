N, D = map(int, input().split())
ds = list(map(int, input().split()))
Q = int(input())
querys = list(map(lambda x: int(x) - 1, input().split()))

# ps[i]: i???????????????????
ps = [0] * (N + 1)
ps[0] = D
for i in range(N):
    ps[i + 1] = min(abs(ps[i] - ds[i]), ps[i])

if ps[N] != 0:
    print('\n'.join(['YES'] * Q))
    exit()

# ms[i]: i???????m?????????????????????????m????
ms = [0] * (N + 1)
for i in range(N)[::-1]:
    if ms[i + 1] + 1 >= ds[i] - ms[i + 1]:
        ms[i] = ms[i + 1] + ds[i]
    else:
        ms[i] = ms[i + 1]

for q in querys:
    if ps[q] <= ms[q + 1]: # ??????
        print('NO')
    else:
        print('YES')