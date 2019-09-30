# -*- coding: utf-8 -*-
from sys import stdin

in_strings = lambda: stdin.readline()[:-1] # s = in_strings()
in_int = lambda: int(stdin.readline()) # N = in_int()
in_intlist = lambda: list(map(int, stdin.readline().split())) # List = in_intlist()

N = in_int()
L_list = []
R_list = []
for _ in range(N):
    temp = in_intlist()
    L_list.append(temp[0])
    R_list.append(temp[1])

L_list.sort(reverse=True)
R_list.sort()


ans = 0
for i in range(N):
    if (L_list[i] - R_list[i]) > 0:
        ans += 2*(L_list[i] - R_list[i])
    else:
        if (L_list[i] <= 0) and (R_list[i] >= 0):
            pass
        elif L_list[i] > 0:
            if (i>0) and (L_list[i] < R_list[i-1]):
                ans += 2 * R_list[i-1]
            else:
                ans += 2 * L_list[i]
        else:
            if (i>0) and (R_list[i] > L_list[i-1]):
                ans -= 2 * L_list[i-1]
            else:
                ans -= 2 * R_list[i]
        break

print(ans)