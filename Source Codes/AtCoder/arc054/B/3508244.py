# -*- coding: utf-8

import math
p = float(input())
x = max(-3/2 * math.log2(3 / (2 * p * math.log(2, math.e))), 0)
print(x + p * 2**(-x / 1.5))