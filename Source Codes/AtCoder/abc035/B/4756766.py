# -*- coding: utf-8 -*-
S = input()
T = int(input())
x, y, count = 0, 0, 0

for i in range(len(S)):
    if S[i] == 'L':
        x -= 1
    elif S[i] == 'R':
        x += 1
    elif S[i] == 'U':
        y += 1
    elif S[i] == 'D':
        y -= 1
    else:
        count += 1
        
d = abs(x) + abs(y)

if T == 1:
    d += count
    ans = d
else:
    tmp = []
    dtmp = []
    for i in range(count // 2 + 1):
        tmp.append(count - 2 * i)

    for i in range(len(tmp)):
        dtmp.append(abs(d - tmp[i]))
    ans = min(dtmp)
    
print(ans)