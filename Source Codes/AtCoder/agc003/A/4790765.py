# -*- coding: utf-8 -*-

s = set(input())
ans = 0
for i in s:
    if 'N' in i:
        ans += 1
    elif 'W' in i:
        ans += -2
    elif 'S' in i:
        ans += -1
    else:
        ans += 2
print('Yes' if ans == 0 else 'No')