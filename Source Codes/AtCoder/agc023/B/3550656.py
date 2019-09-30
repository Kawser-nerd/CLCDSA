# -*- coding: utf-8 -*-
from sys import stdin
import numpy as np

s_in = lambda: stdin.readline()[:-1]  # s = s_in()
d_in = lambda: int(stdin.readline())  # N = d_in()
ds_in = lambda: list(map(int, stdin.readline().split()))  # List = ds_in()


N = d_in()
S_LIST = []
for _ in range(N):
    s = list(s_in())
    S_LIST.append(list(map(ord, s)))
S_LIST = np.array(S_LIST, dtype=int)

ans = 0
for i in range(N):
    check_array = np.concatenate((S_LIST[:, i:], S_LIST[:, :i]), axis=1)
    if np.array_equal(check_array, check_array.T):
        ans += 1
print(ans*N)