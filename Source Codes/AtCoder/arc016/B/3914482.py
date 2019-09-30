#!/usr/bin/env python3
import numpy as np
import re
N = int(input())
x = np.array([list(input()) for _ in range(N)])
cnt = [list(v).count('x') for v in x]
seq = [re.sub('o+', 'o', ''.join(x[:, i])).count('o') for i in range(9)]
print(sum(cnt) + sum(seq))