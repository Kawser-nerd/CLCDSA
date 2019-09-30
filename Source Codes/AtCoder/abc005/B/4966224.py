# -*- coding: utf-8 -*-
import numpy as np

N = int(input())
e = [[int(i) for i in input().split()] for i in range(N)]

e = np.array([i[0] for i in e])

print(e[e.argmin()])