#!/usr/bin/env python3
N = int(input())
ans = [0] * 6
for i in range(N):
    MT, mT = map(float, input().split())
    
    if MT >= 35:
        ans[0] += 1
    elif MT >= 30:
        ans[1] += 1
    elif MT >= 25:
        ans[2] += 1

    if mT >= 25:
        ans[3] += 1

    if MT < 0:
        ans[5] += 1
    elif mT < 0:
        ans[4] += 1

print(ans[0], end='')
for n in ans[1:]:
    print('', n, end='')
print('')